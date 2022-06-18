//// 1) 0, 1

​

#include<stdio.h>

#include<wiringPi.h> //gpio readall->wiringPi 라이브러리 사용

​

//GPIO 핀 번호 정의

#define sw0 0 //Physical 11(GPIO 0)

#define sw1 1 //Physical 12(GPIO 1)

#define sw2 2 //Physical 13(GPIO 2)

#define sw3 3 //Physical 15(GPIO 3)

​

#define led0 22 //Physical 31(GPIO 22)

#define led1 23 //Physical 33(GPIO 23)

#define led2 24 //Physical 35(GPIO 24)

#define led3 25 //Physical 37(GPIO 25)

#define led4 26 //Physical 32(GPIO 26)

#define led5 27 //Physical 36(GPIO 27)

#define led6 28 //Physical 38(GPIO 28)

#define led7 29 //Physical 40(GPIO 29)

​

unsigned char sw[] = { sw0, sw1, sw2, sw3 };

unsigned char led[] = { led0,led1,led2,led3,led4,led5,led6,led7 };

unsigned char even_led_on[] = { led0, led2, led4, led6 };

unsigned char odd_led_on[] = { led1, led3, led5, led7 };

​

//led와 sw 풀업저항

void pin_setting() { //어디에 사용될지 설정

	int i = 0;

	//sw 핀을 INPUT으로 설정(풀업저항-스위치가 열려있으면 1, 스위치가 닫혀있으면 0)

	for (i = 0; i < 4; i++)

		pinMode(sw[i], INPUT);

	//led 핀을 OUTPUT으로 설정(풀업저항-led on 0, led off 1)

	for (i = 0; i < 8; i++)

		pinMode(led[i], OUTPUT);

}

​

int main(void) {

	int i = 0;

	​

		//GPIO 기능을 사용할 수 있는지 검사해주는 함수

		if (wiringPiSetup() == -1)

			return 1; //예를들어 반환값이 -1이면 사용할 수 없음

	​

		pin_setting();

	​

		while (1) {

			//눌렀다가 떼면 led on

			if (digitalRead(sw0) == 0) { //sw0을 눌리면

				while (digitalRead(sw0) == 0);

				for (i = 0; i < 8; i++)

					digitalWrite(led[i], 0); //led on

				​

			}

			//led 오른쪽 shift

			else if (digitalRead(sw1) == 0) { //sw을 눌리면

				for (i = 0; i < 8; i++) {

					digitalWrite(led[i], 0); //led on

					delay(300);

					digitalWrite(led[i], 1); //led off

				}

			}

			//led 왼쪽 shift

			else if (digitalRead(sw2) == 0) { //sw2을 눌리면

				for (i = 8; i > 0; i--) {

					digitalWrite(led[i], 0); //led on

					delay(300);

					digitalWrite(led[i], 1); //led off

				}

			}

			//누르는 동안에 led on

			else if (digitalRead(sw3) == 0) { //sw3을 눌리면

				for (i = 0; i < 8; i++)

					digitalWrite(led[i], 0); //led on

				while (digitalRead(sw3) == 0);

			}

		}

	return 0;

}

​

//// 2) LOW, HIGH

​

#include<stdio.h>

#include<wiringPi.h> //gpio readall->wiringPi 라이브러리 사용

​

//GPIO 핀 번호 정의

#define sw0 0 //Physical 11(GPIO 0)

#define sw1 1 //Physical 12(GPIO 1)

#define sw2 2 //Physical 13(GPIO 2)

#define sw3 3 //Physical 15(GPIO 3)

​

#define led0 22 //Physical 31(GPIO 22)

#define led1 23 //Physical 33(GPIO 23)

#define led2 24 //Physical 35(GPIO 24)

#define led3 25 //Physical 37(GPIO 25)

#define led4 26 //Physical 32(GPIO 26)

#define led5 27 //Physical 36(GPIO 27)

#define led6 28 //Physical 38(GPIO 28)

#define led7 29 //Physical 40(GPIO 29)

​

unsigned char sw[] = { sw0, sw1, sw2, sw3 };

unsigned char led[] = { led0,led1,led2,led3,led4,led5,led6,led7 };

unsigned char even_led_on[] = { led0, led2, led4, led6 };

unsigned char odd_led_on[] = { led1, led3, led5, led7 };

​

//led와 sw 풀업저항

void pin_setting() { //어디에 사용될지 설정

	int i = 0;

	//sw 핀을 INPUT으로 설정(풀업저항-스위치가 열려있으면 1, 스위치가 닫혀있으면 0)

	for (i = 0; i < 4; i++)

		pinMode(sw[i], INPUT);

	//led 핀을 OUTPUT으로 설정(풀업저항-led on 0, led off 1)

	for (i = 0; i < 8; i++)

		pinMode(led[i], OUTPUT);

}

​

int main(void) {

	int i = 0;

	​

		//GPIO 기능을 사용할 수 있는지 검사해주는 함수

		if (wiringPiSetup() == -1)

			return 1; //예를들어 반환값이 -1이면 사용할 수 없음

	​

		pin_setting();

	​

		while (1) {

			//눌렀다가 떼면 led on

			if (digitalRead(sw0) == LOW) { //sw0을 눌리면

				while (digitalRead(sw0) == LOW);

				for (i = 0; i < 8; i++)

					digitalWrite(led[i], 0); //led on

				​

			}

			//led 오른쪽 shift

			else if (digitalRead(sw1) == LOW) { //sw을 눌리면

				for (i = 0; i < 8; i++) {

					digitalWrite(led[i], LOW); //led on

					delay(300);

					digitalWrite(led[i], HIGH); //led off

				}

			}

			//led 왼쪽 shift

			else if (digitalRead(sw2) == LOW) { //sw2을 눌리면

				for (i = 8; i > 0; i--) {

					digitalWrite(led[i], LOW); //led on

					delay(300);

					digitalWrite(led[i], HIGH); //led off

				}

			}

			//누르는 동안에 led on

			else if (digitalRead(sw3) == LOW) { //sw3을 눌리면

				for (i = 0; i < 8; i++)

					digitalWrite(led[i], LOW); //led on

				while (digitalRead(sw3) == LOW);

			}

		}

	return 0;

}
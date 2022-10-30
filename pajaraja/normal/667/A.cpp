#include <iostream>
#include <stdio.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	float a,b,c,d,v1,z;
	scanf("%f%f%f%f",&a,&b,&c,&d);
	v1=d*3.141592*a*a/4;
	z=a*a*3.141592*b/4;
	if(c<=v1)
	{
		printf("NO");
	}
	else
	{
		float t;
		t=z/(c-v1);
		printf("YES\n");
		printf("%f",t);
	}
	return 0;
}
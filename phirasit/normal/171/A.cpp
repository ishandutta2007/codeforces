#include <stdio.h>

int a,b,c;

int main() {
	scanf("%d%d",&a,&b);
	c = 0;
	while(b) {
		c = 10*c + b%10;
		b /= 10;
	}
	printf("%d\n",a+c);
	return 0;
}
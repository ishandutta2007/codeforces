#include <stdio.h>

int gcd(int a,int b) {
	if(a%b == 0) return b;
	return gcd(b,a%b);
}
int main() {
	int a,b;
	scanf("%d %d",&a,&b);
	if(b > a) a = b;
	int g = gcd(6-a+1,6);
	printf("%d/%d\n",(6-a+1)/g,6/g);
	return 0;
}
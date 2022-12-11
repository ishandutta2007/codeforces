#include <stdio.h>

int a,b,x,y;

int gcd(int p,int q) {
	if(p%q == 0) return q;
	return gcd(q,p%q);
}
int main() {
	scanf("%d %d %d %d",&a,&b,&x,&y);
	int l = a*b/gcd(a,b);
	printf("%d\n",y/l - (x-1)/l);
	return 0;
}
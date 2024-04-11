#include <cstdio>

double max(double a,double b) { return a>b?a:b; }

int main(){
	int a,b,c,d;
	scanf("%d%d%d%d",&a,&b,&c,&d);
	int m=max(75*a,250*a-a*c);
	int v=max(75*b,250*b-b*d);
	puts(m>v?"Misha":m<v?"Vasya":"Tie");
	return 0;
}
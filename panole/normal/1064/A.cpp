#include<cstdio>
#include<cstring>

int a,b,c;

int main()
{
	scanf("%d%d%d",&a,&b,&c);
	if (c<b) {int t=b; b=c; c=t;}
	if (c<a) {int t=a; a=c; c=t;}
	if (a+b>c) printf("0\n"); else printf("%d\n",c+1-a-b);
	return 0;
}
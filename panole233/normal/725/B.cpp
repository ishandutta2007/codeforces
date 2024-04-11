#include<cstdio>
#include<cstring>

long long n,ans;
char ch;

int main()
{
	n=0; ch=getchar();
	while (ch>='0'&&ch<='9') n=n*10+ch-48,ch=getchar();
	if (n%4==1||n%4==2) ans=(n/4)*2*7+(n/4)*2+(n%4-1)*7;
	else {ans=((n-1)/4)*2*7+((n-1)/4)*2; if (n%4==0) ans+=7;}
	if (ch=='f') ans++; else
	if (ch=='e') ans+=2; else
	if (ch=='d') ans+=3; else
	if (ch=='a') ans+=4; else
	if (ch=='b') ans+=5; else
	ans+=6;
	printf("%I64d",ans);
	return 0;
}
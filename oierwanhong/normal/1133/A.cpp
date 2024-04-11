#include<iostream>
#include<cstdio>
typedef long long ll;
#define INF (1ll<<58)
ll read()
{
	char c;
	ll f=1,x=0;
	do
	{
		c=getchar();
		if(c=='-')f=-1;
	}while(c<'0'||c>'9');
	do
	{
		x=x*10+c-'0';
		c=getchar();
	}while(c>='0'&&c<='9');
	return f*x;
}
void write(ll x)
{
	if(x==0)
	{
		putchar('0');
		putchar(' ');
		return;
	}
	if(x<0)
	{
		putchar('-');
		x=-x;
	}
	ll s[21],top=0;
	while(x)
	{
		s[++top]=x%10;
		x/=10;
	}
	for(ll i=top;i>=1;--i)putchar(s[i]+'0');
	putchar(' ');
}

int main()
{
	ll a1=read(),b1=read(),a2=read(),b2=read(),ta,tb;
	ta=(a1+a2)/2;
	tb=(b1+b2)/2+(a2-a1)%2*30;
	if(tb>=60)ta+=tb/60,tb%=60;
	ta%=24;
	if(ta<10)std::cout<<0;
	std::cout<<ta<<":";
	if(tb<10)std::cout<<0;
	std::cout<<tb;
	return 0;
}
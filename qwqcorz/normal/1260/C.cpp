#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll read()
{
	ll s=0;
	char c=getchar(),lc='+';
	while (c<'0'||'9'<c) lc=c,c=getchar();
	while ('0'<=c&&c<='9') s=s*10+c-'0',c=getchar();
	return lc=='-'?-s:s;
}
void write(ll x)
{
	if (x<0)
	{
		putchar('-');
		x=-x;
	}
	if (x<10) putchar(x+'0');
	else
	{
		write(x/10);
		putchar(x%10+'0');
	}
}
void print(ll x,char c='\n')
{
	write(x);
	putchar(c);
}
ll gcd(ll x,ll y)
{
	return y==0?x:gcd(y,x%y);
}

int main()
{
	ll T=read();
	while (T--)
	{
		ll a=read(),b=read(),k=read(),g=gcd(a,b);
		if (a>b) swap(a,b);
		a/=g;
		b/=g;
		puts((b-1)/a+((b-1)%a?1:0)>=k?"REBEL":"OBEY");
	}

	return 0;
}
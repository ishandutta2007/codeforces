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

int main()
{
	ll T=read();
	while (T--)
	{
		ll n=read(),a=read(),b=read();
		ll m=n/2+n%2;
		if (m%a==0) print(max((m/a-1)*(a+b)+a,n));
			   else print(max(m/a*(a+b)+m%a,n));
	}

	return 0;
}
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
ll Max(ll x)
{
	ll ret=0;
	while (x)
	{
		ret=max(ret,x%10);
		x/=10;
	}
	return ret;
}
ll Min(ll x)
{
	ll ret=10;
	while (x)
	{
		ret=min(ret,x%10);
		x/=10;
	}
	return ret;
}

int main()
{
	ll T=read();
	while (T--)
	{
		ll now=read(),k=read();
		while (--k)
		{
			ll mn=Min(now),mx=Max(now);
			if (mn==0) break;
			now+=mn*mx;
		}
		print(now);
	}

	return 0;
}
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
	ll n=read(),ans1=0,ans2=0;
	for (ll i=1;i<=n;i++)
	{
		ll a=read();
		if (i&1)
		{
			ans1+=a/2;
			ans2+=(a+1)/2;
		}
		else
		{
			ans1+=(a+1)/2;
			ans2+=a/2;
		}
	}
	print(min(ans1,ans2));

	return 0;
}
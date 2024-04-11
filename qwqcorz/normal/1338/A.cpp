#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=1e5+5;

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
ll a[N];

int main()
{
	ll T=read();
	while (T--)
	{
		ll n=read(),Max=-1e9,ans=0;
		for (ll i=1;i<=n;i++) a[i]=read();
		for (ll i=1;i<=n;i++)
		{
			Max=max(Max,a[i]);
			ans=max(ans,Max-a[i]);
		}
		for (ll i=0;1;i++)
		if ((1ll<<i)>ans)
		{
			print(i);
			break;
		}
	}

	return 0;
}
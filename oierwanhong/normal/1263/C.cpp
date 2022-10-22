#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<map>
typedef unsigned long long ll;
typedef std::pair<ll,ll> pll;
typedef std::string str;
#define INF (1ll<<58)
ll read()
{
	ll x=0,f=1;
	char c;
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
ll min(ll a,ll b)
{
	return a<b?a:b;
}
ll max(ll a,ll b)
{
	return a>b?a:b;
}
bool umin(ll &a,ll b)
{
	if(b<a)return a=b,1;
	return 0;
}
bool umax(ll &a,ll b)
{
	if(b>a)return a=b,1;
	return 0;
}
/**********/
#define MAXN 500011
ll a[MAXN];
int main()
{
	ll t=read();
	while(t--)
	{
		ll n=read(),cnt=0;
		a[++cnt]=0;
		for(ll i=1;i*i<=n;++i)
		{
			a[++cnt]=i;
			if(i*i==n)continue;
			a[++cnt]=n/i;
		}
		std::sort(a+1,a+cnt+1);
		cnt=std::unique(a+1,a+cnt+1)-a-1;
		printf("%lld\n",cnt);
		for(ll i=1;i<=cnt;++i)printf("%lld ",a[i]);
		putchar('\n');
	}
	return 0;
}
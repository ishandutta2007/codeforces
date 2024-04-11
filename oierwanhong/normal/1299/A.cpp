//Wan Hong 2.2
//home
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<queue>
#include<map>
typedef long long ll;
typedef std::pair<ll,ll> pll;
typedef std::string str;
#define INF (1ll<<58)
ll read()
{
	ll f=1,x=0;
	char c=getchar();
	while(c<'0'||c>'9')
	{
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();
	return f*x;
}
ll max(ll a,ll b)
{
	return a>b?a:b;
}
ll min(ll a,ll b)
{
    return a<b?a:b;
}
bool umax(ll& a,ll b)
{
	if(b>a)return a=b,1;
	return 0;
}
bool umin(ll& a,ll b)
{
	if(b<a)return a=b,1;
	return 0;
}

/**********/
#define MAXN 200011
std::map<ll,ll>p;
ll a[MAXN];
int main()
{
	ll n=read();
	for(ll i=1;i<=n;++i)
	{
		a[i]=read();
		ll t=a[i];
		for(ll j=(1ll<<40);j;j>>=1)
			if(t&j)++p[j];
	}
	for(ll j=1ll<<40;j;j>>=1)
		if(p[j]==1)
		{
			for(ll i=1;i<=n;++i)
				if(a[i]&j)
				{
					printf("%lld ",a[i]);
					break;
				}
			for(ll i=1;i<=n;++i)
				if(!(a[i]&j))printf("%lld ",a[i]);
			return 0;
		}
	for(ll i=1;i<=n;++i)printf("%lld ",a[i]);
	return 0;
}
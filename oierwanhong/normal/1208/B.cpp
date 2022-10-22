//Wan Hong 2.2
//home
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<queue>
#include<vector>
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
#define MAXN 2011
ll n,a[MAXN],t[MAXN];
bool check(ll l,ll r)
{
	ll cnt=0;
	for(ll i=1;i<l;++i)t[++cnt]=a[i];
	for(ll i=r+1;i<=n;++i)t[++cnt]=a[i];
	std::sort(t+1,t+cnt+1);
	for(ll i=2;i<=cnt;++i)
		if(t[i]==t[i-1])return 0;
	return 1;
}
int main()
{
	n=read();
	for(ll i=1;i<=n;++i)a[i]=read();
	ll l=0,r=1,ans=n;
	while(l<=n)
	{
		while(r<=n&&!check(l,r-1))
		{
			++r;
		}
		if(!check(l,r-1))break;
		umin(ans,r-l);
		++l;
	}
	printf("%lld",ans);
	return 0;
}
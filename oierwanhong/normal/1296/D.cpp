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
#define MAXN 200011
ll h[MAXN];
ll ceil_div(ll a,ll b)
{
	if(a%b)return a/b+1;
	else return a/b;
}
int main()
{
	ll n=read(),a=read(),b=read(),k=read();
	for(ll i=1;i<=n;++i)
	{
		ll x=read();
		x=x%(a+b)?x%(a+b):a+b;
		h[i]=ceil_div(x,a)-1;
	}
	std::sort(h+1,h+n+1);
	ll ans=0;
	for(ll i=1;i<=n;++i)
	{
		if(k<h[i])break;
		k-=h[i],++ans;
	}
	printf("%lld",ans);
	return 0;
}
//Wan Hong 2.2
//notebook
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
typedef long long ll;
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
#define MAXN 200011
ll a[MAXN],c[MAXN];
bool vis[MAXN];
int main()
{
	ll n=read();
	for(ll i=1;i<=n;++i)a[i]=read(),++c[a[i]];
	std::sort(a+1,a+n+1);
	ll ans=0;
	for(ll i=1;i<=n;++i)
		if(c[i])++ans,i+=2;
	printf("%lld ",ans);
	ans=0;
	for(ll i=1;i<=n;++i)
	{
		if(!vis[a[i]-1])vis[a[i]-1]=1;
		else if(!vis[a[i]])vis[a[i]]=1;
		else if(!vis[a[i]+1])vis[a[i]+1]=1;
	}
	for(ll i=0;i<=n+1;++i)ans+=vis[i];
	printf("%lld",ans);
	return 0;
}
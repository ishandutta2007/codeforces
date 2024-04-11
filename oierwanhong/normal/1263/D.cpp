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
#define MAXN 511
struct Union_Find_Set
{
	ll fa[MAXN];
	void build()
	{
		for(ll i=0;i<MAXN;++i)fa[i]=i;
	}
	ll find(ll x)
	{
		if(fa[x]==x)return x;
		return fa[x]=find(fa[x]);
	}
	void uni(ll u,ll v)
	{
		u=find(u),v=find(v);
		fa[u]=v;
	}
}s;
bool vis[MAXN];
str cur;
int main()
{
	std::ios::sync_with_stdio(0);
	std::cin.tie(0),std::cout.tie(0);
	s.build();
	ll n,ans=0;
	std::cin>>n;
	for(ll i=1;i<=n;++i)
	{
		std::cin>>cur;
		ll p=cur[0];
		vis[p]=1;
		for(ll j=1;j<cur.size();++j)
		{
			ll x=cur[j];
			vis[x]=1,s.uni(x,p);
		}
	}
	for(ll i=0;i<MAXN;++i)
		if(vis[i]&&s.find(i)==i)++ans;
	printf("%lld",ans);
	return 0;
}
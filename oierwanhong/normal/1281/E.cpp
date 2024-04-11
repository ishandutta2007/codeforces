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
struct Edge
{
	ll v,w,nxt;
}e[MAXN<<1|1];
ll cnt=0,last[MAXN];
void adde(ll u,ll v,ll w)
{
	++cnt;
	e[cnt].v=v,e[cnt].w=w;
	e[cnt].nxt=last[u],last[u]=cnt;
}

ll n,ans,size[MAXN];
void dfs1(ll u,ll fa=0)
{
	size[u]=1;
	for(ll i=last[u];i;i=e[i].nxt)
	{
		ll v=e[i].v;
		if(v==fa)continue;
		dfs1(v,u);
		size[u]+=size[v];
		if(size[v]&1)ans+=e[i].w;
	}
}
void dfs2(ll u,ll fa=0)
{
	for(ll i=last[u];i;i=e[i].nxt)
	{
		ll v=e[i].v;
		if(v==fa)continue;
		dfs2(v,u);
		ans+=min(size[v],n-size[v])*e[i].w;
	}
}
int main()
{
	ll task=read();
	while(task--)
	{
		n=read()<<1;
		for(ll i=1;i<n;++i)
		{
			ll u=read(),v=read(),w=read();
			adde(u,v,w),adde(v,u,w);
		}
		ans=0;
		dfs1(1);
		printf("%lld ",ans);
		ans=0;
		dfs2(1);
		printf("%lld\n",ans);
		for(ll i=1;i<=n;++i)last[i]=0,size[i]=0;
		cnt=0;
	}
	return 0;
}
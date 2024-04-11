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
	ll v,nxt;
}e[MAXN<<1|1];
ll cnt=0,last[MAXN];
void adde(ll u,ll v)
{
	e[++cnt].v=v;
	e[cnt].nxt=last[u],last[u]=cnt;
}

ll a[MAXN],p[MAXN],f[MAXN];
void dfs1(ll u,ll fa=0)
{
	p[u]=a[u];
	for(ll i=last[u];i;i=e[i].nxt)
	{
		ll v=e[i].v;
		if(v==fa)continue;
		dfs1(v,u);
		p[u]+=max(p[v],0);
	}
}
void dfs2(ll u,ll fa=0)
{
	for(ll i=last[u];i;i=e[i].nxt)
	{
		ll v=e[i].v;
		if(v==fa)continue;
		f[v]=max(f[u]-max(p[v],0),0)+p[v];
		dfs2(v,u);
	}
}
int main()
{
	ll n=read();
	for(ll i=1;i<=n;++i)a[i]=(read()==1?1:-1);
	for(ll i=1;i<n;++i)
	{
		ll u=read(),v=read();
		adde(u,v),adde(v,u);
	}
	dfs1(1);
	f[1]=p[1],dfs2(1);
	for(ll i=1;i<=n;++i)printf("%lld ",f[i]);
	return 0;
}
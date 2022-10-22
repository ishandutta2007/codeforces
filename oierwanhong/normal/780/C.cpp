#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<queue>
typedef long long ll;
typedef unsigned un;
typedef std::string str;
typedef std::pair<ll,ll> pll;
ll read(){ll x=0,f=1;char c=getchar();while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}while(c>='0'&&c<='9'){x=x*10+c-'0';c=getchar();}return f*x;}
ll max(ll a,ll b){return a>b?a:b;}
void umax(ll& a,ll t){if(t>a)a=t;}
const ll INF=1ll<<58;
#define MAXN 200011
struct edge
{
	ll v,nxt;
}e[MAXN<<1|1];
ll cnt=0,last[MAXN];
void adde(ll u,ll v)
{
	e[++cnt].v=v;
	e[cnt].nxt=last[u],last[u]=cnt;
}
ll a[MAXN],ans=0;
void dfs(ll u,ll fa=0)
{
	ll cur=1,deg=0;
	for(ll i=last[u];i;i=e[i].nxt)
	{
		ll v=e[i].v;
		++deg;
		if(v==fa)continue;
		while(cur==a[u]||cur==a[fa])++cur;
		a[v]=cur++;
		dfs(v,u);
	}
	umax(ans,deg+1);
}
int main()
{
	ll n=read();
	for(ll i=1;i<n;++i)
	{
		ll u=read(),v=read();
		adde(u,v),adde(v,u);
	}
	a[1]=1;dfs(1);
	printf("%lld\n",ans );
	for(ll i=1;i<=n;++i)printf("%lld ",a[i] );
	
	return 0;
}
#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=2e5+5;

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
	if (x<0) putchar('-'),x=-x;
	if (x<10) putchar(x+'0');
	else write(x/10),putchar(x%10+'0');
}
void print(ll x=-1,char c='\n')
{
	write(x);
	putchar(c);
}
struct edge
{
	ll to,nxt;
}e[N];
ll head[N],cnte=0;
void add_edge(ll u,ll v)
{
	e[++cnte].to=v;
	e[cnte].nxt=head[u];
	head[u]=cnte;
}
ll a[N],b[N],p[N],c[N],d[N],dp[N],st[N],top=0,sum=0;
namespace LCA
{
	ll deep[N],siz[N],son[N],top[N],fa[N],dfn[N],ndfn[N],dis[N],cntdfn=0;
	void dfs0(ll now,ll father)
	{
		siz[now]=1,son[now]=0;
		deep[now]=deep[father]+1;
		dis[now]=dis[father]+d[now];
		ndfn[dfn[now]=++cntdfn]=now;
		fa[now]=father;
		for (ll i=head[now];i;i=e[i].nxt)
		{
			ll to=e[i].to;
			if (to==father) continue;
			dfs0(to,now);
			siz[now]+=siz[to];
			if (siz[son[now]]<siz[to]) son[now]=to;
		}
	}
	void dfs1(ll now,ll father,ll Top)
	{
		top[now]=Top;
		if (son[now]) dfs1(son[now],now,Top);
		for (ll i=head[now];i;i=e[i].nxt)
		{
			ll to=e[i].to;
			if (to==father||to==son[now]) continue;
			dfs1(to,now,to);
		}
	}
	ll find(ll x,ll y)
	{
		while (top[x]!=top[y])
		{
			if (deep[top[x]]>deep[top[y]]) swap(x,y);
			y=fa[top[y]];
		}
		if (deep[x]>deep[y]) swap(x,y);
		return x;
	}
	ll getdis(ll x,ll y)
	{
		return dis[x]+dis[y]-dis[find(x,y)]*2;
	}
}
using LCA::getdis;
using LCA::fa;
using LCA::dfn;
using LCA::ndfn;
void dfs(ll now,ll father)
{
	dp[now]=c[now];
	for (ll i=head[now];i;i=e[i].nxt)
	{
		ll to=e[i].to;
		if (to==father) continue;
		dfs(to,now);
		dp[now]+=min(dp[to],0LL);
	}
}
ll cnt[N];
bool vis[N];
set<ll>s;

signed main(signed Goodbye,char *Wangang[])
{
	(void)Goodbye,(void)Wangang;
	ll n=read(),m=read();
	for (ll i=1;i<=n;i++)
	{
		p[i]=read();
		while (top&&p[st[top]]<p[i]) top--;
		add_edge(st[top],i);
		st[++top]=i;
	}
	for (ll i=1;i<=n;i++) a[i]=read();
	for (ll i=1;i<=n;i++) b[i]=read();
	for (ll i=0;i<=n;i++)
	{
		c[i]=-b[i]+a[i];
		for (ll j=head[i];j;j=e[j].nxt) c[i]+=b[e[j].to];
	}
	dfs(0,0);
	for (ll i=0;i<=n;i++) d[i]=max(dp[i],0LL);
	s.insert(1);
	s.insert(n+2);
	LCA::dfs0(0,0);
	LCA::dfs1(0,0,0);
	for (ll i=1;i<=m;i++)
	{
		ll x=read();
		if (vis[x])
		{
			vis[x]=0; x=fa[x];
			if (x&&!--cnt[x])
			{
				auto L=s.find(dfn[x]),R=L; L--,R++;
				ll l=ndfn[*L],r=ndfn[*R];
				sum=sum-getdis(l,x)-getdis(x,r)+getdis(l,r);
				s.erase(dfn[x]);
			}
		}
		else
		{
			vis[x]=1; x=fa[x];
			if (x&&!cnt[x]++)
			{
				auto R=s.lower_bound(dfn[x]),L=R; L--;
				ll l=ndfn[*L],r=ndfn[*R];
				sum=sum-getdis(l,r)+getdis(l,x)+getdis(x,r);
				s.insert(dfn[x]);
			}
		}
		print(dp[0]+sum/2);
	}
	
	return 0;
}
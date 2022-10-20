#include<bits/stdc++.h>
#define ll long long
#define mk make_pair
#define fi first
#define se second
using namespace std;
const ll N=1e5+5;

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
void print(ll x,char c='\n')
{
	write(x);
	putchar(c);
}
struct edge
{
	ll to,nxt;
}e[N*2];
ll head[N],cnte=0;
void add_edge(ll u,ll v)
{
	e[++cnte].to=v;
	e[cnte].nxt=head[u];
	head[u]=cnte;
}
ll deep[N],top[N],fa[N],son[N],n,m;
ll siz[N],f[N],g[N],dfn[N],cntdfn=0;
vector<pair<ll,ll>>s[N];
void dfs0(ll now,ll father)
{
	siz[now]=1;
	fa[now]=father;
	dfn[now]=++cntdfn;
	deep[now]=deep[father]+1;
	for (ll i=head[now];i;i=e[i].nxt)
	{
		ll to=e[i].to;
		if (to==father) continue;
		dfs0(to,now);
		siz[now]+=siz[to];
		if (siz[son[now]]<siz[to]) son[now]=to;
		s[now].push_back(mk(dfn[to],to));
		f[now]+=f[to]+siz[to];
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
void dfs2(ll now,ll father,ll w)
{
	g[now]=w;
	w+=n-siz[now];
	for (ll i=head[now];i;i=e[i].nxt)
	{
		ll to=e[i].to;
		if (to==father) continue;
		w+=f[to]+siz[to];
	}
	for (ll i=head[now];i;i=e[i].nxt)
	{
		ll to=e[i].to;
		if (to==father) continue;
		dfs2(to,now,w-f[to]-siz[to]);
	}
}
ll find(ll x,ll y)
{
	while (top[x]!=top[y])
	{
		if (deep[top[x]]<deep[top[y]]) swap(x,y);
		x=fa[top[x]];
	}
	if (deep[x]<deep[y]) swap(x,y);
	return y;
}

signed main(signed Goodbye,char *Wangang[])
{
	(void)Goodbye,(void)Wangang;
	n=read(),m=read();
	for (ll i=1;i<n;i++)
	{
		ll u=read(),v=read();
		add_edge(u,v);
		add_edge(v,u);
	}
	dfs0(1,0);
	dfs1(1,0,0);
	dfs2(1,0,0);
	for (ll i=1;i<=m;i++)
	{
		ll x=read(),y=read(),lca=find(x,y),dis=deep[x]+deep[y]-deep[lca]*2+1;
		if (dfn[x]>dfn[y]) swap(x,y);
		if (x==lca)
		{
			x=s[x][upper_bound(s[x].begin(),s[x].end(),mk(dfn[y],N))-s[x].begin()-1].se;
			printf("%.10lf\n",dis+1.0*((n-siz[x])*f[y]+siz[y]*g[x])/((n-siz[x])*siz[y]));
		}
		else printf("%.10lf\n",dis+1.0*(siz[x]*f[y]+siz[y]*f[x])/(siz[x]*siz[y]));
	}
	
	return 0;
}
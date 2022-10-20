#include<bits/stdc++.h>
#define ll long long
#define mk make_pair
#define fi first
#define se second
#define posi vector<pair<ll,ll> >
using namespace std;
const ll N=3e5+5;

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
	if (x<0)
	{
		putchar('-');
		x=-x;
	}
	if (x<10) putchar(x+'0');
	else
	{
		write(x/10);
		putchar(x%10+'0');
	}
}
void print(ll x,char c='\n')
{
	write(x);
	putchar(c);
}
ll root=1,n,q,a[N];
struct edge
{
	ll to,nxt;
}e[N*2];
ll head[N],cnte;
void add_edge(ll u,ll v)
{
	e[++cnte].to=v;
	e[cnte].nxt=head[u];
	head[u]=cnte;
}
vector<ll>to[N];
ll deep[N],fa[N],top[N],dfn[N],siz[N],son[N],cntdfn=0;
void dfs0(ll now,ll father)
{
	siz[now]=1;
	son[now]=0;
	deep[now]=deep[father]+1;
	fa[now]=father;
	dfn[now]=++cntdfn;
	for (ll i=head[now];i;i=e[i].nxt)
	{
		ll to=e[i].to;
		if (to==father) continue;
		::to[now].push_back(to);
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
		if (deep[top[x]]<deep[top[y]]) swap(x,y);
		x=fa[top[x]];
	}
	if (deep[x]<deep[y]) swap(x,y);
	return y;
}
ll lca(ll x,ll y)
{
	ll u=find(x,y),v=find(x,root),w=find(y,root);
	if (deep[u]>=deep[v]&&deep[u]>=deep[w]) return u;
	if (deep[v]>=deep[u]&&deep[v]>=deep[w]) return v;
	return w;
}
bool cmp(ll x,ll y)
{
	return dfn[x]<dfn[y];
}
posi get(ll x)
{
	posi ret;
	ret.clear();
	if (root==x)
	{
		ret.push_back(mk(1,n));
		return ret;
	}
	if (dfn[root]<dfn[x]||dfn[x]+siz[x]-1<dfn[root])
	{
		ret.push_back(mk(dfn[x],dfn[x]+siz[x]-1));
		return ret;
	}
	ll p=*--upper_bound(to[x].begin(),to[x].end(),root,cmp);
	ret.push_back(mk(1,dfn[p]-1));
	ret.push_back(mk(dfn[p]+siz[p],n));
	return ret;
}
struct BIT
{
	ll t[N],ti[N];
	void add(ll *t,ll x,ll y)
	{
		for (;x<=n+1;x+=x&-x) t[x]+=y;
	}
	void add(ll x,ll y)
	{
		add(t,x,y);
		add(ti,x,y*x);
	}
	void add(ll l,ll r,ll x)
	{
		add(l,x);
		add(r+1,-x);
	}
	ll query(ll *t,ll x)
	{
		ll ret=0;
		for (;x;x-=x&-x) ret+=t[x];
		return ret;
	}
	ll query(ll x)
	{
		return query(t,x)*(x+1)-query(ti,x);
	}
	ll query(ll l,ll r)
	{
		return query(r)-query(l-1);
	}
}t;

signed main()
{
	n=read(),q=read();
	for (ll i=1;i<=n;i++) a[i]=read();
	for (ll i=1;i<n;i++)
	{
		ll u=read(),v=read();
		add_edge(u,v);
		add_edge(v,u);
	}
	dfs0(1,0);
	dfs1(1,0,1);
	for (ll i=1;i<=n;i++) t.add(dfn[i],dfn[i],a[i]);
	for (ll i=1;i<=q;i++)
	{
		ll opt=read();
		if (opt==1) root=read();
		if (opt==2)
		{
			ll u=read(),v=read(),x=read(),w=lca(u,v);
			posi tmp=get(w);
			for (auto i:tmp) t.add(i.fi,i.se,x);
		}
		if (opt==3)
		{
			ll u=read(),ans=0;
			posi tmp=get(u);
			for (auto i:tmp) ans+=t.query(i.fi,i.se);
			print(ans);
		}
	}
	
	return 0;
}
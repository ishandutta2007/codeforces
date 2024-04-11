#include<bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define mk make_pair
using namespace std;
const int N=3e5+5;

int read()
{
	int s=0;
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
	int to,nxt;
}e[N*2];
int head[N],cnte=0;
void add_edge(int u,int v)
{
	e[++cnte].to=v;
	e[cnte].nxt=head[u];
	head[u]=cnte;
}
vector<int>Son[N];
namespace LCA
{
	int dfn[N],siz[N],deep[N],fa[N],top[N],son[N],cntdfn=0;
	void dfs0(int now,int father)
	{
		dfn[now]=++cntdfn;
		siz[now]=1;
		son[now]=0;
		deep[now]=deep[father]+1;
		fa[now]=father;
		for (int i=head[now];i;i=e[i].nxt)
		{
			int to=e[i].to;
			if (to==father) continue;
			Son[now].push_back(to);
			dfs0(to,now);
			siz[now]+=siz[to];
			if (siz[to]>siz[son[now]]) son[now]=to;
		}
	}
	void dfs1(int now,int father,int Top)
	{
		top[now]=Top;
		if (son[now]) dfs1(son[now],now,Top);
		for (int i=head[now];i;i=e[i].nxt)
		{
			int to=e[i].to;
			if (to==father||to==son[now]) continue;
			dfs1(to,now,to);
		}
	}
	void YSGS()
	{
		dfs0(1,0);
		dfs1(1,0,1);
	}
	int find(int x,int y)
	{
		while (top[x]!=top[y])
		{
			if (deep[top[x]]<deep[top[y]]) swap(x,y);
			x=fa[top[x]];
		}
		if (deep[x]<deep[y]) swap(x,y);
		return y;
	}
}
using LCA::fa;
using LCA::siz;
using LCA::dfn;
using LCA::find;
int lcatot[N],u[N],v[N],x[N],y[N],lca[N],tote[N],totv[N];
map<int,int>lcatot1[N];
map<pair<int,int>,int>lcatot2[N];
ll ans=0,ans0=0;
void dfs(int now,int father)
{
	for (int i=head[now];i;i=e[i].nxt)
	{
		int to=e[i].to;
		if (to==father) continue;
		dfs(to,now);
		totv[now]+=totv[to];
		tote[now]+=tote[to];
	}
}
bool cmp(int x,int y)
{
	return dfn[x]<dfn[y];
}
inline int getson(int x,int y)
{
	return *--upper_bound(Son[x].begin(),Son[x].end(),y,cmp);
}

signed main(signed Recall,char *_902_[])
{
	(void)Recall,(void)_902_;
	int n=read(),cnt=0;
	for (int i=1;i<n;i++)
	{
		int u=read(),v=read();
		add_edge(u,v);
		add_edge(v,u);
	}
	LCA::YSGS();
	int m=read();
	for (int i=1;i<=m;i++)
	{
		u[i]=read(),v[i]=read(),lca[i]=find(u[i],v[i]);
		if (dfn[u[i]]>dfn[v[i]]) swap(u[i],v[i]);
		cnt+=u[i]==v[i];
		totv[u[i]]++;
		totv[v[i]]++;
		totv[lca[i]]--;
		totv[fa[lca[i]]]--;
		tote[u[i]]++;
		tote[v[i]]++;
		tote[lca[i]]--;
		tote[lca[i]]--;
		lcatot[lca[i]]++;
		if (lca[i]==u[i])
		{
			if (lca[i]!=v[i])
			{
				y[i]=getson(lca[i],v[i]);
				lcatot1[lca[i]][y[i]]++;
			}
		}
		else
		{
			x[i]=getson(lca[i],u[i]),y[i]=getson(lca[i],v[i]);
			lcatot1[lca[i]][x[i]]++;
			lcatot1[lca[i]][y[i]]++;
			lcatot2[lca[i]][mk(x[i],y[i])]++;
		}
	}
	dfs(1,0);
	for (int i=1;i<=m;i++)
	if (lca[i]==u[i])
	{
		ans+=totv[lca[i]];
		if (lca[i]!=v[i]) ans-=tote[y[i]];
	}
	else
	{
		ans+=totv[lca[i]];
		ans-=tote[x[i]]+tote[y[i]];
		ans+=lcatot2[lca[i]][mk(x[i],y[i])];
	}
	for (int i=1;i<=m;i++)
	if (lca[i]==u[i])
	{
		ans0+=lcatot[lca[i]];
		if (lca[i]!=v[i]) ans0-=lcatot1[lca[i]][y[i]];
	}
	else
	{
		ans0+=lcatot[lca[i]];
		ans0-=lcatot1[lca[i]][x[i]]+lcatot1[lca[i]][y[i]];
		ans0+=lcatot2[lca[i]][mk(x[i],y[i])];
	}
	ans0+=cnt;
	ans-=ans0/2;
	print(ans);
	
	return 0;
}
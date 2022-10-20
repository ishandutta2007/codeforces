#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e5+5;
const int B=400;

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
void print(ll x=-1,char c='\n')
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
namespace LCA
{
	int deep[N],siz[N],son[N],fa[N],top[N];
	void dfs0(int now,int father)
	{
		fa[now]=father;
		siz[now]=1,son[now]=0;
		deep[now]=deep[father]+1;
		for (int i=head[now];i;i=e[i].nxt)
		{
			int to=e[i].to;
			if (to==father) continue;
			dfs0(to,now);
			siz[now]+=siz[to];
			if (siz[son[now]]<siz[to]) son[now]=to;
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
	void build(){dfs0(1,0),dfs1(1,0,1);}
	int find(int x,int y)
	{
		while (top[x]!=top[y])
		{
			if (deep[top[x]]>deep[top[y]]) swap(x,y);
			y=fa[top[y]];
		}
		if (deep[x]>deep[y]) swap(x,y);
		return x;
	}
}
struct query
{
	int l,r,Add,id;
	bool operator <(const query &a)const
	{
		if (l/B!=a.l/B) return l<a.l;
		return ((l/B)&1)?r>a.r:r<a.r;
	}
}q[N];
bool vis[N];
ll ans[N],now;
int t[N],a[N],b[N],tot[2][N],st[N],ed[N],cntdfn=0,w[N*2];
void dfs(int now,int father)
{
	w[st[now]=++cntdfn]=now;
	for (int i=head[now];i;i=e[i].nxt)
	{
		int to=e[i].to;
		if (to==father) continue;
		dfs(to,now);
	}
	w[ed[now]=++cntdfn]=now;
}
void add(int t,int a)
{
	now+=tot[!t][a];
	tot[t][a]++;
}
void del(int t,int a)
{
	now-=tot[!t][a];
	tot[t][a]--;
}
void insert(int x)
{
	if (!vis[x]) add(t[x],a[x]);
			else del(t[x],a[x]);
	vis[x]^=1;
}

signed main(signed Goodbye,char *Wangang[])
{
	(void)Goodbye,(void)Wangang;
	int n=read();
	for (int i=1;i<=n;i++) t[i]=read();
	for (int i=1;i<=n;i++) b[i]=a[i]=read();
	sort(b+1,b+1+n);
	int cnt=unique(b+1,b+1+n)-b-1;
	for (int i=1;i<=n;i++) a[i]=lower_bound(b+1,b+1+cnt,a[i])-b;
	for (int i=1;i<n;i++)
	{
		int u=read(),v=read();
		add_edge(u,v);
		add_edge(v,u);
	}
	dfs(1,0);
	LCA::build();
	int m=read();
	for (int i=1;i<=m;i++)
	{
		int x=read(),y=read(),lca=LCA::find(x,y);
		if (st[x]>st[y]) swap(x,y);
		if (x==lca) q[i]=(query){st[x],st[y],0,i};
			   else q[i]=(query){ed[x],st[y],lca,i};
	}
	sort(q+1,q+1+m);
	for (int i=1,l=1,r=0;i<=m;i++)
	{
		while (r<q[i].r) insert(w[++r]);
		while (l>q[i].l) insert(w[--l]);
		while (r>q[i].r) insert(w[r--]);
		while (l<q[i].l) insert(w[l++]);
		if (q[i].Add) insert(q[i].Add);
		ans[q[i].id]=now;
		if (q[i].Add) insert(q[i].Add);
	}
	for (int i=1;i<=m;i++) print(ans[i]);
	
	return 0;
}
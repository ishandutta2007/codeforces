#include<bits/stdc++.h>
#define ull unsigned long long
using namespace std;
const int N=3e5+5;
const int LOG=20;

int read()
{
	int s=0;
	char c=getchar(),lc='+';
	while (c<'0'||'9'<c) lc=c,c=getchar();
	while ('0'<=c&&c<='9') s=s*10+c-'0',c=getchar();
	return lc=='-'?-s:s;
}
void write(int x)
{
	if (x<0) putchar('-'),x=-x;
	if (x<10) putchar(x+'0');
	else write(x/10),putchar(x%10+'0');
}
void print(int x=-1,char c='\n')
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
ull val[N];
int a[N],cnt=0,rt[N],n,m;
int add(int,int,int,int,ull);
namespace LCA
{
	int fa[N],deep[N],siz[N],son[N],top[N],cntdfn;
	void dfs0(int now,int father)
	{
		rt[now]=add(rt[father],1,n,a[now],val[a[now]]);
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
using LCA::find;
mt19937_64 rnd(time(0));
#define mid ((l+r)/2)
struct node
{
	ull sum;
	int ls,rs;
}t[N*LOG];
int add(int w,int l,int r,int x,ull y)
{
	int now=++cnt;
	t[now]=t[w],t[now].sum^=y;
	if (l==r) return now;
	if (x<=mid) t[now].ls=add(t[w].ls,l,mid,x,y);
		   else t[now].rs=add(t[w].rs,mid+1,r,x,y);
	return now;
}
int query(int a,int b,int c,int d,int l,int r,int ql,int qr)
{
	if (!(t[a].sum^t[b].sum^t[c].sum^t[d].sum)) return 0;
	if (l==r) return l;
	if (ql<=mid)
	{
		int tmp=query(t[a].ls,t[b].ls,t[c].ls,t[d].ls,l,mid,ql,qr);
		if (tmp) return tmp;
	}
	if (qr>mid)
	{
		int tmp=query(t[a].rs,t[b].rs,t[c].rs,t[d].rs,mid+1,r,ql,qr);
		if (tmp) return tmp;
	}
	return 0;
}
#undef mid

signed main(signed Goodbye,char *Wangang[])
{
	(void)Goodbye,(void)Wangang;
	n=read(),m=read();
	for (int i=1;i<=n;i++) a[i]=read(),val[i]=rnd();
	for (int i=1;i<n;i++)
	{
		int u=read(),v=read();
		add_edge(u,v);
		add_edge(v,u);
	}
	LCA::dfs0(1,0);
	LCA::dfs1(1,0,1);
	for (int i=1;i<=m;i++)
	{
		int u=read(),v=read(),l=read(),r=read(),lca=find(u,v);
		int ans=query(rt[u],rt[v],rt[lca],rt[fa[lca]],1,n,l,r);
		print(ans?ans:-1);
	}
	
	return 0;
}
#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e5+5;

ll read(){static ll x;scanf("%lld",&x);return x;}
void write(ll x){printf("%lld",x);}
void print(ll x,char c='\n'){write(x),putchar(c);}

vector<int>e[N],t[N];
namespace sptree
{
	int fa[N],top[N],deep[N],siz[N],son[N];
	void dfs0(int now,int father)
	{
		fa[now]=father;
		deep[now]=deep[father]+1;
		siz[now]=1,son[now]=0;
		for (int to:t[now])
		{
			if (to==father) continue;
			dfs0(to,now);
			siz[now]+=siz[to];
			if (siz[to]>siz[son[now]]) son[now]=to;
		}
	}
	void dfs1(int now,int father,int Top)
	{
		top[now]=Top;
		if (son[now]) dfs1(son[now],now,Top);
		for (int to:t[now])
		{
			if (to==father||to==son[now]) continue;
			dfs1(to,now,to);
		}
	}
	void build(int rt)
	{
		dfs0(rt,0);
		dfs1(rt,0,rt);
	}
	int find(int x,int y)
	{
		while (top[x]!=top[y])
		{
			if (deep[top[x]]<deep[top[y]]) swap(x,y);
			x=fa[top[x]];
		}
		return deep[x]<deep[y]?x:y;
	}
}
using namespace sptree;
int u[N],v[N];
struct dsu
{
	int fa[N],n;
	void send(int _n){n=_n;for (int i=1;i<=n;i++) fa[i]=i;}
	int find(int x){return x==fa[x]?x:fa[x]=find(fa[x]);}
	bool merge(int x,int y)
	{
		x=find(x),y=find(y);
		if (x==y) return 0;
		fa[x]=y;
		return 1;
	}
}d;
namespace bcc
{
	bool vis[N];
	int dfn[N],low[N],cntdfn=0,col[N],cntcol=0,st[N],top=0;
	void tarjan(int now,int father)
	{
		low[now]=dfn[now]=++cntdfn;
		st[++top]=now;
		vis[now]=1;
		bool flag=1;
		for (int to:e[now])
		{
			if (to==father&&flag){flag=0;continue;}
			if (!dfn[to]) tarjan(to,now),low[now]=min(low[now],low[to]);
			else if (vis[to]) low[now]=min(low[now],dfn[to]);
		}
		if (low[now]==dfn[now])
		{
			int c=++cntcol,x;
			do
			{
				x=st[top--];
				col[x]=c;
				vis[x]=0;
			}while (x!=now);
		}
	}
}
using namespace bcc;
int a[N],b[N];
void dfs(int now,int father)
{
	for (int to:t[now])
	{
		if (to==father) continue;
		dfs(to,now);
		a[now]+=a[to];
		b[now]+=b[to];
	}
	if (a[now]&&b[now]) puts("No"),exit(0);
}

signed main()
{
	int n=read(),m=read(),Q=read();
	for (int i=1;i<=m;i++)
	{
		u[i]=read(),v[i]=read();
		e[u[i]].push_back(v[i]);
		e[v[i]].push_back(u[i]);
	}
	for (int i=1;i<=n;i++) if (!dfn[i]) tarjan(i,0);
	d.send(cntcol);
	for (int i=1;i<=m;i++)
	if (col[u[i]]!=col[v[i]]&&d.merge(col[u[i]],col[v[i]]))
	{
//		print(col[u[i]],','),print(col[v[i]]);
		t[col[u[i]]].push_back(col[v[i]]);
		t[col[v[i]]].push_back(col[u[i]]);
	}
	vector<int>rt;
	for (int i=1;i<=cntcol;i++) if (d.fa[i]==i) rt.push_back(i);
	for (int i:rt) build(i);
	for (int i=1;i<=Q;i++)
	{
		int s=col[read()],t=col[read()];
		if (d.find(s)!=d.find(t)) return puts("No"),0;
		int lca=find(s,t);
		a[s]++,a[lca]--;
		b[t]++,b[lca]--;
	}
	for (int i:rt) dfs(i,0);
//	for (int i=1;i<=n;i++) print(a[i],':'),print(b[i]);
	puts("Yes");
	
	return 0;
}
#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;

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
void print(int x,char c='\n')
{
	write(x);
	putchar(c);
}
struct Query
{
	int x,c,id;
	bool operator <(const Query &a)const
	{
		return c>a.c;
	}
}q[N];
int ans1[N],ans2[N];
struct edge
{
	int u,v,c,w;
	bool operator <(const edge &a)const
	{
		return c>a.c;
	}
}ed[N];
vector<pair<int,int>>e[N];
namespace lca
{
	int fa[N][20],mx[N][20],deep[N];
	void dfs(int now,int father)
	{
		fa[now][0]=father;
		deep[now]=deep[father]+1;
		for (int i=1;i<20;i++) fa[now][i]=fa[fa[now][i-1]][i-1];
		for (int i=1;i<20;i++) mx[now][i]=max(mx[now][i-1],mx[fa[now][i-1]][i-1]);
		for (auto i:e[now])
		{
			int to=i.first,w=i.second;
			if (to==father) continue;
			mx[to][0]=w;
			dfs(to,now);
		}
	}
	int query(int x,int y)
	{
		int ret=0;
		if (deep[x]<deep[y]) swap(x,y);
		for (int i=19;deep[x]!=deep[y];i--)
		if (deep[fa[x][i]]>=deep[y])
		ret=max(ret,mx[x][i]),x=fa[x][i];
		if (x==y) return ret;
		for (int i=19;i>=0;i--)
		if (fa[x][i]!=fa[y][i])
		ret=max({ret,mx[x][i],mx[y][i]}),
		x=fa[x][i],y=fa[y][i];
		return max({ret,mx[x][0],mx[y][0]});
	}
}
int fa[N],val[N],mx[N],d[N],a[N];
int find(int x){return x==fa[x]?x:fa[x]=find(fa[x]);}
void merge(int u,int v)
{
	u=find(u),v=find(v);
	if (val[u]<val[v]) return void(fa[u]=v);
	if (val[v]<val[u]) return void(fa[v]=u);
	fa[u]=v;
	mx[v]=max({mx[u],mx[v],lca::query(d[u],d[v])});
}

signed main()
{
	int n=read(),Q=read();
	for (int i=1;i<=n;i++) a[i]=read();
	for (int i=1;i<n;i++)
	{
		int u=read(),v=read(),c=read(),w=read();
		ed[i]=(edge){u,v,c,w};
		e[u].push_back(make_pair(v,w));
		e[v].push_back(make_pair(u,w));
	}
	for (int i=1;i<=n;i++) fa[i]=i,val[i]=a[i],mx[i]=0,d[i]=i;
	lca::dfs(1,0);
	sort(ed+1,ed+n);
	for (int i=1;i<=Q;i++) q[i].c=read(),q[i].x=read(),q[i].id=i;
	sort(q+1,q+1+Q);
	for (int i=1,j=1;i<=Q;i++)
	{
		while (j<n&&ed[j].c>=q[i].c) merge(ed[j].u,ed[j].v),j++;
		int x=find(q[i].x);
		ans1[q[i].id]=val[x];
		ans2[q[i].id]=max(mx[x],lca::query(q[i].x,d[x]));
	}
	for (int i=1;i<=Q;i++) print(ans1[i],' '),print(ans2[i]);
	
	return 0;
}
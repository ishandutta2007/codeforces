#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e5+5;
const ll inf=1LL<<60;

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
int fa[N];
int find(int x) {return fa[x]==x?x:fa[x]=find(fa[x]);}
bool merge(int x,int y){bool ret=find(x)!=find(y);fa[find(x)]=find(y);return ret;}
struct Edge
{
	int u,v,w;
	bool operator <(const Edge &a)const
	{
		return w<a.w;
	}
}fe[N*2],E[N*2];
ll mst(int n,int m)
{
	ll ret=0;
	for (int i=1;i<=m;i++)
	if (merge(E[i].u,E[i].v))
	ret+=E[i].w;
	return ret;
}
int n,m;
namespace std1
{
	int e[1000][1000],cnt=0;
	ll get_mst(int u,int v,int w)
	{
		for (int i=1;i<=n;i++) fa[i]=i;
		for (int i=1;i<=cnt;i++) if (E[i].u==u&&E[i].v==v) E[i].w=w;
		for (int i=1;i<cnt;i++) if (E[i].w>E[i+1].w) swap(E[i],E[i+1]);
		ll ret=mst(n,cnt);
		for (int i=1;i<=cnt;i++) E[i]=fe[i];
		return ret;
	}
	void solve()
	{
		int Xor=0;
		ll ans=inf;
		for (int i=1;i<=m;i++) Xor^=fe[i].w;
		for (int i=1;i<=m;i++) e[fe[i].u][fe[i].v]=fe[i].w;
		for (int i=1;i<=m;i++) e[fe[i].v][fe[i].u]=fe[i].w;
		for (int i=1;i<n;i++)
		for (int j=i+1;j<=n;j++)
		E[++cnt]=(Edge){i,j,e[i][j]};
		sort(E+1,E+1+cnt);
		for (int i=1;i<=cnt;i++) fe[i]=E[i];
		for (int i=1;i<n;i++)
		for (int j=i+1;j<=n;j++)
		if (!e[i][j]) ans=min(ans,get_mst(i,j,Xor));
		print(ans);
	}
}
namespace std2
{
	struct edge
	{
		int to,val,nxt;
	}e[N*2];
	int head[N],cnte=0;
	void add_edge(int u,int v,int w)
	{
		e[++cnte].to=v;
		e[cnte].val=w;
		e[cnte].nxt=head[u];
		head[u]=cnte;
	}
	ll get_mst()
	{
		for (int i=1;i<=m;i++) E[i]=fe[i];
		sort(E+1,E+1+m);
		return mst(n,m);
	}
	bool vis[N],is[N];
	int siz[N],no[N];
	void solve()
	{
		for (int i=1;i<=n;i++) fa[i]=i;
		int id=1,cnt=0;
		for (int i=1;i<=m;i++) siz[fe[i].u]++,siz[fe[i].v]++;
		for (int i=2;i<=n;i++) if (siz[i]<siz[id]) id=i;
		for (int i=1;i<=m;i++) add_edge(fe[i].u,fe[i].v,fe[i].w);
		for (int i=1;i<=m;i++) add_edge(fe[i].v,fe[i].u,fe[i].w);
		for (int i=head[id];i;i=e[i].nxt) is[e[i].to]=1;
		for (int i=1;i<=n;i++) if (!is[i]) merge(id,i);
		for (int i=1;i<=n;i++) if (is[i]) no[++cnt]=i;
		for (int i=1;i<=n;i++)
		{
			int tot=0;
			for (int j=head[i];j;j=e[j].nxt) vis[e[j].to]=1,tot+=!is[e[j].to];
			if (tot+cnt<n) merge(i,id);
			for (int j=1;j<=cnt;j++) if (!vis[no[j]]) merge(i,no[j]);
			for (int j=head[i];j;j=e[j].nxt) vis[e[j].to]=0;
		}
		print(get_mst());
	}
}

signed main(signed Recall,char *_902_[])
{
	(void)Recall,(void)_902_;
	n=read(),m=read();
	for (int i=1;i<=m;i++) fe[i].u=read(),fe[i].v=read(),fe[i].w=read();
	if (1LL*n*(n-1)/2-m<n) std1::solve();
					  else std2::solve();
	
	return 0;
}
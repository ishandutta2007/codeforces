#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e5+5;
const int M=1e7+5;
const int p=1e9+7;
const int P=664585;

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
ll power(ll a,ll b)
{
	ll ret=1;
	while (b)
	{
		if (b&1) ret=ret*a%p;
		a=a*a%p;
		b/=2;
	}
	return ret;
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
	int dfn[N],deep[N],fa[N],siz[N],son[N],top[N],cntdfn=0;
	void dfs1(int now,int father)
	{
		dfn[now]=++cntdfn;
		siz[now]=1,son[now]=0;
		deep[now]=deep[fa[now]=father]+1;
		for (int i=head[now];i;i=e[i].nxt)
		{
			int to=e[i].to;
			if (to==father) continue;
			dfs1(to,now);
			siz[now]+=siz[to];
			if (siz[to]>siz[son[now]]) son[now]=to;
		}
	}
	void dfs2(int now,int father,int Top)
	{
		top[now]=Top;
		if (son[now]) dfs2(son[now],now,Top);
		for (int i=head[now];i;i=e[i].nxt)
		{
			int to=e[i].to;
			if (to==father||to==son[now]) continue;
			dfs2(to,now,to);
		}
	}
	void build()
	{
		dfs1(1,0);
		dfs2(1,0,1);
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
using LCA::dfn;
using LCA::siz;
struct Query
{
	int u,v,lca;
}q[N];
ll ans[N];
struct bit
{
	ll t[N]; int n;
	void add(int x,ll y){for (;x<=n;x+=x&-x) t[x]+=y;}
	void add(int l,int r,ll x){add(l,x),add(r+1,-x);}
	ll query(int x){ll ret=0;for (;x;x&=x-1) ret+=t[x];return ret;}
}t1,t2;
bool vis[M];
int mn[M],pr[P],cntp=0;
vector<pair<int,int>>a[P],b[P];
vector<pair<int,int>>get(int x)
{
	vector<pair<int,int>>ret;
	while (x>1)
	{
		int now=mn[x]; x/=pr[now];
		if (ret.empty()||ret.back().second!=now) ret.push_back(make_pair(1,now));
											else ret.back().first++;
	}
	return ret;
}
int query(bit &t,int i)
{
//	print(t.query(dfn[q[i].u]));
//	print(t.query(dfn[q[i].v]));
//	print(-t.query(dfn[q[i].lca]));
//	print(-t.query(dfn[fa[q[i].lca]]));
	return t.query(dfn[q[i].u])+t.query(dfn[q[i].v])-t.query(dfn[q[i].lca])-t.query(dfn[fa[q[i].lca]]);
}

signed main(signed bangumi,char *ss969[])
{
	(void)bangumi,(void)ss969;
	int n=t1.n=t2.n=read(),m=1e7;
	for (int i=1;i<n;i++)
	{
		int u=read(),v=read();
		add_edge(u,v);
		add_edge(v,u);
	}
	LCA::build();
	for (int i=2;i<=m;i++)
	{
		if (!vis[i]) pr[mn[i]=++cntp]=i;
		for (int j=1;j<=cntp;j++)
		{
			if (i*pr[j]>m) break;
			vis[i*pr[j]]=1;
			mn[i*pr[j]]=j;
			if (i%pr[j]==0) break;
		}
	}
	for (int i=1;i<=n;i++)
	{
		int x=read();
		auto t=get(x);
		for (auto j:t) a[j.second].push_back(make_pair(j.first,i));
	}
	int Q=read();
	for (int i=1;i<=Q;i++)
	{
		ans[i]=1;
		int u=q[i].u=read(),v=q[i].v=read(),w=read();
		q[i].lca=LCA::find(u,v);
		auto t=get(w);
		for (auto j:t) b[j.second].push_back(make_pair(j.first,i));
	}
	for (int x=1;x<=cntp;x++)
	if (!b[x].empty())
	{
		sort(a[x].begin(),a[x].end());
		sort(b[x].begin(),b[x].end());
		for (auto i:a[x]) t2.add(dfn[i.second],dfn[i.second]+siz[i.second]-1,1);
		int j=0;
		for (auto i:b[x])
		{
			while (j<(int)a[x].size()&&a[x][j].first<i.first)
			{
				t2.add(dfn[a[x][j].second],dfn[a[x][j].second]+siz[a[x][j].second]-1,-1);
				t1.add(dfn[a[x][j].second],dfn[a[x][j].second]+siz[a[x][j].second]-1,a[x][j].first);
				j++;
			}
			ll tot=query(t1,i.second)+query(t2,i.second)*i.first;
			ans[i.second]=ans[i.second]*power(pr[x],tot)%p;
//			print(i.second,':');
//			print(i.first,' ');
//			print(query(t2,i.second));
		}
		for (int i=0;i<j;i++) t1.add(dfn[a[x][i].second],dfn[a[x][i].second]+siz[a[x][i].second]-1,-a[x][i].first);
		while (j<(int)a[x].size()) t2.add(dfn[a[x][j].second],dfn[a[x][j].second]+siz[a[x][j].second]-1,-1),j++;
	}
	for (int i=1;i<=Q;i++) print(ans[i]);
	
	return 0;
}
#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e4+5;

ll read(){static ll x;scanf("%lld",&x);return x;}
void write(ll x){printf("%lld",x);}
void print(ll x,char c='\n'){write(x),putchar(c);}

int cnt=0,n,m,ans[N];
const int V=N*10;
vector<int>e2[N];
unordered_map<int,vector<int>>e1[N];
int w[N],id[N][2],pre[N],suf[N];
struct two_sat
{
	bool vis[V];
	int dfn[V],low[V],cntdfn=0,st[V],top=0,col[V],cntcol=0;
	vector<int>e[V];
	void add_edge(int u,int v){e[u].push_back(v);}
	void tarjan(int now)
	{
		vis[now]=1;
		st[++top]=now;
		low[now]=dfn[now]=++cntdfn;
		for (int to:e[now])
		if (!dfn[to]) tarjan(to),low[now]=min(low[now],low[to]);
		else if (vis[to]) low[now]=min(low[now],dfn[to]);
		if (low[now]==dfn[now])
		{
			int c=++cntcol,x;
			do
			{
				x=st[top--];
				vis[x]=0;
				col[x]=c;
			}while (x!=now);
		}
	}
	bool solve()
	{
		for (int i=1;i<=cnt;i++) if (!dfn[i]) tarjan(i);
		for (int i=1;i<=m;i++) if (col[id[i][0]]==col[id[i][1]]) return 0;
		for (int i=1;i<=m;i++) ans[i]=col[id[i][1]]<col[id[i][0]];
		return 1;
	}
}g,s;
bool check(int k)
{
	s=g;
	for (int i=1;i<=m;i++) if (w[i]>k) s.add_edge(id[i][1],id[i][0]);
	return s.solve();
}

void GreenDay()
{
	n=read(),m=read();
	for (int i=1;i<=m;i++)
	{
		int u=read(),v=read(),c=read(),w=read();
		e1[u][c].push_back(i);
		e1[v][c].push_back(i);
		e2[u].push_back(i);
		e2[v].push_back(i);
		::w[i]=w;
	}
	for (int i=1;i<=m;i++) id[i][0]=++cnt;
	for (int i=1;i<=m;i++) id[i][1]=++cnt;
	for (int j=1;j<=n;j++)
	for (auto k:e1[j])
	{
		auto &a=k.second;
		int m=a.size();
		for (int i=0;i<m;i++) pre[i]=++cnt;
		for (int i=0;i<m;i++) suf[i]=++cnt;
		for (int i=1;i<m;i++) g.add_edge(pre[i],pre[i-1]);
		for (int i=1;i<m;i++) g.add_edge(suf[i-1],suf[i]);
		for (int i=0;i<m;i++) g.add_edge(pre[i],id[a[i]][1]);
		for (int i=0;i<m;i++) g.add_edge(suf[i],id[a[i]][1]);
		for (int i=1;i<m;i++) g.add_edge(id[a[i]][0],pre[i-1]);
		for (int i=0;i<m-1;i++) g.add_edge(id[a[i]][0],suf[i+1]);
	}
	for (int j=1;j<=n;j++)
	{
		auto &a=e2[j];
		int m=a.size();
		for (int i=0;i<m;i++) pre[i]=++cnt;
		for (int i=0;i<m;i++) suf[i]=++cnt;
		for (int i=1;i<m;i++) g.add_edge(pre[i],pre[i-1]);
		for (int i=1;i<m;i++) g.add_edge(suf[i-1],suf[i]);
		for (int i=0;i<m;i++) g.add_edge(pre[i],id[a[i]][0]);
		for (int i=0;i<m;i++) g.add_edge(suf[i],id[a[i]][0]);
		for (int i=1;i<m;i++) g.add_edge(id[a[i]][1],pre[i-1]);
		for (int i=0;i<m-1;i++) g.add_edge(id[a[i]][1],suf[i+1]);
	}
	int l=0,r=1e9;
	while (l<=r)
	{
		int mid=(l+r)/2;
		if (check(mid)) r=mid-1;
				   else l=mid+1;
	}
	if (!check(l)) return puts("No"),void();
	puts("Yes");
	int tot=0;
	for (int i=1;i<=m;i++) tot+=ans[i];
	print(l,' '),print(tot);
	for (int i=1;i<=m;i++) if (ans[i]) print(i,' ');
}

signed main()
{
	int T=1;
//	int T=read();
	while (T--) GreenDay();
	
	return 0;
}
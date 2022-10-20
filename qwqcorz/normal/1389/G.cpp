#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=3e5+5;

ll read(){static ll x;scanf("%lld",&x);return x;}
void write(ll x){printf("%lld",x);}
void print(ll x,char c='\n'){write(x),putchar(c);}

bool vis[N],is[N];
ll val[N];
int dfn[N],low[N],cntdfn=0,col[N],cntcol=0,st[N],top=0;
vector<int>e[N];
vector<pair<int,int>>t[N];
int p[N],c[N],u[N],v[N],w[N];
void tarjan(int now,int father)
{
	low[now]=dfn[now]=++cntdfn;
	st[++top]=now,vis[now]=1;
	for (int to:e[now])
	{
		if (to==father) continue;
		if (!dfn[to]) tarjan(to,now),low[now]=min(low[now],low[to]);
		else if (vis[to]) low[now]=min(low[now],dfn[to]);
	}
	if (low[now]==dfn[now])
	{
		int x,c=++cntcol;
		do
		{
			x=st[top--];
			col[x]=c;
			vis[x]=0;
		}while (x!=now);
	}
}
int colp[N];
bool has[N];
void dfs0(int now,int father)
{
	has[now]=is[now];
	for (auto [to,w]:t[now])
	{
		if (to==father) continue;
		dfs0(to,now);
		has[now]|=has[to];
	}
}
void dfs00(int now,int father,int top)
{
	if (has[now]) top=now;
	for (auto [to,w]:t[now])
	{
		if (to==father) continue;
		dfs00(to,now,top);
	}
	if (!has[now]) colp[now]=top;
}
void shrink(int n,int m,int k)
{
	tarjan(1,0);
	for (int i=1;i<=k;i++) is[col[p[i]]]=1;
	for (int i=1;i<=n;i++) val[col[i]]+=c[i];
	for (int i=1;i<=m;i++)
	if (col[u[i]]!=col[v[i]])
	{
		t[col[u[i]]].push_back({col[v[i]],w[i]});
		t[col[v[i]]].push_back({col[u[i]],w[i]});
	}
	for (int i=1;i<=cntcol;i++) colp[i]=i;
	dfs0(col[p[1]],0);
	dfs00(col[p[1]],0,0);
	for (int i=1;i<=cntcol;i++) t[i].clear(),val[i]=0;
	for (int i=1;i<=n;i++) val[col[i]=colp[col[i]]]+=c[i];
	for (int i=1;i<=m;i++)
	if (col[u[i]]!=col[v[i]])
	{
		t[col[u[i]]].push_back({col[v[i]],w[i]});
		t[col[v[i]]].push_back({col[u[i]],w[i]});
	}
}
ll F[N],G[N];
void dfs1(int now,int father)
{
	F[now]=val[now];
	for (auto [to,w]:t[now])
	{
		if (to==father) continue;
		dfs1(to,now);
		F[now]+=max(F[to]-w,0LL);
	}
}
void dfs2(int now,int father,ll g)
{
	G[now]=g;
	for (auto [to,w]:t[now])
	{
		if (to==father) continue;
		g+=max(F[to]-w,0LL);
	}
	for (auto [to,w]:t[now])
	{
		if (to==father) continue;
		dfs2(to,now,max(g-max(F[to]-w,0LL)+val[now]-w,0LL));
	}
}

signed main()
{
	int n=read(),m=read(),k=read();
	for (int i=1;i<=k;i++) p[i]=read();
	for (int i=1;i<=n;i++) c[i]=read();
	for (int i=1;i<=m;i++) w[i]=read();
	for (int i=1;i<=m;i++)
	{
		u[i]=read(),v[i]=read();
		e[u[i]].push_back(v[i]);
		e[v[i]].push_back(u[i]);
	}
	shrink(n,m,k);
	int rt=col[p[1]];
	dfs1(rt,0);
	dfs2(rt,0,0);
	for (int i=1;i<=n;i++) print(F[col[i]]+G[col[i]]," \n"[i==n]);
	
	return 0;
}
#include<bits/stdc++.h>
#define int long long
#define ll long long
using namespace std;
const int N=1e5+5;
const int M=3e5+5;
const int inf=1LL<<60;

ll read(){static ll x;scanf("%lld",&x);return x;}
void write(ll x){printf("%lld",x);}
void print(ll x,char c='\n'){write(x),putchar(c);}

struct edge{int to,val;};
vector<edge>e[N],t[N];
int n,m,k,q,u[M],v[M],w[M];
bool vis[N];
int dis[N],nr[N];
void dijkstra()
{
	for (int i=k+1;i<=n;i++) dis[i]=inf;
	for (int i=1;i<=k;i++) nr[i]=i;
	priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q;
	for (int i=1;i<=k;i++) q.push(make_pair(dis[i],i));
	while (!q.empty())
	{
		int now=q.top().second; q.pop();
		if (vis[now]) continue;
		vis[now]=1;
		for (edge i:e[now])
		{
			int to=i.to,val=i.val;
			if (dis[to]>dis[now]+val)
			{
				nr[to]=nr[now];
				dis[to]=dis[now]+val;
				q.push(make_pair(dis[to],to));
			}
		}
	}
}
int fa[N];
int find(int x){return fa[x]==x?x:fa[x]=find(fa[x]);}
namespace lca
{
	int fa[N][20],mx[N][20],deep[N];
	void dfs(int now,int father)
	{
		deep[now]=deep[father]+1;
		fa[now][0]=father;
		for (int i=1;(1<<i)<deep[now];i++)
			fa[now][i]=fa[fa[now][i-1]][i-1],
			mx[now][i]=max(mx[now][i-1],mx[fa[now][i-1]][i-1]);
		for (edge i:t[now])
		{
			int to=i.to,val=i.val;
			if (to==father) continue;
			mx[to][0]=val;
			dfs(to,now);
		}
	}
	int query(int x,int y)
	{
		int ret=0;
		if (deep[x]<deep[y]) swap(x,y);
		for (int i=19;deep[x]!=deep[y];i--)
		if (deep[fa[x][i]]>=deep[y])
			ret=max(ret,mx[x][i]),
			x=fa[x][i];
		if (x==y) return ret;
		for (int i=19;i>=0;i--)
		if (fa[x][i]!=fa[y][i])
			ret=max({ret,mx[x][i],mx[y][i]}),
			x=fa[x][i],y=fa[y][i];
		return max({ret,mx[x][0],mx[y][0]});
	}
}

signed main()
{
	n=read(),m=read(),k=read(),q=read();
	for (int i=1;i<=m;i++)
	{
		int u=read(),v=read(),w=read();
		e[u].push_back((edge){v,w});
		e[v].push_back((edge){u,w});
		::u[i]=u,::v[i]=v,::w[i]=w;
	}
	dijkstra();
	vector<tuple<int,int,int>>ed;
	for (int i=1;i<=m;i++) if (nr[u[i]]!=nr[v[i]]) ed.push_back(make_tuple(dis[u[i]]+dis[v[i]]+w[i],nr[u[i]],nr[v[i]]));
	sort(ed.begin(),ed.end());
	for (int i=1;i<=n;i++) fa[i]=i;
	for (auto i:ed)
	{
		int u=get<1>(i),v=get<2>(i),w=get<0>(i);
		if (find(u)==find(v)) continue;
		fa[find(u)]=find(v);
		t[u].push_back((edge){v,w});
		t[v].push_back((edge){u,w});
	}
	lca::dfs(1,0);
	while (q--)
	{
		int u=read(),v=read();
		print(lca::query(u,v));
	}
	
	return 0;
}
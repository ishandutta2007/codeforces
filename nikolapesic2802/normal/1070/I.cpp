#include <bits/stdc++.h>
using namespace std;
#define pb push_back
const int N=605;
const int M=2*N;
const int inf=1e9+7;
struct Edge
{
	int u,v,c;
	Edge(int a=0, int b=0, int d=0){ u=a,v=b,c=d;}
};
vector<Edge> edges;
vector<int> G[M];
int s,t;
void AddEdge(int u, int v, int c)
{
	G[u].pb(edges.size());
	edges.pb(Edge(u,v,c));
	G[v].pb(edges.size());
	edges.pb(Edge(v,u,0));
}
int dist[M],was[M];
int Cut(int u, int flow)
{
	if(u==t) return flow;
	if(dist[u]>=dist[t]) return 0;
	int ans=0;
	for(;was[u]<G[u].size();was[u]++)
	{
		int e=G[u][was[u]];
		int v=edges[e].v;
		int c=edges[e].c;
		if(dist[u]+1!=dist[v] || !c) continue;
		int cut=Cut(v,min(flow,c));
		ans+=cut;
		flow-=cut;
		edges[e].c-=cut;
		edges[e^1].c+=cut;
		if(!flow) return ans;
	}
	return ans;
}
bool BFS()
{
	for(int i=s;i<=t;i++) dist[i]=inf,was[i]=0;
	queue<int> q;
	q.push(s);dist[s]=0;
	while(q.size())
	{
		int u=q.front();
		q.pop();
		for(int i=0;i<G[u].size();i++)
		{
            int e=G[u][i];
            int v=edges[e].v;
            int c=edges[e].c;
            if(c && dist[v]>dist[u]+1)
			{
				dist[v]=dist[u]+1;
				q.push(v);
			}
		}
	}
	return dist[t]!=inf;
}
int MaxFlow()
{
	int Flow=0;
	while(BFS()) Flow+=Cut(s,inf);
	return Flow;
}
int u[N],v[N],sz[N],col[N];
vector<int> sol[N];
void Run()
{
	int n,m,k,i,j;
	scanf("%i %i %i",&n,&m,&k);
	s=0;t=n+m+1;
	for(i=1;i<=n;i++) sz[i]=0,sol[i].clear();
	for(i=1;i<=m;i++) col[i]=0;
	for(i=s;i<=t;i++) G[i].clear();
	edges.clear();
	for(i=1;i<=m;i++)
	{
		scanf("%i %i",&u[i],&v[i]);
		AddEdge(s,n+i,1);
		AddEdge(n+i,u[i],1);
		AddEdge(n+i,v[i],1);
		sz[u[i]]++;sz[v[i]]++;
	}
	int need=0;
	for(i=1;i<=n;i++)
	{
        int o=1e6;
        for(j=0;j<=sz[i];j++)
		{
            if(sz[i]-j+(j+1)/2<=k){ o=j;break;}
		}
		AddEdge(i,t,o);
		need+=o;
	}
	int flow=MaxFlow();
	if(flow!=need)
	{
		for(i=1;i<=m;i++) printf("0 ");
		printf("\n");
		return;
	}
    for(i=0;i<edges.size();i++)
	{
		int u=edges[i].u;
		int v=edges[i].v;
		int c=edges[i].c;
		if(u>n && u<t && v>0 && v<=n && c==0)
		{
			sol[v].pb(u-n);
		}
	}
	int tsz=0;
	for(i=1;i<=n;i++)
	{
		for(j=1;j<sol[i].size();j+=2)
		{
			tsz++;
			col[sol[i][j]]=tsz;
			col[sol[i][j-1]]=tsz;
		}
	}
	for(i=1;i<=m;i++) if(!col[i]) col[i]=++tsz;
	for(i=1;i<=m;i++) printf("%i ",col[i]);
	printf("\n");
}
int main()
{
	int t;scanf("%i",&t);
	while(t--) Run();
	return 0;
}
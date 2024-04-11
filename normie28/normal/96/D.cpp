#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e4 + 10;
typedef long long ll;
#define clr(x,y) memset(x,y,sizeof x)
#define INF 0x3f3f3f3f
#define IINF 0x3f3f3f3f3f3f3f3f
const ll Mod = 1e9 + 7;
typedef pair<ll,int> P;
typedef unsigned long long ull;
 
int n,m,s,t;
struct Edge{int to;ll w;int next;}edge[maxn << 2];
int head[maxn],edge_num;
ll dist[maxn/10][maxn/10],cost[maxn];
bool vis[maxn];
ll V[maxn],W[maxn];
void Init()
{
    clr(head,-1);edge_num = 0;clr(dist,IINF);clr(cost,IINF);
}
void add_edge(int x,int y,int z)
{
    edge[edge_num] = (Edge){y,z,head[x]};head[x] = edge_num ++;
}
 
void dijkstra(int s)
{
    priority_queue<P,vector<P>,greater<P> >q;
    q.push(P(dist[s][s] = 0, s));
    while(!q.empty())
    {
        int u = q.top().second;ll d = q.top().first;q.pop();
        if(dist[s][u] < d)continue;
        for(int i = head[u];i != -1;i = edge[i].next)
        {
            int  v = edge[i].to;ll w = edge[i].w;
            if(dist[s][v] > dist[s][u] + w)
            {
                q.push(P(dist[s][v] = dist[s][u] + w,v));
            }
        }
    }
}
ll solve()
{
    priority_queue<P,vector<P>,greater<P> >q;
    q.push(P(cost[s] = 0,s));
    while(!q.empty())
    {
        int u = q.top().second;ll co = q.top().first;q.pop();
        if(cost[u] < co)continue;
        for(int i = 1;i <= n;i ++)
        {
            if(dist[u][i] <= V[u] && cost[i] > cost[u] + W[u])
            {
                q.push(P(cost[i] = cost[u] + W[u],i));
            }
        }
    }
    return cost[t];
}
int main()
{
 
    while( ~ scanf("%d%d",&n,&m))
    {
        Init();
        scanf("%d%d",&s,&t);
        for(int i = 1;i <= m;i ++)
        {
            int x,y,z;scanf("%d%d%d",&x,&y,&z);
            add_edge(x,y,z);add_edge(y,x,z);
        }
        for(int i = 1;i <= n;i ++)
        {
            scanf("%lld%lld",&V[i],&W[i]);
        }
        for(int i = 1;i <= n;i ++)
        {
            dijkstra(i);
        }
        
        ll ans = solve();
        printf("%lld\n",ans == IINF ? -1 : ans);
    }
}
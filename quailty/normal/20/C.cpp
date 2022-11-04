#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
typedef long long ll;
const int MAXN=100005;
const ll INF=(1LL<<60)-1;
struct qnode
{
    int v;
    ll c;
    qnode(int _v=0,ll _c=0):v(_v),c(_c) {}
    bool operator <(const qnode &r)const
    {
        return c>r.c;
    }
};
struct Edge
{
    int v,cost;
    Edge(int _v=0,int _cost=0):v(_v),cost(_cost) {}
};
vector<Edge>E[MAXN];
bool vis[MAXN];
ll dis[MAXN];
int pre[MAXN];
void Dijkstra(int n,int st)
{
    memset(vis,false,sizeof(vis));
    for(int i=1; i<=n; i++)dis[i]=INF;
    priority_queue<qnode>que;
    while(!que.empty())que.pop();
    dis[st]=0;
    que.push(qnode(st,0));
    qnode tmp;
    while(!que.empty())
    {
        tmp=que.top();
        que.pop();
        int u=tmp.v;
        if(vis[u])continue;
        vis[u]=true;
        for(int i=0; i<(int)E[u].size(); i++)
        {
            int v=E[tmp.v][i].v;
            int cost=E[u][i].cost;
            if(!vis[v]&&dis[v]>dis[u]+cost)
            {
                dis[v]=dis[u]+cost;
                pre[v]=u;
                que.push(qnode(v,dis[v]));
            }
        }
    }
}
void addedge(int u,int v,int w)
{
    E[u].push_back(Edge(v,w));
}
void output(int n)
{
    if(!n)return;
    output(pre[n]);
    printf("%d ",n);
}
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    while(m--)
    {
        int u,v,w;
        scanf("%d%d%d",&u,&v,&w);
        addedge(u,v,w);
        addedge(v,u,w);
    }
    Dijkstra(n,1);
    if(dis[n]<INF)output(n);
    else printf("-1");
    return 0;
}
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<iomanip>
#include<algorithm>
#include<queue>
using namespace std;
typedef long long ll;
const int MAXN=100005;
struct Edge
{
    int v,cost,ty;
    Edge(int _v=0,int _cost=0,int _ty=0):v(_v),cost(_cost),ty(_ty){}
    bool operator < (const Edge &t)const
    {
        return cost==t.cost ? ty<t.ty : cost<t.cost;
    }
};
struct qnode
{
    int v;
    ll c;
    qnode(int _v=0,ll _c=0):v(_v),c(_c){}
    bool operator < (const qnode &t)const
    {
        return c>t.c;
    }
};
vector<Edge>e[MAXN];
bool vis[MAXN];
ll dis[MAXN],pre[MAXN];
void work(int n,int st)
{
    memset(vis,0,sizeof(vis));
    for(int i=1;i<=n;i++)dis[i]=(1LL<<60),pre[i]=0;
    priority_queue<qnode>q;
    while(!q.empty())q.pop();
    q.push(st);
    dis[st]=0;
    while(!q.empty())
    {
        int u=q.top().v;
        q.pop();
        if(vis[u])continue;
        vis[u]=1;
        for(int i=0;i<(int)e[u].size();i++)
        {
            int v=e[u][i].v;
            int cost=e[u][i].cost;
            if(!vis[v] && dis[v]>=dis[u]+cost+e[u][i].ty)
            {
                dis[v]=dis[u]+cost;
                pre[v]=e[u][i].ty;
                q.push(qnode(v,dis[v]));
            }
        }
    }
}
int main()
{
    int n,m,k;
    scanf("%d%d%d",&n,&m,&k);
    for(int i=1;i<=m;i++)
    {
        int u,v,x;
        scanf("%d%d%d",&u,&v,&x);
        e[u].push_back(Edge(v,x,0));
        e[v].push_back(Edge(u,x,0));
    }
    for(int i=1;i<=k;i++)
    {
        int s,y;
        scanf("%d%d",&s,&y);
        e[1].push_back(Edge(s,y,1));
    }
    work(n,1);
    for(int i=1;i<=n;i++)k-=pre[i];
    return 0*printf("%d",k);
}
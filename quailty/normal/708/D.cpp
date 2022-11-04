#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
const int MAXN = 105;
const int MAXM = 10005;
const int INF = 0x3f3f3f3f;
struct Edge
{
    int to,next,cap,flow,cost;
} edge[MAXM];
int head[MAXN],tol;
int pre[MAXN],dis[MAXN];
bool vis[MAXN];
int N;
void init(int n)
{
    N = n;
    tol = 0;
    memset(head,-1,sizeof(head));
}
void addedge(int u,int v,int cap,int cost)
{
    edge[tol].to = v;
    edge[tol].cap = cap;
    edge[tol].cost = cost;
    edge[tol].flow = 0;
    edge[tol].next = head[u];
    head[u] = tol++;
    edge[tol].to = u;
    edge[tol].cap = 0;
    edge[tol].cost = -cost;
    edge[tol].flow = 0;
    edge[tol].next = head[v];
    head[v] = tol++;
}
bool spfa(int s,int t)
{
    queue<int>q;
    for(int i = 0; i < N; i++)
    {
        dis[i] = INF;
        vis[i] = false;
        pre[i] = -1;
    }
    dis[s] = 0;
    vis[s] = true;
    q.push(s);
    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        vis[u] = false;
        for(int i = head[u]; i != -1; i = edge[i].next)
        {
            int v = edge[i].to;
            if(edge[i].cap > edge[i].flow &&
                    dis[v] > dis[u] + edge[i].cost )
            {
                dis[v] = dis[u] + edge[i].cost;
                pre[v] = i;
                if(!vis[v])
                {
                    vis[v] = true;
                    q.push(v);
                }
            }
        }
    }
    if(pre[t] == -1)return false;
    else return true;
}
int minCostMaxflow(int s,int t,int &cost)
{
    int flow = 0;
    cost = 0;
    while(spfa(s,t))
    {
        int Min = INF;
        for(int i = pre[t]; i != -1; i = pre[edge[i^1].to])
        {
            if(Min > edge[i].cap - edge[i].flow)
                Min = edge[i].cap - edge[i].flow;
        }
        for(int i = pre[t]; i != -1; i = pre[edge[i^1].to])
        {
            edge[i].flow += Min;
            edge[i^1].flow -= Min;
            cost += edge[i].cost * Min;
        }
        flow += Min;
    }
    return flow;
}
int in[MAXN],out[MAXN];
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    init(n+2);
    int buf=0;
    for(int i=1; i<=m; i++)
    {
        int u,v,c,f;
        scanf("%d%d%d%d",&u,&v,&c,&f);
        out[u]+=f,in[v]+=f;
        if(c>=f)
        {
            addedge(u,v,c-f,1);
            addedge(u,v,INF,2);
            addedge(v,u,f,1);
        }
        else
        {
            buf+=f-c;
            addedge(u,v,INF,2);
            addedge(v,u,f-c,0);
            addedge(v,u,c,1);
        }
    }
    for(int i=1; i<=n; i++)
    {
        addedge(0,i,in[i],0);
        addedge(i,n+1,out[i],0);
    }
    addedge(n,1,INF,0);
    int cost;
    minCostMaxflow(0,n+1,cost);
    printf("%d\n",cost+buf);
    return 0;
}
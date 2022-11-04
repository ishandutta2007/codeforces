#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
typedef long long ll;
const ll INF=0x3f3f3f3f3f3f3f3fLL;
const int MAXN=300005;
struct qnode
{
    ll v,c,d,id;
    qnode(ll v=0,ll c=0,ll d=0,ll id=0):v(v),c(c),d(d),id(id){}
    bool operator < (const qnode &r)const
    {
        return c==r.c ? d>r.d : c>r.c;
    }
};
struct Edge
{
    ll v,cost,id;
    Edge(ll v=0,ll cost=0,ll id=0):v(v),cost(cost),id(id){}
};
vector<Edge>E[MAXN];
vector<ll>ans;
bool vis[MAXN];
ll dis[MAXN];
ll Dijkstra(int n,int st)
{
    memset(vis,0,sizeof(vis));
    for(int i=1;i<=n;i++)dis[i]=INF;
    priority_queue<qnode>q;
    q.push(qnode(st,0,0,0));
    ll tot=0;
    dis[st]=0;
    while(!q.empty())
    {
        qnode p=q.top();
        q.pop();
        ll u=p.v;
        if(vis[u])continue;
        vis[u]=1;
        if(p.id>0)ans.push_back(p.id);
        tot+=p.d;
        for(int i=0;i<E[u].size();i++)
        {
            ll v=E[u][i].v;
            ll cost=E[u][i].cost;
            ll id=E[u][i].id;
            if(!vis[v] && dis[v]>=dis[u]+cost)
            {
                dis[v]=dis[u]+cost;
                q.push(qnode(v,dis[v],cost,id));
            }
        }
    }
    sort(ans.begin(),ans.end());
    return tot;
}
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    ll u,v,w;
    for(int i=1;i<=m;i++)
    {
        scanf("%I64d%I64d%I64d",&u,&v,&w);
        E[u].push_back(Edge(v,w,i));
        E[v].push_back(Edge(u,w,i));
    }
    int st;
    scanf("%d",&st);
    printf("%I64d\n",Dijkstra(n,st));
    for(int i=0;i<ans.size();i++)
    {
        printf("%I64d ",ans[i]);
    }
}
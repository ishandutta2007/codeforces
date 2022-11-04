#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
const int INF=0x3f3f3f3f;
const int MAXN=100005;
struct qnode
{
    int v,c;
    qnode(int _v=0,int _c=0):v(_v),c(_c){}
    bool operator < (const qnode &r)const
    {
        return c>r.c;
    }
};
struct Edge
{
    int v,cost;
    Edge(int _v=0,int _cost=0):v(_v),cost(_cost){}
};
vector<Edge>E[MAXN];
void addedge(int u,int v,int w)
{
    E[u].push_back(Edge(v,w));
}
int vis[MAXN],dis[MAXN];
void Dijkstra1(int n,int st)
{
    memset(vis,0,sizeof(vis));
    for(int i=0;i<n;i++)dis[i]=INF;
    priority_queue<qnode>q;
    while(!q.empty())q.pop();
    dis[st]=0;
    q.push(qnode(st,0));
    while(!q.empty())
    {
        qnode t=q.top();
        q.pop();
        int u=t.v;
        if(vis[u])continue;
        vis[u]=1;
        for(int i=0;i<E[u].size();i++)
        {
            int v=E[u][i].v;
            if(!vis[v] && dis[v]>dis[u]+1)
            {
                dis[v]=dis[u]+1;
                q.push(qnode(v,dis[v]));
            }
        }
    }
}
int pre[MAXN],dis2[MAXN];
void Dijkstra2(int n,int st)
{
    memset(pre,-1,sizeof(pre));
    memset(vis,0,sizeof(vis));
    for(int i=0;i<n;i++)dis2[i]=INF;
    priority_queue<qnode>q;
    while(!q.empty())q.pop();
    dis2[st]=0;
    q.push(qnode(st,0));
    while(!q.empty())
    {
        qnode t=q.top();
        q.pop();
        int u=t.v;
        if(vis[u])continue;
        vis[u]=1;
        for(int i=0;i<E[u].size();i++)
        {
            int v=E[u][i].v;
            int cost=E[u][i].cost;
            if(cost)continue;
            if(!vis[v] && dis2[v]>dis2[u]+1)
            {
                dis2[v]=dis2[u]+1;
                pre[v]=u;
                q.push(qnode(v,dis2[v]));
            }
        }
    }
}
int in[MAXN];
void BFS(int n)
{
    memset(in,INF,sizeof(in));
    vector<int>ss;
    vector<pair<pair<int,int>,int> >la,now;
    la.clear();
    now.clear();
    int Min=INF;
    for(int i=0;i<n;i++)
        if(vis[i])Min=min(Min,dis[i]);
    for(int i=0;i<n;i++)
        if(vis[i] && dis[i]==Min)
            la.push_back(make_pair(make_pair(in[i],dis2[i]),i));
    memset(vis,0,sizeof(vis));
    for(int _=Min;_>=0;_--)
    {
        sort(la.begin(),la.end());
        now.clear();
        ss.clear();
        for(int i=0;i<la.size();i++)
        {
            if(i>0 && (la[i].first.first>la[i-1].first.first))break;
            int u=la[i].second;
            for(int j=0;j<E[u].size();j++)
            {
                int v=E[u][j].v;
                int cost=E[u][j].cost;
                if(dis[v]>=dis[u])continue;
                if(in[v]>cost || (in[v]==cost && dis2[v]>dis2[u]+1))
                {
                    in[v]=cost;
                    dis2[v]=dis2[u]+1;
                    pre[v]=u;
                    if(!vis[v])ss.push_back(v);
                    vis[v]=1;
                }
            }
        }
        for(int i=0;i<ss.size();i++)
        {
            now.push_back(make_pair(make_pair(in[ss[i]],dis2[ss[i]]),ss[i]));
        }
        swap(la,now);
    }
}
char s[MAXN];
int tot;
void get_ans(int n,int u)
{
    if(u==n-1 || in[u]==INF)return;
    get_ans(n,pre[u]);
    s[tot++]=in[u]+'0';
}
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    int a,b,l;
    for(int i=1;i<=m;i++)
    {
        scanf("%d%d%d",&a,&b,&l);
        addedge(a,b,l);
        addedge(b,a,l);
    }
    Dijkstra1(n,0);
    Dijkstra2(n,n-1);
    if(vis[0])
        printf("0\n");
    else
    {
        BFS(n);
        get_ans(n,0);
        printf("%s\n",s);
    }
    queue<int>ans;
    for(int i=0;i>=0;i=pre[i])ans.push(i);
    printf("%d\n",ans.size());
    while(!ans.empty())
    {
        printf("%d ",ans.front());
        ans.pop();
    }
    return 0;
}
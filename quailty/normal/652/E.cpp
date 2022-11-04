#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
const int MAXN=300005;
int x[MAXN],y[MAXN],z[MAXN];
struct Edge
{
    int to,nxt,val;
};
struct Graph
{
    int n,tot,head[MAXN];
    Edge edge[MAXN<<1];
    void init(int _n)
    {
        n=_n;
        tot=0;
        memset(head,-1,sizeof(head));
    }
    void addedge(int u,int v,int z)
    {
        edge[tot].to=v;
        edge[tot].val=z;
        edge[tot].nxt=head[u];
        head[u]=tot++;
    }
}G,H;
struct Tarjan
{
    int Low[MAXN],DFN[MAXN],Stack[MAXN],Belong[MAXN];
    int Index,top,block;
    bool vis[MAXN],Instack[MAXN];
    void dfs(int u,int la,Graph &G)
    {
        vis[u]=1;
        int v;
        Low[u]=DFN[u]=++Index;
        Stack[top++]=u;
        Instack[u]=1;
        for(int i=G.head[u];~i;i=G.edge[i].nxt)
        {
            if(i==(la^1))continue;
            v=G.edge[i].to;
            if(!DFN[v])
            {
                dfs(v,i,G);
                if(Low[u]>Low[v])Low[u]=Low[v];
            }
            else if(Instack[v] && Low[u]>DFN[v])
                Low[u]=DFN[v];
        }
        if(Low[u]==DFN[u])
        {
            block++;
            do
            {
                v=Stack[--top];
                Instack[v]=0;
                Belong[v]=block;
            }while(v!=u);
        }
    }
    void solve(Graph &G)
    {
         memset(DFN,0,sizeof(DFN));
         memset(vis,0,sizeof(vis));
         memset(Instack,0,sizeof(Instack));
         Index=top=block=0;
         for(int i=1;i<=G.n;i++)
            if(!vis[i])dfs(i,-1,G);
    }
}T;
int ok[MAXN],vis[MAXN];
void dfs(int u)
{
    vis[u]=1;
    for(int i=H.head[u];~i;i=H.edge[i].nxt)
    {
        int v=H.edge[i].to;
        if(vis[v])continue;
        ok[v]|=ok[u]|H.edge[i].val;
    }
    for(int i=H.head[u];~i;i=H.edge[i].nxt)
    {
        int v=H.edge[i].to;
        if(vis[v])continue;
        dfs(v);
    }
}
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    G.init(n);
    for(int i=1;i<=m;i++)
        scanf("%d%d%d",&x[i],&y[i],&z[i]);
    for(int i=1;i<=m;i++)
    {
        G.addedge(x[i],y[i],z[i]);
        G.addedge(y[i],x[i],z[i]);
    }
    T.solve(G);
    H.init(T.block);
    for(int i=1;i<=m;i++)
    {
        if(T.Belong[x[i]]==T.Belong[y[i]])ok[T.Belong[x[i]]]|=z[i];
        else
        {
            H.addedge(T.Belong[x[i]],T.Belong[y[i]],z[i]);
            H.addedge(T.Belong[y[i]],T.Belong[x[i]],z[i]);
        }
    }
    memset(vis,0,sizeof(vis));
    int a,b;
    scanf("%d%d",&a,&b);
    dfs(T.Belong[a]);
    printf("%s",(ok[T.Belong[b]] ? "YES" : "NO"));
    return 0;
}
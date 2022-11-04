#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
const int MAXN=200005;
const int DEG=18;
int v[MAXN],u[MAXN];
struct Edge
{
    int to,nxt;
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
    void addedge(int u,int v)
    {
        edge[tot].to=v;
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
bool vis[MAXN];
int fa[MAXN][DEG],dep[MAXN],up[MAXN],dw[MAXN];
void dfs1(int u,int la)
{
    vis[u]=1,fa[u][0]=la,dep[u]=dep[la]+1;
    for(int i=1;i<DEG;i++)
        fa[u][i]=fa[fa[u][i-1]][i-1];
    for(int i=H.head[u];~i;i=H.edge[i].nxt)
    {
        int v=H.edge[i].to;
        if(vis[v])continue;
        dfs1(v,u);
    }
}
int lca(int u,int v)
{
    if(dep[u]<dep[v])swap(u,v);
    for(int i=dep[u]-dep[v],j=0;i;i>>=1,j++)
        if(i&1)u=fa[u][j];
    if(u==v)return u;
    for(int i=DEG-1;i>=0;i--)
        if(fa[u][i]!=fa[v][i])
            u=fa[u][i],v=fa[v][i];
    return fa[u][0];
}
void fail()
{
    exit(0*printf("No"));
}
void dfs2(int u)
{
    vis[u]=1;
    for(int i=H.head[u];~i;i=H.edge[i].nxt)
    {
        int v=H.edge[i].to;
        if(vis[v])continue;
        dfs2(v);
        up[u]+=up[v];
        dw[u]+=dw[v];
    }
    if(up[u] && dw[u])fail();
}
int main()
{
    int n,m,q;
    scanf("%d%d%d",&n,&m,&q);
    G.init(n);
    for(int i=1;i<=m;i++)
        scanf("%d%d",&v[i],&u[i]);
    for(int i=1;i<=m;i++)
    {
        G.addedge(u[i],v[i]);
        G.addedge(v[i],u[i]);
    }
    T.solve(G);
    H.init(T.block);
    for(int i=1;i<=m;i++)
    {
        H.addedge(T.Belong[u[i]],T.Belong[v[i]]);
        H.addedge(T.Belong[v[i]],T.Belong[u[i]]);
    }
    memset(vis,0,sizeof(vis));
    for(int i=1;i<=H.n;i++)
        if(!vis[i])dfs1(i,0);
    for(int i=1;i<=q;i++)
    {
        int s,d;
        scanf("%d%d",&s,&d);
        s=T.Belong[s],d=T.Belong[d];
        int p=lca(s,d);
        if(!p)fail();
        up[s]++,up[p]--;
        dw[d]++,dw[p]--;
    }
    memset(vis,0,sizeof(vis));
    for(int i=1;i<=H.n;i++)
        if(!vis[i])dfs2(i);
    return 0*printf("Yes");
}
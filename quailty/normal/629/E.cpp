#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
typedef double db;
const int MAXN=100005;
const int DEG=20;
struct Edge
{
    int to,nxt;
}edge[MAXN<<1];
int head[MAXN],tot;
void init()
{
    memset(head,-1,sizeof(head));
    tot=0;
}
void addedge(int u,int v)
{
    edge[tot].to=v;
    edge[tot].nxt=head[u];
    head[u]=tot++;
}
ll dp[MAXN][3];
int fa[MAXN][DEG],dep[MAXN];
const int root=1;
void dfs1(int u,int pre)
{
    if(u==root)
    {
        dep[u]=0;
        for(int i=0;i<DEG;i++)
            fa[u][i]=u;
    }
    else
    {
        dep[u]=dep[pre]+1;
        fa[u][0]=pre;
        for(int i=1;i<DEG;i++)
            fa[u][i]=fa[fa[u][i-1]][i-1];
    }
    for(int i=head[u];~i;i=edge[i].nxt)
    {
        int v=edge[i].to;
        if(v==pre)continue;
        dfs1(v,u);
        dp[u][0]+=dp[v][0];
        dp[u][1]+=dp[v][1];
    }
    dp[u][1]+=dp[u][0]++;
}
void dfs2(int u,int pre)
{
    if(u==root)dp[u][2]=dp[u][1];
    else dp[u][2]=dp[pre][2]-dp[u][0]+(dp[root][0]-dp[u][0]);
    for(int i=head[u];~i;i=edge[i].nxt)
    {
        int v=edge[i].to;
        if(v==pre)continue;
        dfs2(v,u);
    }
}
void go_up(int &u,int d)
{
    for(int i=0;i<DEG;i++)
        if(d&(1<<i))u=fa[u][i];
}
int lca(int u,int v)
{
    if(dep[u]<dep[v])swap(u,v);
    go_up(u,dep[u]-dep[v]);
    if(u==v)return u;
    for(int i=DEG-1;i>=0;i--)
    {
        if(fa[u][i]==fa[v][i])continue;
        u=fa[u][i];
        v=fa[v][i];
    }
    return fa[u][0];
}
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    init();
    for(int i=1;i<n;i++)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        addedge(u,v);
        addedge(v,u);
    }
    dfs1(root,0);
    dfs2(root,0);
    for(int i=1;i<=m;i++)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        if(dep[u]<dep[v])swap(u,v);
        int p=lca(u,v);
        db res=dep[u]+dep[v]-2*dep[p]+1;
        if(p==v)
        {
            res+=(dp[u][1]+0.0)/dp[u][0];
            go_up(u,dep[u]-dep[v]-1);
            res+=(dp[v][2]-dp[u][1]-dp[u][0]+0.0)/(dp[root][0]-dp[u][0]);
        }
        else res+=(dp[u][1]+0.0)/dp[u][0]+(dp[v][1]+0.0)/dp[v][0];
        printf("%.12f\n",res);
    }
    return 0;
}
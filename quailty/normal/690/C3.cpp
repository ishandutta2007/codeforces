#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
const int MAXN=200005;
int dep[MAXN],fa[MAXN][20];
vector<int>e[MAXN];
void dfs(int u)
{
    dep[u]=dep[fa[u][0]]+1;
    for(int i=1;i<20;i++)
        fa[u][i]=fa[fa[u][i-1]][i-1];
    for(int i=0;i<(int)e[u].size();i++)
        dfs(e[u][i]);
}
int lca(int u,int v)
{
    if(dep[u]<dep[v])swap(u,v);
    for(int i=19,det=dep[u]-dep[v];i>=0;i--)
        if(det>>i&1)u=fa[u][i];
    if(u==v)return u;
    for(int i=19;i>=0;i--)
    {
        if(fa[u][i]==fa[v][i])continue;
        u=fa[u][i];
        v=fa[v][i];
    }
    return fa[u][0];
}
int dis(int u,int v)
{
    return dep[u]+dep[v]-2*dep[lca(u,v)];
}
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=2;i<=n;i++)
    {
        scanf("%d",&fa[i][0]);
        e[fa[i][0]].push_back(i);
    }
    dfs(1);
    int u=1,v=1;
    for(int i=2;i<=n;i++)
    {
        int tu,tv;
        if(dis(u,i)>dis(i,v))tu=u,tv=i;
        else tu=i,tv=v;
        if(dis(tu,tv)>dis(u,v))u=tu,v=tv;
        printf("%d ",dis(u,v));
    }
    return 0;
}
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
const int MAXN=100005;
const int root=1;
vector<int>e[MAXN];
int cnt[MAXN],dep[MAXN],fa[MAXN][17];
void dfs(int u,int p)
{
    if(u==root)
    {
        dep[u]=0;
        for(int i=0;i<17;i++)
            fa[u][i]=u;
    }
    else
    {
        dep[u]=dep[p]+1;
        fa[u][0]=p;
        for(int i=1;i<17;i++)
            fa[u][i]=fa[fa[u][i-1]][i-1];
    }
    cnt[u]=1;
    for(int i=0;i<(int)e[u].size();i++)
    {
        int v=e[u][i];
        if(v==p)continue;
        dfs(v,u);
        cnt[u]+=cnt[v];
    }
}
int swim(int u,int d)
{
    for(int i=16;i>=0;i--)
        if(d&(1<<i))u=fa[u][i];
    return u;
}
int lca(int u,int v)
{
    u=swim(u,dep[u]-dep[v]);
    if(u==v)return u;
    for(int i=16;i>=0;i--)
        if(fa[u][i]!=fa[v][i])
            u=fa[u][i],v=fa[v][i];
    return fa[u][0];
}
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<n;i++)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        e[a].push_back(b);
        e[b].push_back(a);
    }
    dfs(1,0);
    int m;
    scanf("%d",&m);
    for(int i=1;i<=m;i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        if(x==y)
        {
            printf("%d\n",n);
            continue;
        }
        if(dep[x]<dep[y])swap(x,y);
        int p=lca(x,y);
        int d=dep[x]+dep[y]-2*dep[p];
        if(d&1)
        {
            printf("0\n");
            continue;
        }
        int z=swim(x,d/2);
        int res=cnt[z]-cnt[swim(x,d/2-1)];
        if(dep[x]==dep[y])
        {
            res+=cnt[root]-cnt[z];
            res-=cnt[swim(y,d/2-1)];
        }
        printf("%d\n",res);
    }
    return 0;
}
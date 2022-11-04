#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
const int MAXN=200005;
const int INF=0x3f3f3f3f;
int dis[MAXN],col[MAXN];
vector<int>e[MAXN];
void dfs(int u,int fa)
{
    for(int i=0;i<(int)e[u].size();i++)
    {
        int v=e[u][i];
        if(v==fa)continue;
        dis[v]=dis[u]+(col[u]^col[v]);
        dfs(v,u);
    }
}
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&col[i]);
    for(int i=1;i<=n-1;i++)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        e[u].push_back(v);
        e[v].push_back(u);
    }
    memset(dis,INF,sizeof(dis));
    dis[1]=0;
    dfs(1,-1);
    int u=1;
    for(int i=1;i<=n;i++)
        if(dis[i]>dis[u])u=i;
    memset(dis,INF,sizeof(dis));
    dis[u]=0;
    dfs(u,-1);
    u=1;
    for(int i=1;i<=n;i++)
        if(dis[i]>dis[u])u=i;
    printf("%d",(dis[u]+1)/2);
    return 0;
}
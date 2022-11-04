#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
const int MAXN=405;
const int INF=0x3f3f3f3f;
int g[MAXN][MAXN];
int dis[MAXN];
bool vis[MAXN];
void Dijkstra(int n,int st)
{
    for(int i=1;i<=n;i++)
    {
        dis[i]=INF;
        vis[i]=0;
    }
    dis[st]=0;
    for(int j=1;j<=n;j++)
    {
        int k=-1,Min=INF;
        for(int i=1;i<=n;i++)
            if(!vis[i] && dis[i]<Min)
            {
                Min=dis[i];
                k=i;
            }
        if(k==-1)break;
        vis[k]=1;
        for(int i=1;i<=n;i++)
            if(!vis[i] && dis[k]+g[k][i]<dis[i])
                dis[i]=dis[k]+g[k][i];
    }
}
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    memset(g,INF,sizeof(g));
    bool flag=0;
    for(int i=1;i<=m;i++)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        if(u>v)swap(u,v);
        g[u][v]=g[v][u]=1;
        if(u==1 && v==n)flag=1;
    }
    if(flag)
    {
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
            {
                if(i==j)continue;
                g[i][j]=(g[i][j]==INF ? 1 : INF);
            }
    }
    Dijkstra(n,1);
    printf("%d\n",(dis[n]==INF ? -1 : dis[n]));
    return 0;
}
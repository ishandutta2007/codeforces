#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
const int MAXN=200005;
const int INF=0x3f3f3f3f;
struct Edge
{
    int to,nxt;
}edge[MAXN<<1];
int head[MAXN],tot;
void init()
{
    tot=0;
    memset(head,-1,sizeof(head));
}
void addedge(int u,int v)
{
    edge[tot].to=v;
    edge[tot].nxt=head[u];
    head[u]=tot++;
}
int d[MAXN],dp[MAXN][3];
void dfs(int u,int fa)
{
    int t[3]={0,INF,INF};
    for(int i=head[u];~i;i=edge[i].nxt)
    {
        int v=edge[i].to;
        if(v==fa)continue;
        dfs(v,u);
        t[2]=min(t[2]+min(dp[v][2],min(dp[v][0],dp[v][1])),t[1]+min(dp[v][0],dp[v][1])-1);
        t[1]=min(t[1]+min(dp[v][2],min(dp[v][0],dp[v][1])),t[0]+min(dp[v][0],dp[v][1]));
        t[0]=t[0]+min(dp[v][2],min(dp[v][0],dp[v][1]));
    }
    t[0]++;
    for(int i=0;i<3;i++)
        dp[u][i]=min(dp[u][i],t[i]);
}
int main()
{
    int n;
    scanf("%d",&n);
    ll x,y;
    scanf("%I64d%I64d",&x,&y);
    init();
    for(int i=1;i<n;i++)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        addedge(u,v);
        addedge(v,u);
        d[u]++;
        d[v]++;
    }
    int flag=0;
    for(int i=1;i<=n;i++)
        if(d[i]==n-1)flag=1;
    memset(dp,INF,sizeof(dp));
    dfs(1,0);
    int tot=min(dp[1][0],min(dp[1][1],dp[1][2]))-1;
    printf("%I64d\n",min(flag*x+(n-1-flag)*y,(n-1-tot)*x+tot*y));
    return 0;
}
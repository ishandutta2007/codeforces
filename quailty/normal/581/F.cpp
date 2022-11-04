#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
const int MAXN=5005;
const int INF=0x3f3f3f3f;
struct Edge
{
    int to,next;
}edge[MAXN<<1];
int head[MAXN],tot;
void init()
{
    memset(head,-1,sizeof(head));
    tot=0;
}
int d[MAXN];
void addedge(int u,int v)
{
    edge[tot].to=v;
    edge[tot].next=head[u];
    head[u]=tot++;
}
int dp[MAXN][MAXN][2];
int dfs(int u,int fa)
{
    int tot=0,now=0;
    dp[u][0][0]=0;
    dp[u][0][1]=0;
    int flag=1;
    for(int i=head[u];i!=-1;i=edge[i].next)
    {
        int v=edge[i].to;
        if(v==fa)continue;
        flag=0;
        now=dfs(v,u);
        tot+=now;
        for(int k=tot;k>=0;k--)
        {
            int Max[2]={INF,INF};
            for(int j=0;j<=now;j++)
            {
                Max[0]=min(Max[0],min(dp[u][k-j][0]+dp[v][j][0],dp[u][k-j][0]+dp[v][j][1]+1));
                Max[1]=min(Max[1],min(dp[u][k-j][1]+dp[v][j][0]+1,dp[u][k-j][1]+dp[v][j][1]));
            }
            for(int j=0;j<2;j++)
                dp[u][k][j]=Max[j];
        }
    }
    if(flag)
    {
        dp[u][0][1]=INF;
        dp[u][1][1]=0;
    }
    return tot+flag;
}
int main()
{
    init();
    int n;
    scanf("%d",&n);
    int a,b;
    for(int i=1;i<n;i++)
    {
        scanf("%d%d",&a,&b);
        addedge(a,b);
        addedge(b,a);
        d[a]++;
        d[b]++;
    }
    if(n==2)printf("1\n");
    else
    {
        int root=0,cnt=0;
        for(int i=1;i<=n;i++)
        {
            if(d[i]>1)root=i;
            else cnt++;
        }
        memset(dp,INF,sizeof(dp));
        dfs(root,0);
        printf("%d\n",min(dp[root][cnt/2][0],dp[root][cnt/2][1]));
    }
    return 0;
}
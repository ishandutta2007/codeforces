#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
const int MAXN=15;
const int INF=0x3f3f3f3f;
int a[MAXN][MAXN],deg[MAXN],dp[1<<MAXN];
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    int sum=0;
    memset(a,INF,sizeof(a));
    for(int i=0;i<n;i++)
        a[i][i]=0;
    for(int i=0;i<m;i++)
    {
        int x,y,w;
        scanf("%d%d%d",&x,&y,&w);
        sum+=w;
        deg[--x]++;
        deg[--y]++;
        a[x][y]=min(a[x][y],w);
        a[y][x]=min(a[y][x],w);
    }
    for(int k=0;k<n;k++)
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                a[i][j]=min(a[i][j],a[i][k]+a[k][j]);
    for(int i=0;i<n;i++)
        if(deg[i]>0 && a[0][i]==INF)
            return 0*printf("-1");
    memset(dp,INF,sizeof(dp));
    int now=0;
    for(int i=0;i<n;i++)
        now|=(deg[i]&1)<<i;
    dp[now]=0;
    for(int i=(1<<n)-1;i>0;i--)
        for(int j=0;j<n;j++)
        {
            if(~i&(1<<j))continue;
            for(int k=j+1;k<n;k++)
            {
                if(~i&(1<<k))continue;
                dp[i^(1<<j)^(1<<k)]=min(dp[i^(1<<j)^(1<<k)],dp[i]+a[j][k]);
            }
            break;
        }
    printf("%d",sum+dp[0]);
    return 0;
}
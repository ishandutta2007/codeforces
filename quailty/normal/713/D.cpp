#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
int a[1005][1005],val[1005][1005];
int dp[10][10][1005][1005],mm[1005];
void initRMQ(int n,int m)
{
    mm[0] = -1;
    for(int i = 1; i < 1005; i++)
        mm[i] = mm[i-1]+((i&(i-1))==0);
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            dp[0][0][i][j] = val[i][j];
    for(int ii = 0; ii <= mm[n]; ii++)
        for(int jj = 0; jj <= mm[m]; jj++)
            if(ii+jj)for(int i = 1; i + (1<<ii) - 1 <= n; i++)
                for(int j = 1; j + (1<<jj) - 1 <= m; j++)
                {
                    if(ii)dp[ii][jj][i][j] = max(dp[ii-1][jj][i][j],dp[ii-1][jj][i+(1<<(ii-1))][j]);
                    else dp[ii][jj][i][j] = max(dp[ii][jj-1][i][j],dp[ii][jj-1][i][j+(1<<(jj-1))]);
                }
}
int rmq(int x1,int y1,int x2,int y2)
{
    int k1 = mm[x2-x1+1];
    int k2 = mm[y2-y1+1];
    x2 = x2 - (1<<k1) + 1;
    y2 = y2 - (1<<k2) + 1;
    return max({dp[k1][k2][x1][y1],dp[k1][k2][x1][y2],dp[k1][k2][x2][y1],dp[k1][k2][x2][y2]});
}
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=1; i<=n; i++)
        for(int j=1; j<=m; j++)
            scanf("%d",&a[i][j]);
    for(int i=1; i<=n; i++)
        for(int j=1; j<=m; j++)
            if(a[i][j])val[i][j]=min({val[i-1][j-1],val[i][j-1],val[i-1][j]})+1;
    initRMQ(n,m);
    int q;
    scanf("%d",&q);
    while(q--)
    {
        int x[2],y[2];
        for(int i=0; i<2; i++)
            scanf("%d%d",&x[i],&y[i]);
        int l=0,r=min(x[1]-x[0]+1,y[1]-y[0]+1);
        while(l<r)
        {
            int t=(l+r+1)/2;
            if(rmq(x[0]+t-1,y[0]+t-1,x[1],y[1])>=t)l=t;
            else r=t-1;
        }
        printf("%d\n",l);
    }
    return 0;
}
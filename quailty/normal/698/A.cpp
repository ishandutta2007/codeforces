#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
const int INF=0x3f3f3f3f;
int a[105],dp[105][3];
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    memset(dp,INF,sizeof(dp));
    dp[0][0]=0;
    for(int i=1;i<=n;i++)
    {
        if(a[i]&1)
        {
            dp[i][1]=min(dp[i][1],dp[i-1][0]);
            dp[i][1]=min(dp[i][1],dp[i-1][2]);
        }
        if(a[i]&2)
        {
            dp[i][2]=min(dp[i][2],dp[i-1][0]);
            dp[i][2]=min(dp[i][2],dp[i-1][1]);
        }
        for(int j=0;j<3;j++)
            dp[i][0]=min(dp[i][0],dp[i-1][j]+1);
    }
    int res=INF;
    for(int j=0;j<3;j++)
        res=min(res,dp[n][j]);
    return 0*printf("%d",res);
}
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<iomanip>
#include<algorithm>
using namespace std;
typedef double db;
db p[105],dp[105][2];
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%lf",&p[i]);
    sort(p+1,p+n+1);
    db res=0;
    for(int i=0;i<=n;i++)
        for(int j=i+1;j<=n+1;j++)
        {
            memset(dp,0,sizeof(dp));
            dp[0][0]=1;
            for(int k=1;k<=n;k++)
            {
                if(k>i && k<j)
                {
                    dp[k][0]=dp[k-1][0];
                    dp[k][1]=dp[k-1][1];
                }
                else
                {
                    dp[k][0]+=(1-p[k])*dp[k-1][0];
                    dp[k][1]+=p[k]*dp[k-1][0];
                    dp[k][1]+=(1-p[k])*dp[k-1][1];
                }
            }
            res=max(res,dp[n][1]);
        }
    return 0*printf("%.15f",res);
}
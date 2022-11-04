#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
typedef double db;
const int MAXN=18;
db p[MAXN][MAXN],dp[1<<MAXN][MAXN];
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            scanf("%lf",&p[i][j]);
    dp[1][0]=1;
    for(int i=0;i<(1<<n);i++)
        for(int j=0;j<n;j++)
        {
            if(~i&(1<<j))continue;
            for(int k=0;k<n;k++)
            {
                if(j==k || ~i&(1<<k))continue;
                dp[i][j]=max(dp[i][j],p[j][k]*dp[i^(1<<k)][j]+p[k][j]*dp[i^(1<<j)][k]);
            }
        }
    db res=0;
    for(int j=0;j<n;j++)
        res=max(res,dp[(1<<n)-1][j]);
    printf("%.10f",res);
    return 0;
}
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<bitset>
using namespace std;
int c[505];
bitset<505>dp[505][505];
int main()
{
    int n,k;
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++)
        scanf("%d",&c[i]);
    dp[0][0][0]=1;
    for(int i=1;i<=n;i++)
        for(int j=0;j<=k;j++)
        {
            dp[i][j]|=dp[i-1][j];
            if(j>=c[i])
            {
                dp[i][j]|=dp[i-1][j-c[i]];
                dp[i][j]|=dp[i-1][j-c[i]]<<c[i];
            }
        }
    int cnt=0;
    for(int i=0;i<=k;i++)
        cnt+=dp[n][k][i];
    printf("%d\n",cnt);
    for(int i=0;i<=k;i++)
        if(dp[n][k][i])printf("%d ",i);
    return 0;
}
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<iostream>
#include<algorithm>
using namespace std;
int n,m,b,mod;
int a[505];
int dp[2][505][505];
int main()
{
    scanf("%d%d%d%d",&n,&m,&b,&mod);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
    }
    dp[0][0][0]=1;
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<=m;j++)
        {
            for(int k=0;k<=b;k++)
            {
                dp[i%2][j][k]=dp[(i+1)%2][j][k];
                if(j>0 && k>=a[i])dp[i%2][j][k]=(dp[i%2][j][k]+dp[i%2][j-1][k-a[i]])%mod;
            }
        }
    }
    int ans=0;
    for(int i=0;i<=b;i++)
    {
        ans=(ans+dp[n%2][m][i])%mod;
    }
    printf("%d\n",ans);
    return 0;
}
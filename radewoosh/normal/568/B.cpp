#include <bits/stdc++.h>
using namespace std;

int n;

long long mod=1000000007;
//long long sil[5007];
//long long odw[5007];

long long dp[4007][4007][2];
long long wyn;

/*long long dziel(long long a, long long b)
{
    long long x=mod-2;
    while(x)
    {
        if (x&1)
        {
            a*=b;
            a%=mod;
        }
        b*=b;
        b%=mod;
        x>>=1;
    }
    return a%mod;
}*/

int main()
{
    scanf("%d", &n);
    dp[0][0][0]=1;
    for (int i=0; i<n; i++)
    {
        for (int j=0; j<=i; j++)
        {
            dp[i+1][j][1]+=dp[i][j][0]+dp[i][j][1];

            dp[i+1][j+1][0]+=dp[i][j][0];
            dp[i+1][j+1][0]%=mod;

            dp[i+1][j+1][1]+=dp[i][j][1];
            dp[i+1][j+1][1]%=mod;

            dp[i+1][j][1]+=dp[i][j][1]*j;
            dp[i+1][j][1]%=mod;

            dp[i+1][j][0]+=dp[i][j][0]*j;
            dp[i+1][j][0]%=mod;
        }
    }
    for (int i=0; i<=n; i++)
    {
        wyn+=dp[n][i][1];
        wyn%=mod;
    }
    printf("%lld\n", wyn);
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

int t;
int n=30, m=30, k=50;

long long dp[50][50][100];

int main()
{
    for (int i=1; i<=n; i++)
    {
        for (int j=1; j<=m; j++)
        {
            for (int l=1; l<=k; l++)
            {
                dp[i][j][l]=1000000000;
            }
            if (i*j<=k)
            dp[i][j][i*j]=0;
            dp[i][j][0]=0;
        }
    }
    for (int i=1; i<=n; i++)
    {
        for (int j=1; j<=m; j++)
        {
            for (int l=1; l<=k; l++)
            {
                for (int p=1; p<i; p++)
                {
                    for (int b=0; b<=l; b++)
                    {
                        dp[i][j][l]=min(dp[i][j][l], dp[p][j][b]+dp[i-p][j][l-b]+j*j);
                    }
                }
                for (int p=1; p<j; p++)
                {
                    for (int b=0; b<=l; b++)
                    {
                        dp[i][j][l]=min(dp[i][j][l], dp[i][p][b]+dp[i][j-p][l-b]+i*i);
                    }
                }
            }
        }
    }
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d%d%d", &n, &m, &k);
        printf("%lld\n", dp[n][m][k]);
    }
    return 0;
}
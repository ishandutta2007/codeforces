#include <bits/stdc++.h>
using namespace std;

int n;

int tab[1007];

int dp[1007][1007];

int inf=1000000;

int main()
{
    scanf("%d", &n);
    for (int i=1; i<=n; i++)
    {
        scanf("%d", &tab[i]);
    }
    for (int i=0; i<=n+2; i++)
    {
        for (int j=0; j<=n+2; j++)
        {
            dp[i][j]=inf;
        }
    }
    for (int k=1; k<=n; k++)
    {
        for (int p=k; p; p--)
        {
            if (k==p)
            {
                dp[p][k]=1;
                continue;
            }
            if (p+1==k)
            {
                if (tab[p]==tab[k])
                {
                    dp[p][k]=1;
                }
                else
                {
                    dp[p][k]=2;
                }
                continue;
            }
            if (tab[p]==tab[k])
            {
                dp[p][k]=dp[p+1][k-1];
            }
            for (int i=p; i<k; i++)
            {
                dp[p][k]=min(dp[p][k], dp[p][i]+dp[i+1][k]);
            }
        }
    }
    printf("%d\n", dp[1][n]);
    return 0;
}
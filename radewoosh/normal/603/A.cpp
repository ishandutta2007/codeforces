#include <bits/stdc++.h>
using namespace std;

int n;

char wcz[100007];

int dp[100007][2][3];

int wyn;

int main()
{
    scanf("%d", &n);
    scanf("%s", wcz+1);
    for (int i=1; i<=n; i++)
    {
        for (int j=wcz[i]-'0'; j<=wcz[i]-'0'; j++)
        {
            for (int k=0; k<3; k++)
            {
                dp[i][j][k]=dp[i-1][j][k];
                dp[i][j][k]=max(dp[i][j][k], dp[i-1][j^1][k]+1);
                if (k)
                dp[i][j][k]=max(dp[i][j][k], dp[i-1][j][k-1]+1);
            }
        }
    }
    for (int j=0; j<2; j++)
    {
        for (int k=0; k<3; k++)
        {
            wyn=max(wyn, dp[n][j][k]);
        }
    }
    printf("%d\n", wyn);
    return 0;
}
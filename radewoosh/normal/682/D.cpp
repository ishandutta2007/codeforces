#include <bits/stdc++.h>
using namespace std;

int n, m, k;

char wcz1[1007];
char wcz2[1007];

int dp[1007][1007][12][2];

int main()
{
    scanf("%d%d%d", &n, &m, &k);
    scanf("%s", wcz1+1);
    scanf("%s", wcz2+1);
    for (int i=0; i<=n; i++)
    {
        for (int j=0; j<=m; j++)
        {
            for (int l=0; l<=k; l++)
            {
                dp[i][j][l][0]=-1000000000;
                dp[i][j][l][1]=-1000000000;
            }
        }
    }
    dp[0][0][0][0]=0;
    for (int i=0; i<=n; i++)
    {
        for (int j=0; j<=m; j++)
        {
            for (int l=0; l<=k; l++)
            {
                dp[i][j][l][0]=max(dp[i][j][l][0], dp[i][j][l][1]);

                if (wcz1[i+1]==wcz2[j+1])
                dp[i+1][j+1][l][1]=max(dp[i+1][j+1][l][1], dp[i][j][l][1]+1);

                dp[i+1][j][l][0]=max(dp[i+1][j][l][0], dp[i][j][l][0]);
                dp[i][j+1][l][0]=max(dp[i][j+1][l][0], dp[i][j][l][0]);

                if (wcz1[i+1]==wcz2[j+1])
                dp[i+1][j+1][l+1][1]=max(dp[i+1][j+1][l+1][1], dp[i][j][l][0]+1);
            }
        }
    }
    printf("%d\n", dp[n][m][k][0]);
    return 0;
}
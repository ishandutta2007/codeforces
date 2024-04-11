#include <bits/stdc++.h>
using namespace std;

int n, k;

int x;

int dp[1007][1007];

int wyn;

int main()
{
    scanf("%d%d", &n, &k);
    dp[0][0]=1;
    while(n--)
    {
        scanf("%d", &x);
        for (int j=k; j>=0; j--)
        {
            for (int l=k; l>=0; l--)
            {
                if (!dp[j][l])
                continue;
                dp[j][l+x]=1;
                dp[j+x][l+x]=1;
            }
        }
    }
    for (int i=0; i<=k; i++)
    wyn+=dp[i][k];
    printf("%d\n", wyn);
    for (int i=0; i<=k; i++)
    if (dp[i][k])
    printf("%d ", i);
    printf("\n");
    return 0;
}
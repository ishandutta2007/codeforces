#include <bits/stdc++.h>
using namespace std;

int n, k;

int tab[1007];

long long mod=1000000007;

long long dp[207][107][1307];

int cel;

long long wyn;

int main()
{
    scanf("%d%d", &n, &k);
    for (int i=1; i<=n; i++)
    scanf("%d", &tab[i]);
    sort(tab+1, tab+1+n);
    tab[n+1]=tab[n];
    dp[1][0][0]=1;
    for (int i=1; i<=n; i++)
    {
        for (int j=0; j<=(n/2)+2; j++)
        {
            for (int l=0; l<=k; l++)
            {
                cel=l+j*(tab[i+1]-tab[i]);
                if (cel<=k)
                {
                    dp[i+1][j][cel]+=dp[i][j][l]*(j+1);
                    dp[i+1][j][cel]%=mod;
                }

                cel=l+(j+1)*(tab[i+1]-tab[i]);
                if (cel<=k)
                {
                    dp[i+1][j+1][cel]+=dp[i][j][l];
                    dp[i+1][j+1][cel]%=mod;
                }

                cel=l+(j-1)*(tab[i+1]-tab[i]);
                if (j && cel<=k)
                {
                    dp[i+1][j-1][cel]+=dp[i][j][l]*j;
                    dp[i+1][j-1][cel]%=mod;
                }

            }
        }
    }
    for (int i=0; i<=k; i++)
    {
        wyn+=dp[n+1][0][i];
        wyn%=mod;
    }
    printf("%lld\n", wyn);
    return 0;
}
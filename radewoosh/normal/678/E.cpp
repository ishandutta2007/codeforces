#include <bits/stdc++.h>
using namespace std;

int n;

double tab[27][27];

double dp[19][300007];

double wyn;

int main()
{
    scanf("%d", &n);
    for (int i=0; i<n; i++)
    {
        for (int j=0; j<n; j++)
        {
            scanf("%lf", &tab[i][j]);
        }
    }
    dp[0][1]=1.0;
    for (int i=1; i<(1<<n); i++)
    {
        int l=0;
        for (int j=0; j<n; j++)
        {
            l+=((i&(1<<j))>0);
        }
        if (l==1)
        {
            continue;
        }
        for (int j=0; j<n; j++)
        {
            if (!(i&(1<<j)))
            continue;
            double s=0;
            for (int k=0; k<n; k++)
            {
                if (!(i&(1<<k)) || k==j)
                continue;
                dp[j][i]=max(dp[j][i], dp[k][i^(1<<j)]*tab[k][j]+dp[j][i^(1<<k)]*tab[j][k]);
                //printf("%d %d    %lf %lf\n", j, k, dp[k][i^(1<<j)], tab[j][k]);
            }
            //printf("%d %d   %lf\n", j, i, dp[j][i]);
        }
    }
    for (int i=0; i<n; i++)
    wyn=max(wyn, dp[i][(1<<n)-1]);
    printf("%.9lf\n", wyn);
    return 0;
}
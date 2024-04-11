#include <bits/stdc++.h>
using namespace std;

int n;

char wcz[5007];

long long mod=1000000007;

int dp[5007][5007];
int pch[5007][5007];

int roz[5007][5007];

long long wyn;

int po;

int mnie(int a, int b, int d)
{
    int o=roz[a][b];
    return (o<d && wcz[a+o]<wcz[b+o]);
}

int main()
{
    scanf("%d%s", &n, wcz+1);
    for (int p=n; p; p--)
    {
        for (int k=n; k>=p; k--)
        {
            if (p==k)
            {
                roz[p][k]=1;
                continue;
            }
            if (wcz[p]!=wcz[k])
            {
                roz[p][k]=0;
            }
            else
            {
                roz[p][k]=roz[p+1][k+1]+1;
            }
        }
    }
    pch[1][1]=1;
    for (int i=1; i<=n; i++)
    {
        for (int j=i; j<=n; j++)
        {
            dp[i][j]+=pch[i][j];
            if (dp[i][j]>=mod)
            dp[i][j]-=mod;

            pch[i][j+1]+=pch[i][j];
            if (pch[i][j+1]>=mod)
            pch[i][j+1]-=mod;

            if (wcz[j+1]=='0' || j==n)
            continue;
            if (j-i+1>n-j)
            continue;

            po=mnie(i, j+1, (j-i+1));
            //printf("%d %d  %d    %d\n", i, j, po, j+(j-i+1)+1-po);
            pch[j+1][j+(j-i+1)+1-po]+=dp[i][j];
            if (pch[j+1][j+(j-i+1)+1-po]>=mod)
            pch[j+1][j+(j-i+1)+1-po]-=mod;
        }
    }
    for (int i=1; i<=n; i++)
    wyn+=dp[i][n];
    printf("%lld\n", wyn%mod);
    return 0;
}
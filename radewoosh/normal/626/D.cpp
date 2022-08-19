#include <bits/stdc++.h>
using namespace std;

int n;

int tab[2007];

long double dp[5][10007];
long double ile;

long double zwie[10007];

long double wyn;

int main()
{
    scanf("%d", &n);
    ile=n*(n-1)/2.0;
    ile=1.0/ile;
    for (int i=1; i<=n; i++)
    scanf("%d", &tab[i]);
    sort(tab+1, tab+1+n);
    for (int i=1; i<=n; i++)
    {
        for (int j=i+1; j<=n; j++)
        {
            zwie[tab[j]-tab[i]]+=ile;
        }
    }
    for (int j=0; j<=5000; j++)
    {
        dp[1][j]=zwie[j];
    }
    for (int i=0; i<=5000; i++)
    {
        for (int j=0; i+j<=5000; j++)
        {
            dp[2][i+j]+=dp[1][i]*zwie[j];
        }
    }
    for (int i=0; i<=5000; i++)
    {
        for (int j=i+1; j<=5000; j++)
        {
            wyn+=dp[2][i]*zwie[j];
        }
    }
    printf("%.9lf\n", (double)wyn);
    return 0;
}
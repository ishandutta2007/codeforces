#include <bits/stdc++.h>
using namespace std;

int n;

long long tab[3007];

long long inf=(long long)1000000000*1000000000;

long long dp[3007][3007];

long long wyn=inf;

vector <int> kol;

long long z(int v, int u)
{
    long long ch=tab[u];
    return abs(-u+v+tab[u]  - tab[v]);
}

bool mniej(int a, int b)
{
    return tab[a]-a<tab[b]-b;
}

int main()
{
    scanf("%d", &n);
    for (int i=1; i<=n; i++)
    {
        scanf("%lld", &tab[i]);
        tab[i]+=3000;
        kol.push_back(i);
    }
    sort(kol.begin(), kol.end(), mniej);
    for (int i=1; i<=n+1; i++)
    {
        for (int j=0; j<=n+1; j++)
        {
            dp[i][j]=inf;
        }
    }
    for (int i=1; i<=n; i++)
    {
        for (int j=1; j<=n; j++)
        {
            dp[i][j]=min(dp[i][j], dp[i-1][j]+z(i, j));
        }
        for (int j=0; j+1<(int)kol.size(); j++)
        {
            dp[i][kol[j+1]]=min(dp[i][kol[j+1]], dp[i][kol[j]]);
        }
    }
    printf("%lld\n", dp[n][kol.back()]);
    return 0;
}
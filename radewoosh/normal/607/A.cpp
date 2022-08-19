#include <bits/stdc++.h>
using namespace std;

int n;

pair <int,int> tab[1000007];

int dp[1000007];

int wyn=1000000000;

pair <int,int> s;

int poz;

int main()
{
    scanf("%d", &n);
    for (int i=1; i<=n; i++)
    {
        scanf("%d%d", &tab[i].first, &tab[i].second);
    }
    sort(tab+1, tab+1+n);
    tab[0].first=-100000000;
    for (int i=1; i<=n; i++)
    {
        s.first=tab[i].first-tab[i].second;
        poz=lower_bound(tab+1, tab+1+n, s)-tab;
        dp[i]=i-poz+dp[poz-1];
        wyn=min(wyn, n-i+dp[i]);
    }
    printf("%d\n", wyn);
    return 0;
}
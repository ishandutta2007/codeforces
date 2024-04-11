#include <cstdio>
#include <set>
#include <map>
#include <cmath>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int m=1000000;

int n;
int tab[1000007];
int dp[1000007];
int wyn;
int ile[1000007];

int main()
{
    scanf("%d", &n);
    for (int i=1; i<=n; i++)
    {
        scanf("%d", &tab[i]);
        ile[tab[i]]++;
    }
    for (int i=1; i<=m; i++)
    {
        dp[i]=ile[i];
    }
    for (int i=1; i<=m; i++)
    {
        for (int j=2*i; j<=m; j+=i)
        {
            dp[j]=max(dp[j], dp[i]+ile[j]);
        }
        wyn=max(wyn, dp[i]);
    }
    printf("%d", wyn);
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

int n, k;

int x;

long long dp[100007][12];

inline void pisz(int v, int u, long long war)
{
    for (int i=v; i<=n; i+=(-i&i))
    {
        dp[i][u]+=war;
    }
}

inline long long czyt(int a, int b, int u)
{
    long long ret=0;
    for (int i=b; i; i-=(-i&i))
    {
        ret+=dp[i][u];
    }
    for (int i=a-1; i; i-=(-i&i))
    {
        ret+=dp[i][u];
    }
    return ret;
}

int main()
{
    scanf("%d%d", &n, &k);
    pisz(1, 0, 1);
    for (int i=1; i<=n; i++)
    {
        scanf("%d", &x);
        for (int j=k+1; j; j--)
        {
            pisz(x, j, czyt(1, x, j-1));
        }
    }
    printf("%lld\n", czyt(1, n, k+1));
    return 0;
}
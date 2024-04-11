#include <bits/stdc++.h>
using namespace std;

int n;
int s, k;

long long inf=(long long)1000000000*1000000000;

int wyr[5007];

long long x[5007];
long long a[5007];
long long b[5007];
long long c[5007];
long long d[5007];

long long dp[5007][5007];

int main()
{
    scanf("%d%d%d", &n, &s, &k);
    for (int i=1; i<=n; i++)
        scanf("%lld", &x[i]);
    for (int i=1; i<=n; i++)
        scanf("%lld", &a[i]);
    for (int i=1; i<=n; i++)
        scanf("%lld", &b[i]);
    for (int i=1; i<=n; i++)
        scanf("%lld", &c[i]);
    for (int i=1; i<=n; i++)
        scanf("%lld", &d[i]);
    if (s>k)
    {
        swap(s, k);
        for (int i=1; i<=n; i++)
            swap(b[i], d[i]);
        for (int i=1; i<=n; i++)
            swap(a[i], c[i]);
    }
    for (int i=0; i<=n; i++)
        for (int j=0; j<=n; j++)
            dp[i][j]=inf;
    dp[0][0]=0;
    for (int i=1; i<=n; i++)
    {
        if (i<s || i>k)
        {
            for (int j=0; j<=n; j++)
            {
                dp[i][j]=min(dp[i][j], dp[i-1][j]+b[i]+c[i]);
                dp[i][j]=min(dp[i][j], dp[i-1][j]+a[i]+d[i]);
                dp[i][j]=min(dp[i][j], dp[i-1][j+1]+a[i]+c[i]+2*x[i]);
                if (j)
                dp[i][j]=min(dp[i][j], dp[i-1][j-1]+b[i]+d[i]-2*x[i]);
            }
        }
        if (i==s)
        {
            for (int j=0; j<=n; j++)
            {
                dp[i][j]=min(dp[i][j], dp[i-1][j+1]+c[i]+x[i]);
                dp[i][j]=min(dp[i][j], dp[i-1][j]+d[i]-x[i]);
            }
        }
        if (i>s && i<k)
        {
            for (int j=0; j<=n; j++)
            {
                if (j)
                dp[i][j]=min(dp[i][j], dp[i-1][j]+b[i]+c[i]);
                dp[i][j]=min(dp[i][j], dp[i-1][j]+a[i]+d[i]);
                dp[i][j]=min(dp[i][j], dp[i-1][j+1]+a[i]+c[i]+2*x[i]);
                if (j)
                dp[i][j]=min(dp[i][j], dp[i-1][j-1]+b[i]+d[i]-2*x[i]);
            }
        }
        if (i==k)
        {
            for (int j=0; j<=n; j++)
            {
                if (j)
                dp[i][j]=min(dp[i][j], dp[i-1][j-1]+b[i]-x[i]);
                dp[i][j]=min(dp[i][j], dp[i-1][j]+a[i]+x[i]);
            }
        }
        if (i!=n && (i>=k || i<s))
            dp[i][0]=inf;
    }
    printf("%lld\n", dp[n][0]);
    return 0;
}
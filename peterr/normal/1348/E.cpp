#include <bits/stdc++.h>

using namespace std;

const int MAXN = 500;
int a[MAXN];
int b[MAXN];
bool dp[MAXN + 1][MAXN];

int main()
{
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; i++)
        cin >> a[i] >> b[i];
    long long red = 0;
    long long blue = 0;
    for (int i = 0; i < n; i++)
    {
        red += a[i];
        blue += b[i];
    }
    long long ans = red / k + blue / k;
    red %= k;
    blue %= k;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < k; j++)
        {
            dp[i][j] = dp[i - 1][j];
            for (int r = 1; r < k; r++)
            {
                if (a[i - 1] >= r && b[i - 1] >= k - r)
                {
                    dp[i][r] = true;
                    if (dp[i - 1][(j - r + k) % k])
                        dp[i][j] = true;
                }
            }
        }
    }
    for (int i = 1; i < k; i++)
    {
        if (i > red)
            break;
        if (k - i > blue)
            continue;
        if (dp[n][i])
        {
            ans++;
            break;
        }
    }
    cout << ans << endl;
    return 0;
}
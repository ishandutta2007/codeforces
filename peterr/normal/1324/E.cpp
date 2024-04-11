#include <bits/stdc++.h>

using namespace std;

const int NEG = -1E9;
const int MAXN = 2000;
int dp[MAXN + 1][MAXN];
int a[MAXN + 1];

int main()
{
    int n, h, l, r;
    cin >> n >> h >> l >> r;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    fill(dp[0] + 1, dp[0] + h, NEG);
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < h; j++)
        {
            dp[i][j] = NEG;
            int good = j >= l && j <= r;
            dp[i][j] = max(dp[i][j], dp[i - 1][(j - a[i] + h) % h] + good);
            dp[i][j] = max(dp[i][j], dp[i - 1][(j - a[i] + 1 + h) % h] + good);
            if (i == n)
                ans = max(ans, dp[i][j]);
        }
    }
    cout << ans << endl;
    return 0;
}
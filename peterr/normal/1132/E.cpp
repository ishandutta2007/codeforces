#include <bits/stdc++.h>

using namespace std;

const int MAXN = 6750;
const int LCM = 840;
long long a[9];
long long dp[MAXN];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long w;
    cin >> w;
    for (int i = 1; i <= 8; i++)
    {
        cin >> a[i];
    }
    dp[0] = 0;
    fill(dp + 1, dp + MAXN, -1);
    for (int i = 1; i <= 8; i++)
    {
        for (int j = MAXN - 1; j >= 0; j--)
        {
            if (dp[j] == -1)
                continue;
            for (int k = 1; k <= min(a[i], (long long) LCM / i - 1) && j + i * k < MAXN; k++)
            {
                dp[j + i * k] = max(dp[j + i * k], dp[j] + (a[i] - k) / (LCM / i));
            }
            dp[j] += a[i] / (LCM / i);
        }
    }
    long long ans = 0;
    for (int i = 0; i < MAXN && i <= w; i++)
    {
        if (dp[i] == -1)
            continue;
        ans = max(ans, i + LCM * min(dp[i], (w - i) / LCM));
    }
    cout << ans << "\n";
    return 0;
}
#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2E5;
int dp[MAXN + 1];
int best[MAXN + 1];
int a[MAXN + 1];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        fill(best, best + MAXN + 1, 0);
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        sort(a + 1, a + n + 1);
        a[0] = 1;
        int ans = 0;
        for (int i = 1; i <= n; i++)
        {
            dp[i] = 0;
            for (int j = 1; j * j <= a[i]; j++)
            {
                if (a[i] % j != 0)
                    continue;
                dp[i] = max(dp[i], best[j]);
                dp[i] = max(dp[i], best[a[i] / j]);
            }
            dp[i]++;
            best[a[i]] = dp[i];
            ans = max(ans, dp[i]);
            //cout << "dp " << i << " " << dp[i] << endl;
        }
        cout << n - ans << "\n";
    }
    return 0;
}
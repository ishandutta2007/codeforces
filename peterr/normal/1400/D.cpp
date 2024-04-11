#include <bits/stdc++.h>

using namespace std;

const int MAXN = 3000;
int pref[MAXN][MAXN + 1];
int dp[MAXN][MAXN];
int a[MAXN];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        fill(pref[0] + 1, pref[0] + n + 1, 0);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            if (i)
            {
                for (int j = 1; j <= n; j++)
                {
                    pref[i][j] = pref[i - 1][j];
                }
            }
            pref[i][a[i]]++;
        }
        for (int i = 0; i < n; i++)
            fill(dp[i], dp[i] + n, 0);
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 2; j < n; j++)
            {
                dp[i][j] = dp[i][j - 1] + pref[i][a[j]];
            }
        }
        long long ans = 0;
        for (int i = 1; i < n; i++)
        {
            for (int j = i + 2; j < n; j++)
            {
                if (a[i] != a[j])
                    continue;
                ans += dp[i - 1][j - 1];
            }
        }
        cout << ans << "\n";
    }
    return 0;
}
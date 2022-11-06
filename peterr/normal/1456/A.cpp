#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1E5;
int a[MAXN + 1];
int dp[MAXN + 1];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int n, p, k;
        string s;
        cin >> n >> p >> k >> s;
        for (int i = 1; i <= n; i++)
        {
            a[i] = s[i - 1] == '1';
        }
        int x, y;
        cin >> x >> y;
        for (int i = n; i >= 1; i--)
        {
            dp[i] = a[i] == 0 ? x : 0;
            if (i + k <= n)
                dp[i] += dp[i + k];
        }
        int ans = 2E9;
        for (int i = p; i <= n; i++)
        {
            ans = min(ans, dp[i] + (i - p) * y);
        }
        cout << ans << "\n";
    }
    return 0;
}
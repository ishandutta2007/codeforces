#include <bits/stdc++.h>

using namespace std;

const int MAXN = 5000;
const int INF = MAXN * MAXN;
int a[MAXN + 1];
int dp[MAXN + 1][MAXN + 1];
int pref[MAXN + 1];
int suf[MAXN + 1];

void calc(int n, int ind)
{
    pref[0] = dp[ind][0] + n;
    for (int i = 1; i <= n; i++)
    {
        pref[i] = min(pref[i - 1], dp[ind][i] + (n - i));
    }
    suf[n] = dp[ind][n];
    for (int i = n - 1; i >= 0; i--)
    {
        suf[i] = min(suf[i + 1], dp[ind][i]);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    fill(dp[0], dp[0] + n + 1, INF);
    dp[0][0] = 0;
    calc(n, 0);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            if (j > a[i])
            {
                dp[i][j] = INF;
                //cout << i << " " << j << " " << dp[i][j] << "\n";
                continue;
            }
            dp[i][j] = dp[i - 1][j];
            if (j < n)
                dp[i][j] = min(dp[i][j], suf[j + 1]);
            if (j)
                dp[i][j] = min(dp[i][j], pref[j - 1] - (n - j));
            if (a[i] && a[i] == j)
                dp[i][j]--;
            //cout << i << " " << j << " " << dp[i][j] << "\n";
        }
        calc(n, i);
    }
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        if (a[i])
            ans++;
    }
    int best = 0;
    for (int i = 0; i <= n; i++)
    {
        best = min(best, dp[n][i]);
    }
    ans += best;
    cout << ans << "\n";
    return 0;
}
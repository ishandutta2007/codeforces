#include <bits/stdc++.h>

using namespace std;

const int INF = 1E6;
const int MAXN = 3000;
int a[MAXN];
int dp[MAXN][MAXN + 1];

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
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        vector<int> active(n);
        fill(dp[n - 1], dp[n - 1] + n + 1, 0);
        for (int i = n - 2; i >= 0; i--)
        {
            active.assign(n, 0);
            int cost = 0;
            for (int j = i + 1; j < n; j++)
            {
                active[j + a[j]]++;
            }
            dp[i][n] = INF;
            for (int len = n - 1; len >= 0; len--)
            {
                dp[i][len] = dp[i][len + 1];
                int dest = i + len + 1;
                if (dest >= n)
                    continue;
                cost += active[dest];
                cost--;
                if (i + a[i] >= dest)
                {
                    dp[i][len] = min(dp[i][len], cost + dp[dest][i + a[i] - dest]);
                }
            }
        }
        cout << dp[0][0] << "\n";
    }
    return 0;
}
#include <bits/stdc++.h>

using namespace std;

const int MAXN = 100;
long long a[MAXN][MAXN];
long long dp[MAXN][MAXN];

bool inBounds(int r, int c, int n, int m)
{
    return r >= 0 && r < n && c >= 0 && c < m;
}

long long solve(int n, int m, long long start)
{
    if (a[0][0] < start)
        return -1;
    dp[0][0] = a[0][0] - start;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (i == 0 && j == 0)
                continue;
            dp[i][j] = -1;
            long long cost = a[i][j] - (start + i + j);
            if (cost < 0)
                continue;
            if (inBounds(i - 1, j, n, m) && dp[i - 1][j] != -1)
            {
                dp[i][j] = dp[i - 1][j] + cost;
            }
            if (inBounds(i, j - 1, n, m) && dp[i][j - 1] != -1)
            {
                if (dp[i][j] == -1)
                    dp[i][j] = dp[i][j - 1] + cost;
                else
                    dp[i][j] = min(dp[i][j], dp[i][j - 1] + cost);
            }
        }
    }
    return dp[n - 1][m - 1];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
                cin >> a[i][j];
        }
        long long ans = -1;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                long long start = a[i][j] - (i + j);

                long long temp = solve(n, m, start);
                //cout << "hi " << i << " " << j << " " << start << " " << temp << "\n";
                if (temp == -1)
                    continue;
                if (ans == -1)
                    ans = temp;
                else
                    ans = min(ans, temp);
            }
        }
        cout << ans << "\n";
    }
    return 0;
}
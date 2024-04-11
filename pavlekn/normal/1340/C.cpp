#include <bits/stdc++.h>

using namespace std;

#define int long long

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int dp[10007][1007];

const int INF = 1e14 + 118;

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> m >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }
    int g, r;
    cin >> g >> r;
    sort(a.begin(), a.end());
    for (int i = 0; i < 10007; ++i)
    {
        for (int j = 0; j < 1007; ++j)
        {
            dp[i][j] = INF;
        }
    }
    dp[0][0] = 0;
    deque<pair<int, int>> q;
    q.push_back({0, 0});
    while (!q.empty())
    {
        int i = q.front().first;
        int j = q.front().second;
        q.pop_front();
        if (i > 0)
        {
            int d = abs(a[i] - a[i - 1]);
            int cr = dp[i - 1][(j + d) % g];
            if (j + d <= g)
            {
                if (j + d == g)
                {
                    dp[i - 1][(j + d) % g] = min(dp[i - 1][(j + d) % g], dp[i][j] + 1);
                    if (dp[i - 1][(j + d) % g] < cr)
                    {
                        q.push_back({i - 1, (j + d) % g});
                    }
                }
                else
                {
                    dp[i - 1][(j + d) % g] = min(dp[i - 1][(j + d) % g], dp[i][j]);
                    if (dp[i - 1][(j + d) % g] < cr)
                    {
                        q.push_front({i - 1, (j + d) % g});
                    }
                }
            }
        }
        if (i < n - 1)
        {
            int d = abs(a[i] - a[i + 1]);
            int cr = dp[i + 1][(j + d) % g];
            if (j + d <= g)
            {
                if (j + d == g)
                {
                    dp[i + 1][(j + d) % g] = min(dp[i + 1][(j + d) % g], dp[i][j] + 1);
                    if (dp[i + 1][(j + d) % g] < cr)
                    {
                        q.push_back({i + 1, (j + d) % g});
                    }
                }
                else
                {
                    dp[i + 1][(j + d) % g] = min(dp[i + 1][(j + d) % g], dp[i][j]);
                    if (dp[i + 1][(j + d) % g] < cr)
                    {
                        q.push_front({i + 1, (j + d) % g});
                    }
                }
            }
        }
    }
    int ans = dp[n - 1][0] * (r + g) - r;
    for (int j = 1; j < g; ++j)
    {
        ans = min(ans, (r + g) * dp[n - 1][j] + j);
    }
    if (ans >= INF)
    {
        cout << -1 << endl;
    }
    else
    {
        cout << ans << endl;
    }
    return 0;
}
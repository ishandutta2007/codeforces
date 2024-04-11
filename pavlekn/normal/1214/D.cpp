#include<bits/stdc++.h>

using namespace std;

#define int long long

const int MAXN = 1e6 + 5;

const int mod = 2e9 + 87;

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n, m;
    cin >> n >> m;
    vector<vector<char>> a(n, vector<char>(m));
    vector<vector<int>> dp(n, vector<int>(m));
    vector<vector<int>> dp2(n, vector<int>(m));
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            cin >> a[i][j];
        }
    }
    dp[n - 1][m - 1] = 1;
    dp2[0][0] = 1;
    for (int i = n - 1; i >= 0; --i)
    {
        for (int j = m - 1; j >= 0; --j)
        {
            if (a[i][j] == '.')
            {
                if (i + 1 < n)
                {
                    dp[i][j] += dp[i + 1][j];
                }
                if (j + 1 < m)
                {
                    dp[i][j] += dp[i][j + 1];
                }
                dp[i][j] %= mod;
            }
        }
    }
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            if (a[i][j] == '.')
            {
                if (i > 0)
                {
                    dp2[i][j] += dp2[i - 1][j];
                }
                if (j > 0)
                {
                    dp2[i][j] += dp2[i][j - 1];
                }
            }
            dp2[i][j] %= mod;
        }
    }
    if (dp[0][0] == 0)
    {
        cout << 0 << endl;
        return 0;
    }
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            if (dp[0][0] == (dp[i][j] * dp2[i][j]) % mod && i + j > 0 && i + j < n + m - 2)
            {
                cout << 1 << endl;
                return 0;
            }
        }
    }
    cout << 2 << endl;
    return 0;
}
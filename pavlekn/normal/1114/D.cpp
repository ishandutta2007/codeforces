#include <bits/stdc++.h>

using namespace std;

const int MAXN = 5007;

int dp[MAXN][MAXN];

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> a;
    int pr = 0;
    for (int i = 0; i < n; ++i)
    {
        int x;
        cin >> x;
        if (x != pr)
        {
            pr = x;
            a.push_back(x);
        }
    }
    n = a.size();
    for (int i = 0; i < n + 1; ++i)
    {
        dp[i][0] = 0;
    }
    for (int i = 0; i < n; ++i)
    {
        dp[i][1] = 1;
    }
    for (int l = 2; l <= n; ++l)
    {
        for (int i = 0; i + l <= n; ++i)
        {
            dp[i][l] = 1 + dp[i][l - 1];
            dp[i][l] = min(dp[i][l], 1 + dp[i + 1][l - 1]);
            if (a[i] == a[i + l - 1])
            {
                dp[i][l] = min(dp[i][l], 1 + dp[i + 1][l - 2]);
            }
        }
    }
    cout << dp[0][n] - 1 << endl;
    return 0;
}
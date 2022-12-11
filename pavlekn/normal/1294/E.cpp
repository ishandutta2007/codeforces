#include<bits/stdc++.h>

using namespace std;

#define int long long

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m));
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            cin >> a[i][j];
        }
    }
    int ans = 0;
    for (int j = 0; j < m; ++j)
    {
        int cur = n;
        vector<int> cnt(n);
        for (int i = 0; i < n; ++i)
        {
            int x = i * m + j + 1;
            if ((a[i][j] - 1) % m == j && a[i][j] <= n * m)
            {
                cnt[((i - (a[i][j] - 1) / m) % n + n) % n]++;
            }
        }
        for (int i = 0; i < n; ++i)
        {
            cur = min(cur, i + n - cnt[i]);
        }
        ans += cur;
    }
    cout << ans << endl;
    return 0;
}
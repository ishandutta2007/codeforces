#include<bits/stdc++.h>

using namespace std;

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int q;
    cin >> q;
    for (int _ = 0; _ < q; ++_)
    {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> a(n, vector<int>(m));
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < m; ++j)
            {
                char c;
                cin >> c;
                if (c == '*')
                {
                    a[i][j] = 1;
                }
            }
        }
        vector<int> x(n);
        vector<int> y(m);
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < m; ++j)
            {
                x[i] += a[i][j];
                y[j] += a[i][j];
            }
        }
        int ans = n + m;
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < m; ++j)
            {
                if (a[i][j])
                {
                    ans = min(ans, n + m - 1 - (x[i] + y[j] - 1));
                }
                else
                {
                    ans = min(ans, n + m - 1 - (x[i] + y[j]));
                }
            }
        }
        cout << ans << endl;
    }
}
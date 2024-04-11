#include <bits/stdc++.h>

using namespace std;

#define int long long

const int MAXN = 1e3 + 23;

int ans[MAXN][MAXN];

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    for (int _ = 0; _ < t; ++_)
    {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> a(n, vector<int> (m));
        vector<vector<int>> c(n, vector<int> (m));
        vector<vector<int>> b(n, vector<int> (m));
        vector<vector<int>> d(n, vector<int> (m));
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < m; ++j)
            {
                cin >> a[i][j];
                c[i][j] = a[i][j];
            }
            sort(c[i].begin(), c[i].end());
        }
        for (int j = 0; j < m; ++j)
        {
            for (int i = 0; i < n; ++i)
            {
                cin >> b[i][j];
                d[i][j] = b[i][j];
            }
        }
        vector<int> used(n);
        for (int i = 0; i < n; ++i)
        {
            sort(d[i].begin(), d[i].end());
        }
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (used[j])
                {
                    continue;
                }
                int fl = true;
                for (int k = 0; k < m; ++k)
                {
                    if (d[i][k] != c[j][k])
                    {
                        fl = false;
                        break;
                    }
                }
                if (fl)
                {
                    for (int k = 0; k < m; ++k)
                    {
                        ans[i][k] = a[j][k];
                    }
                    used[j] = true;
                    break;
                }
            }
        }
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < m; ++j)
            {
                cout << ans[i][j] << " ";
            }
            cout << endl;
        }
    }
    return 0;
}
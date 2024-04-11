#include <bits/stdc++.h>

using namespace std;

#define int long long

const int MAXN = 1007;

int a[MAXN][MAXN];
int b[MAXN][MAXN];

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<vector<int>> x(n + m);
    vector<vector<int>> y(n + m);
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            cin >> a[i][j];
            x[i + j].push_back(a[i][j]);
        }
    }
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            cin >> b[i][j];
            y[i + j].push_back(b[i][j]);
        }
    }
    int fl = true;
    for (int i = 0; i < n + m; ++i)
    {
        sort(x[i].begin(), x[i].end());
        sort(y[i].begin(), y[i].end());
        for (int j = 0; j < x[i].size(); ++j)
        {
            if (x[i][j] != y[i][j])
            {
                fl = false;
            }
        }
    }
    if (fl)
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }
    return 0;
}
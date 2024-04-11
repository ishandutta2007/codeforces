#include<bits/stdc++.h>

using namespace std;

#define int long long

const int MAXN = 103;

int a[MAXN][MAXN];
int b[MAXN][MAXN];

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            cin >> b[i][j];
        }
    }
    vector<pair<int, int>> ans;
    for (int i = 0; i < n - 1; ++i)
    {
        for (int j = 0; j < m - 1; ++j)
        {
            if (b[i][j] && b[i + 1][j] && b[i][j + 1] && b[i + 1][j + 1])
            {
                a[i][j] = true;
                a[i][j + 1] = true;
                a[i + 1][j] = true;
                a[i + 1][j + 1] = true;
                ans.push_back({i + 1, j + 1});
            }
        }
    }
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            if (a[i][j] != b[i][j])
            {
                cout << -1 << endl;
                return 0;
            }
        }
    }
    cout << ans.size() << endl;
    for (auto el : ans)
    {
        cout << el.first << " " << el.second << endl;
    }
    return 0;
}
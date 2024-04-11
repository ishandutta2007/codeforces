#include <bits/stdc++.h>

using namespace std;

const int MAXN = 50;
bool mat[MAXN + 1][MAXN + 1];
bool res[MAXN + 1][MAXN + 1];
vector<pair<int, int>> ans;

int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> mat[i][j];
        }
    }
    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < m; j++)
        {
            if (mat[i][j] && mat[i + 1][j] && mat[i][j + 1] && mat[i + 1][j + 1])
            {
                ans.push_back({i, j});
                res[i][j] = res[i + 1][j] = res[i][j + 1] = res[i + 1][j + 1] = true;
            }
        }
    }
    bool valid = true;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (mat[i][j] != res[i][j])
                valid = false;
        }
    }
    if (valid)
    {
        cout << ans.size() << endl;
        for (pair<int, int> p : ans)
        {
            cout << p.first << " " << p.second << endl;
        }
    }
    else
    {
        cout << -1 << endl;
    }

    return 0;
}
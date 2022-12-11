#include <bits/stdc++.h>

using namespace std;

#define int long long

const int MAXN = 1e6 + 77;

vector<vector<int>> g(MAXN);

int u[MAXN];
int t[MAXN];

void dfs(int i)
{
    u[i] = true;
    for (auto v : g[i])
    {
        if (!u[v])
        {
            dfs(v);
        }
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int> (m));
    vector<vector<int>> used(n, vector<int> (m));
    vector<int> b(n);
    vector<int> c(m);
    int sm = 0;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            char cv;
            cin >> cv;
            int x = 0;
            if (cv == '#')
            {
                x = 1;
            }
            a[i][j] = x;
            b[i] += x;
            c[j] += x;
            sm += x;
        }
    }
    if (sm == 0)
    {
        cout << 0 << endl;
        return 0;
    }
    for (int i = 0; i < n; ++i)
    {
        if (b[i])
        {
            continue;
        }
        int t = 1;
        for (int j = 0; j < m; ++j)
        {
            if (!c[j])
            {
                t = 0;
            }
        }
        if (t)
        {
            cout << -1 << endl;
            return 0;
        }
    }
    for (int i = 0; i < m; ++i)
    {
        if (c[i])
        {
            continue;
        }
        int t = 1;
        for (int j = 0; j < n; ++j)
        {
            if (!b[j])
            {
                t = 0;
            }
        }
        if (t)
        {
            cout << -1 << endl;
            return 0;
        }
    }
    for (int i = 0; i < n; ++i)
    {
        int cc = 0;
        for (int j = 0; j < m; ++j)
        {
            if ((j == 0 || !a[i][j - 1]) && a[i][j])
            {
                ++cc;
            }
        }
        if (cc > 1)
        {
            cout << -1 << endl;
            return 0;
        }
    }
    for (int i = 0; i < m; ++i)
    {
        int cc = 0;
        for (int j = 0; j < n; ++j)
        {
            if ((j == 0 || !a[j - 1][i]) && a[j][i])
            {
                ++cc;
            }
        }
        if (cc > 1)
        {
            cout << -1 << endl;
            return 0;
        }
    }
    int ans = 0;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            if (a[i][j])
            {
                t[i * m + j] = true;
                if (i > 0 && a[i - 1][j])
                {
                    g[i * m + j].push_back(i * m + j - m);
                }
                if (i < n - 1 && a[i + 1][j])
                {
                    g[i * m + j].push_back(i * m + j + m);
                }
                if (j > 0 && a[i][j - 1])
                {
                    g[i * m + j].push_back(i * m + j - 1);
                }
                if (j < m - 1 && a[i][j + 1])
                {
                    g[i * m + j].push_back(i * m + j + 1);
                }
            }
        }
    }
    for (int i = 0; i < n * m; ++i)
    {
        if (!u[i] && t[i])
        {
            dfs(i);
            ++ans;
        }
    }
    cout << ans << endl;
    return 0;
}
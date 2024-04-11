#include <bits/stdc++.h>

using namespace std;

#define int long long

const int MAXN = 1e5 + 7;

int used[MAXN];

int add = 0;

vector<vector<int>> g(MAXN);

int cc = 0;

void dfs(int u, int pr = -1)
{
    ++cc;
    used[u] = true;
    for (auto v : g[u])
    {
        if (!used[v])
        {
            dfs(v, u);
        }
        else if (v != pr)
        {
            add = 1;
        }
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    for (int _= 0; _ < t; ++_)
    {
        int n, m;
        cin >> n >> m;
        for (int i = 0; i < m; ++i)
        {
            used[i] = false;
            g[i] = {};
        }
        int ans = 0;
        vector<int> x(m);
        vector<int> y(m);
        vector<int> cnt(n);
        vector<int> xx(n);
        vector<int> yy(n);
        for (int i = 0; i < m; ++i)
        {
            cin >> x[i] >> y[i];
            --x[i]; --y[i];
            xx[x[i]] = i;
            yy[y[i]] = i;
            if (x[i] != y[i])
            {
                ++cnt[x[i]];
                ++cnt[y[i]];
            }
            else
            {
                used[i] = true;
            }
        }
        for (int i = 0; i < m; ++i)
        {
            if (cnt[x[i]] == 2)
            {
                g[i].push_back(yy[x[i]]);
            }
            if (cnt[y[i]] == 2)
            {
                g[i].push_back(xx[y[i]]);
            }
        }
        for (int i = 0; i < m; ++i)
        {
            if (!used[i])
            {
                add = 0;
                cc = 0;
                dfs(i);
                ans += cc + add;
            }
        }
        cout << ans << endl;
    }
    return 0;
}
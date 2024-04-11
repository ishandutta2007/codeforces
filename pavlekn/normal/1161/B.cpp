#include <bits/stdc++.h>

using namespace std;

#define int long long

const int INF = 1e9;

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<int> a;
    a.push_back(1);
    for (int i = 2; i * i <= n; ++i)
    {
        if (n % i == 0)
        {
            a.push_back(i);
            a.push_back(n / i);
        }
    }
    vector<vector<int>> g(n);
    for (int i = 0; i < m; ++i)
    {
        int u, v;
        cin >> u >> v;
        --u; --v;
        g[u].push_back((u - v + n) % n);
        g[v].push_back((v - u + n) % n);
    }
    for (int i = 0; i < n; ++i)
    {
        sort(g[i].begin(), g[i].end());
    }
    for (auto k : a)
    {
        int fl = true;
        for (int i = 0; i < n; ++i)
        {
            int j = (i + k) % n;
            if (g[i].size() != g[j].size())
            {
                fl = false;
                break;
            }
            for (int ii = 0; ii < g[i].size(); ++ii)
            {
                if (g[i][ii] != g[j][ii])
                {
                    fl = false;
                    break;
                }
            }
        }
        if (fl)
        {
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;
    return 0;
}
#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e3 + 43;

vector<vector<int>> g(MAXN);

int deg[MAXN];

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n - 1; ++i)
    {
        int u, v;
        cin >> u >> v;
        --u; --v;
        g[u].push_back(v);
        g[v].push_back(u);
        ++deg[u];
        ++deg[v];
    }
    int cnt = n;
    vector<int> used(n);
    while (true)
    {
        if (cnt == 1)
        {
            int u = -1;
            for (int i = 0; i < n; ++i)
            {
                if (!used[i])
                {
                    u = i;
                    used[u] = true;
                    break;
                }
            }
            cout << "! " << u + 1 << endl;
            return 0;
        }
        int u = -1;
        for (int i = 0; i < n; ++i)
        {
            if (!used[i] && deg[i] == 1)
            {
                u = i;
                used[u] = true;
                break;
            }
        }
        int v = -1;
        for (int i = 0; i < n; ++i)
        {
            if (!used[i] && deg[i] == 1)
            {
                v = i;
                used[v] = true;
                break;
            }
        }
        cout << "? " << u + 1 << " " << v + 1 << endl;
        int ans;
        cin >> ans;
        --ans;
        if (ans == u)
        {
            cout << "! " << u + 1 << endl;
            return 0;
        }
        if (ans == v)
        {
            cout << "! " << v + 1 << endl;
            return 0;
        }
        deg[u] = 0;
        deg[v] = 0;
        for (auto w : g[u])
        {
            --deg[w];
        }
        for (auto w : g[v])
        {
            --deg[w];
        }
        cnt -= 2;
    }
    return 0;
}
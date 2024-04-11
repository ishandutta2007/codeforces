#include <bits/stdc++.h>

using namespace std;

#define int long long

const int mod = 1e9 + 7;

const int MAXN = 1e6 + 6;

int used[MAXN];

vector<vector<int>> g(MAXN);

void dfs(int u)
{
    used[u] = true;
    for (auto v : g[u])
    {
        if (!used[v])
        {
            dfs(v);
        }
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    int t;
    cin >> t;
    for (int _ = 0; _ < t; ++_)
    {
        int n;
        cin >> n;
        for (int i = 0; i < n; ++i)
        {
            used[i] = false;
            g[i] = {};
        }
        vector<int> a(n);
        vector<int> b(n);
        for (int i = 0; i < n; ++i)
        {
            cin >> a[i];
            --a[i];
        }
        for (int i = 0; i < n; ++i)
        {
            cin >> b[i];
            --b[i];
        }
        for (int i = 0; i < n; ++i)
        {
            g[a[i]].push_back(b[i]);
        }
        int cnt = 0;
        for (int i = 0; i < n; ++i)
        {
            if (!used[i])
            {
                dfs(i);
                ++cnt;
            }
        }
        int ans = 1;
        for (int i = 0; i < cnt; ++i)
        {
            ans *= 2;
            ans %= mod;
        }
        cout << ans << endl;
    }
    return 0;
}
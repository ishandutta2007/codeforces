#include <bits/stdc++.h>

using namespace std;

#define int long long

const int mod = 1e9 + 7;

const int MAXN = 2e5 + 25;

int used[MAXN];

vector<vector<int>> g(MAXN);

int cnt = 0;

void dfs(int u)
{
    ++cnt;
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
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(false);
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n - 1; ++i)
    {
        int u, v, x;
        cin >> u >> v >> x;
        --u; --v;
        if (x == 0)
        {
            g[u].push_back(v);
            g[v].push_back(u);
        }
    }
    int ans = 1;
    for (int i = 0; i < k; ++i)
    {
        ans *= n;
        ans %= mod;
    }
    for (int i = 0; i < n; ++i)
    {
        if (!used[i])
        {
            cnt = 0;
            dfs(i);
            int res = 1;
            for (int i = 0; i < k; ++i)
            {
                res *= cnt;
                res %= mod;
            }
            ans -= res;
            ans %= mod;
            ans += mod;
            ans %= mod;
        }
    }
    cout << ans << endl;
    return 0;
}
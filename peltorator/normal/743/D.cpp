#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

vector<ll> g[200001], a, d, used, best;

ll ans = -1e18;

int dfs(int v)
{
    used[v] = 1;
    d[v] = a[v];
    ll ans1 = -1e18, ans2 = -1e18;
    for (auto u : g[v])
        if (!used[u])
        {
            dfs(u);
            d[v] += d[u];
            best[v] = max(best[v], best[u]);
            if (best[u] >= ans1)
            {
                ans2 = ans1;
                ans1 = best[u];
            }
            else if (best[u] > ans2)
                ans2 = best[u];
        }
    best[v] = max(best[v], d[v]);
    if (ans1 > -1e17 && ans2 > -1e17)
        ans = max(ans, ans1 + ans2);
    return 0;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    a.resize(n + 1);
    d.resize(n + 1, 0);
    used.resize(n + 1, 0);
    best.resize(n + 1, -1e17);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i < n; i++)
    {
        int k, l;
        cin >> k >> l;
        g[k].push_back(l);
        g[l].push_back(k);
    }
    dfs(1);
    if (ans < -1e17)
        cout << "Impossible";
    else
        cout << ans;
    return 0;
}
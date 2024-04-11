#include <bits/stdc++.h>

using namespace std;

#define int long long

const int MAXN = 5e5 + 7;

const int mod = 998244353;
const int INF = 1e9 + 66;

vector<vector<pair<int, int>>> g(MAXN);

pair<int, int> dist[MAXN][2];

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); srand(clock());
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; ++i)
    {
        int u, v;
        cin >> u >> v;
        --u; --v;
        g[u].push_back({v, 0});
        g[v].push_back({u, 1});
    }
    set<pair<pair<int, int>, pair<int, int>>> s;
    s.insert({{0, 0}, {0, 0}});
    for (int i = 0; i < n; ++i)
    {
        dist[i][0] = {INF, 0};
        dist[i][1] = {INF, 0};
    }
    dist[0][0] = {0, 0};
    while (!s.empty())
    {
        auto pp = (*s.begin());
        auto u = pp.second.first;
        s.erase(s.begin());
        for (auto pr : g[u])
        {
            int v = pr.first;
            int tp = pr.second;
            pair<int, int> cur = {0, 0};
            if (tp == pp.second.second)
            {
                cur = {pp.first.first, pp.first.second + 1};
            }
            else
            {
                cur = {pp.first.first + 1, pp.first.second + 1};
            }
            if (cur < dist[v][tp])
            {
                s.erase({dist[v][tp], {v, tp}});
                dist[v][tp] = cur;
                s.insert({cur, {v, tp}});
            }
        }
    }
    int lg, val;
    if (dist[n - 1][0] < dist[n - 1][1])
    {
        lg = dist[n - 1][0].first;
        val = dist[n - 1][0].second - 1;
    }
    else
    {
        lg = dist[n - 1][1].first;
        val = dist[n - 1][1].second - 1;
    }
    if (lg >= 20)
    {
        int ans = 1;
        for (int i = 0; i < lg; ++i)
        {
            ans *= 2ll;
            ans %= mod;
        }
        ans += val;
        ans %= mod;
        ans += mod;
        ans %= mod;
        cout << ans << endl;
    }
    else
    {
        set<pair<pair<int, int>, pair<int, int>>> q;
        q.insert({{0, 0}, {0, 0}});
        for (int i = 0; i < n; ++i)
        {
            dist[i][0] = {INF, 0};
            dist[i][1] = {INF, 0};
        }
        dist[0][0] = {0, 0};
        while (!q.empty())
        {
            auto pp = (*q.begin());
            auto u = pp.second.first;
            q.erase(q.begin());
            for (auto pr : g[u])
            {
                int v = pr.first;
                int tp = pr.second;
                pair<int, int> cur = {0, 0};
                if (tp == pp.second.second)
                {
                    cur = {pp.first.first + 1, pp.first.second};
                }
                else
                {
                    cur = {pp.first.first + 1 + (1 << pp.first.second), pp.first.second + 1};
                }
                if (cur < dist[v][tp])
                {
                    q.erase({dist[v][tp], {v, tp}});
                    dist[v][tp] = cur;
                    q.insert({cur, {v, tp}});
                }
            }
        }
        int ans;
        if (dist[n - 1][0] < dist[n - 1][1])
        {
            ans = dist[n - 1][0].first;
        }
        else
        {
            ans = dist[n - 1][1].first;
            val = dist[n - 1][1].second - 1;
        }

        cout << ans << endl;
    }
    return 0;
}
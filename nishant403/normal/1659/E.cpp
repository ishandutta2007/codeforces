#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define S second
#define F first
#define f(i, n) for (int i = 0; i < n; i++)
#define fast                      \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0)
#define vi vector<int>
#define pii pair<int, int>
#define all(x) x.begin(), x.end()

class DSU
{
    int n;
    vector<int> root, sz;

public:
    DSU(int _n) : n(_n)
    {
        root.resize(n);
        sz.resize(n);
        for (int i = 0; i < n; i++)
        {
            root[i] = i;
            sz[i] = 1;
        }
    }

    int get_root(int u)
    {
        return (u == root[u] ? u : (root[u] = get_root(root[u])));
    }

    bool connected(int u, int v)
    {
        if (get_root(u) == get_root(v))
            return true;
        return false;
    }

    void merge(int u, int v)
    {
        if (connected(u, v))
            return;
        u = get_root(u);
        v = get_root(v);
        if (sz[v] > sz[u])
            swap(u, v);
        root[v] = u;
        sz[u] += sz[v];
    }

    int total_comp()
    {
        vector<int> mark(n, 0);
        int tot_component = 0;
        for (int i = 0; i < n; i++)
        {
            int u = get_root(i);
            if (!mark[u])
                tot_component++;
            mark[u] = 1;
        }
        return tot_component;
    }

    int comp_size(int u)
    {
        u = get_root(u);
        return sz[u];
    }

    int max_size_comp()
    {
        int max_sz = 0;
        for (int i = 0; i < n; i++)
            max_sz = max(max_sz, sz[get_root(i)]);
        return max_sz;
    }
};

const int N = 1e5 + 10;
vector<pii> g[N];

void solve()
{
    int n, m;
    cin >> n >> m;

    int u, v, w;

    vector<DSU> go0(30, DSU(n + 1));

    vector<DSU> go1(30, DSU(n + 2));

    f(i, m)
    {
        cin >> u >> v >> w;
        g[u].pb({v, w});
        g[v].pb({u, w});

        for (int j = 0; j < 30; j++)
        {
            if ((w >> j) & 1)
            {
                go0[j].merge(u, v);
                go1[j].merge(u, v);
            }
        }

        if (w % 2 == 0)
        {
            for (int j = 0; j < 30; j++)
            {
                go1[j].merge(u, n + 1);
                go1[j].merge(v, n + 1);
            }
        }
    }

    int q;
    cin >> q;

    while (q--)
    {
        cin >> u >> v;

        int ans = 2;

        for (int i = 0; i < 30; i++)
            if (go0[i].connected(u, v))
            {
                ans = 0;
                break;
            }

        if (ans == 0)
        {
            cout << 0 << '\n';
            continue;
        }

        // check for 1
        for (int i = 1; i < 30; i++)
            if (go1[i].connected(u, n + 1))
            {
                ans = 1;
                break;
            }

        cout << ans << '\n';
    }
}

signed main()
{
    fast;

    solve();
}
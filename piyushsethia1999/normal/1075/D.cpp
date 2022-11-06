#include <bits/stdc++.h>
#define pb emplace_back
#define mp make_pair

using namespace std;

int askB(int v)
{
    cout << "B " << v << endl;
    int y;
    cin >> y;
    return y;
}

int askA(int v)
{
    cout << "A " << v << endl;
    int y;
    cin >> y;
    return y;
}

int dfsnearest(std::vector<std::vector<int> >& adj, int u, int p, std::vector<bool>& vis)
{
    if (vis[u])
        return u;
    int y = -1;
    for (int v : adj[u])
        if (v != p)
            y = max(y, dfsnearest(adj, v, u, vis));
    return y;
}

int32_t main()
{
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        std::vector<std::vector<int> > adj(n + 1);
        std::vector<bool> v1(n + 1);
        std::vector<bool> v2(n + 1);
        for (int i = 0; i < n - 1; ++i)
        {
            int u, v;
            cin >> u >> v;
            adj[u].pb(v);
            adj[v].pb(u);
        }
        int k1;
        cin >> k1;
        for (int i = 0; i < k1; ++i)
        {
            int u;
            cin >> u;
            v1[u] = true;
        }
        int k2;
        cin >> k2;
        int vv = -1;
        for (int i = 0; i < k2; ++i)
        {
            int u;
            cin >> u;
            v2[u] = true;
            vv = u;
        }
        int u = askB(vv);
        if (v1[u])
        {
            cout << "C " << u << endl;
            continue;
        }
        vv = dfsnearest(adj, u, 0, v1);
        u = askA(vv);
        if (!v2[u])
            vv = -1;
        cout << "C " << vv << endl;
    }
}
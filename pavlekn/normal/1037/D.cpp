#include <bits/stdc++.h>

using namespace std;

#define int long long

const int INF = 2e9;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    vector<vector<int>> g(n);
    for (int i = 0; i < n - 1; ++i)
    {
        int u, v;
        cin >> u >> v;
        --u; --v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    vector<int> pos(n);
    vector<int> a(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
        pos[a[i] - 1] = i;
    }
    vector<int> used(n, 0);
    vector<int> dist(n, INF);
    vector<int> pp(n, -1);
    used[0] = 1;
    dist[0] = 0;
    deque<int> q;
    q.push_back(0);
    while (!q.empty())
    {
        int u = q.front();
        q.pop_front();
        for (auto v : g[u])
        {
            if (!used[v])
            {
                used[v] = 1;
                q.push_back(v);
                dist[v] = dist[u] + 1;
                pp[u] = v;
            }
        }
    }
    string ans = "Yes";
    for (int i = 0; i < n - 1; ++i)
    {
        if (dist[a[i] - 1] == dist[a[i + 1] - 1])
        {
            if (pp[a[i] - 1] != -1 && pp[a[i + 1] - 1] != -1 && pos[pp[a[i] - 1]] > pos[pp[a[i + 1] - 1]])
            {
                ans = "No";
            }
        }
        if (dist[a[i] - 1] == dist[a[i + 1] - 1] || (dist[a[i] - 1] + 1) == dist[a[i + 1] - 1])
        {

        }
        else
        {
            ans = "No";
        }
    }
    cout << ans << endl;
}
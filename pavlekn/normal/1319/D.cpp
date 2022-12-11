#include <bits/stdc++.h>

using namespace std;

#define int long long

const int MAXN = 2e5 + 77;

vector<vector<int>> g(MAXN);

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; ++i)
    {
        int u, v;
        cin >> u >> v;
        --u; --v;
        g[v].push_back(u);
    }
    int k;
    cin >> k;
    vector<int> v(k);
    for (int i = 0; i < k; ++i)
    {
        cin >> v[i];
        --v[i];
    }
    int s = v[0];
    int t = v[k - 1];
    vector<int> dist(n, MAXN);
    vector<int> cnt(n);
    cnt[t] = 1;
    dist[t] = 0;
    deque<int> q;
    q.push_back(t);
    while (!q.empty())
    {
        int u = q.front();
        q.pop_front();
        for (auto v : g[u])
        {
            if (dist[v] == dist[u] + 1)
            {
                cnt[v] += cnt[u];
            }
            if (dist[v] > dist[u] + 1)
            {
                q.push_back(v);
                dist[v] = dist[u] + 1;
                cnt[v] = cnt[u];
            }
        }
    }
    int mn = 0;
    int mx = 0;
    for (int i = k - 2; i >= 0; --i)
    {
        if (dist[v[i]] <= dist[v[i + 1]])
        {
            ++mn;
            ++mx;
        }
        else if (dist[v[i]] == dist[v[i + 1]] + 1 && cnt[v[i]] == cnt[v[i + 1]])
        {

        }
        else
        {
            ++mx;
        }
    }
    cout << mn << " " << mx << endl;
    return 0;
}
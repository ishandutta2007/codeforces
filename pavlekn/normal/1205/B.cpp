#include<bits/stdc++.h>

using namespace std;

#define int long long

const int MAXN = 1003;

int mat[MAXN][MAXN];

const int INF = 1e9;

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }
    vector<vector<int>> b(63);
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < 63; ++j)
        {
            if (a[i] & (1ll << j))
            {
                b[j].push_back(a[i]);
                if (b[j].size() >= 3)
                {
                    cout << 3 << endl;
                    return 0;
                }
            }
        }
    }
    vector<int> g;
    for (int i = 0; i < n; ++i)
    {
        if (a[i])
        {
            g.push_back(a[i]);
        }
    }
    n = g.size();
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            if (i == j)
            {
                continue;
            }
            if (g[i] & g[j])
            {
                mat[i][j] = true;
            }
        }
    }
    int ans = INF;
    for (int i = 0; i < n; ++i)
    {
        vector<int> dist(n, INF);
        vector<int> p(n);
        vector<int> used(n);
        used.push_back(i);
        dist[i] = 0;
        p[i] = i;
        used[i] = true;
        deque<int> q;
        q.push_back(i);
        while (!q.empty())
        {
            int u = q.front();
            q.pop_front();
            used[u] = true;
            for (int v = 0; v < n; ++v)
            {
                if (mat[u][v] && v != p[u])
                {
                    if (!used[v])
                    {
                        p[v] = u;
                        dist[v] = dist[u] + 1;
                        q.push_back(v);
                    }
                    else
                    {
                        ans = min(ans, dist[u] + dist[v] + 1);
                    }
                }
            }
        }
    }
    if (ans == INF)
    {
        cout << -1 << endl;
    }
    else
    {
        cout << ans << endl;
    }
    return 0;
}
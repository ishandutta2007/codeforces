#include <bits/stdc++.h>

using namespace std;

#define int long long

const int INF = 1e9;

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0); srand(clock());
    int t;
    cin >> t;
    for (int iii = 0; iii < t; ++iii)
    {
        int n;
        cin >> n;
        vector<vector<int>> g(n);
        int u, v;
        for (int i = 0; i < n - 1; ++i)
        {
            cin >> u >> v;
            --u;
            --v;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        int k1;
        cin >> k1;
        set<int> s1;
        for (int i = 0; i < k1; ++i)
        {
            cin >> u;
            --u;
            s1.insert(u);
        }
        int k2;
        cin >> k2;
        set<int> s2;
        for (int i = 0; i < k2; ++i)
        {
            cin >> u;
            s2.insert(u);
        }
        int num;
        cout << "B " << (*s2.begin()) << endl;
        cin >> num;
        --num;
        if (s1.find(num) != s1.end())
        {
            cout << "C " << (num + 1) << endl;
            continue;
        }
        vector<int> dist(n, INF);
        dist[num] = 0;
        deque<int> q;
        q.push_back(num);
        int ans = 0;
        while (!q.empty())
        {
            int u = q.front();
            q.pop_front();
            if (s1.find(u) != s1.end())
            {
                ans = u;
                break;
            }
            for (auto v : g[u])
            {
                if (dist[v] == INF)
                {
                    dist[v] = dist[u] + 1;
                    q.push_back(v);
                }
            }
        }
        cout << "A " << (ans + 1) << endl;
        cin >> num;
        if (s2.find(num) != s2.end())
        {
            cout << "C " << (ans + 1) << endl;
        }
        else
        {
            cout << "C " << -1 << endl;
        }
    }
    return 0;
}
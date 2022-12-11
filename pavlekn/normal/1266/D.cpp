#include<bits/stdc++.h>

using namespace std;

#define int long long

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<int> deg(n);
    for (int i = 0; i < m; ++i)
    {
        int u, v, d;
        cin >> u >> v >> d;
        --u; --v;
        deg[u] -= d;
        deg[v] += d;
    }
    set<pair<int, int>> s;
    for (int i = 0; i < n; ++i)
    {
        s.insert({deg[i], i});
    }
    vector<int> ans1;
    vector<int> ans2;
    vector<int> ans3;
    while (!s.empty())
    {
        int u = s.begin()->second;
        int v = (s.rbegin())->second;
        if (deg[u] == 0)
        {
            break;
        }
        else
        {
            int t = min(abs(deg[u]), abs(deg[v]));
            s.erase({deg[u], u});
            s.erase({deg[v], v});
            deg[u] += t;
            deg[v] -= t;
            s.insert({deg[u], u});
            s.insert({deg[v], v});
            ans1.push_back(u + 1);
            ans2.push_back(v + 1);
            ans3.push_back(t);
        }
    }
    cout << ans1.size() << endl;
    for (int i = 0; i < ans1.size(); ++i)
    {
        cout << ans1[i] << " " << ans2[i] << " " << ans3[i] << endl;
    }
    return 0;
}
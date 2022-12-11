#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e3 + 23;

const int INF = 2e9 + 118;

unordered_map<int, vector<int>> num;

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    set<int> b;
    for (int i = 0; i < 6; ++i)
    {
        int x;
        cin >> x;
        b.insert(-x);
    }
    int n;
    cin >> n;
    vector<int> pos(n);
    set<int> s;
    set<pair<int, int>> t;
    vector<vector<int>> a(n);
    for (int i = 0; i < n; ++i)
    {
        int x;
        cin >> x;
        for (auto el : b)
        {
            a[i].push_back(x + el);
            num[x + el].push_back(i);
            s.insert(x + el);
        }
        t.insert({a[i][0], i});
        pos[i] = 0;
        a[i].push_back(INF);
    }
    int ans = INF;
    for (auto el : s)
    {
        ans = min(ans, t.rbegin()->first - el);
        for (auto u : num[el])
        {
            t.erase({a[u][pos[u]], u});
            ++pos[u];
            t.insert({a[u][pos[u]], u});
        }
    }
    cout << ans << endl;
    return 0;
}
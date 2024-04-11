#include <bits/stdc++.h>

using namespace std;

const int N = 100010;

int n, m;
long long a[N];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        a[u] += w;
        a[v] -= w;
    }
    set<pair<long long, int>> s;
    for (int i = 1; i <= n; i++) {
        if (a[i] != 0) s.insert({a[i], i});
    }
    vector<tuple<int, int, long long>> res;
    while (!s.empty()) {
        assert(s.size() >= 2);
        auto u = *s.begin();
        auto v = *s.rbegin();
        s.erase(u);
        s.erase(v);
        long long val = min(-u.first, v.first);
        u.first += val;
        v.first -= val;
        if (u.first) s.insert(u);
        if (v.first) s.insert(v);
        res.push_back({v.second, u.second, val});
    }
    cout << res.size() << endl;
    for (auto u : res) {
        int x, y;
        long long z;
        tie(x, y,z) = u;
        cout << x << ' ' << y << ' ' << z << '\n';
    }
    return 0;
}
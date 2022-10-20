#include <bits/stdc++.h>

using namespace std;

const int N = 500010;

int n;
set<pair<int, int>> h;
vector<int> adj[N];
set<pair<int, int>> s[N];
int root[N];
vector<tuple<int, int, int, int>> res;

int getRoot(int u) {
    return root[u] < 0 ? u : root[u] = getRoot(root[u]);
}

void join(int u, int v) {
    u = getRoot(u);
    v = getRoot(v);
    assert(u != v);
    if (s[u].size() < s[v].size()) swap(u, v);
    root[u] += root[v];
    root[v] = u;
    for (auto val : s[v]) s[u].insert(val);
}

void plug(int u, int x, int y) {
    u = getRoot(u);
    assert(!s[u].empty());
    auto val = *s[u].begin();
    s[u].erase(s[u].begin());
    int v = getRoot(val.second);
    assert(s[v].count({val.second, val.first}));
    s[v].erase({val.second, val.first});
    join(u, v);
    res.push_back({x, y, val.first, val.second});
}

void dfs(int u, int p) {
    for (int v : adj[u]) {
        if (v == p) continue;
        dfs(v, u);
        if (h.count({u, v})) {
            s[getRoot(u)].erase({u, v});
            s[getRoot(v)].erase({v, u});
            join(u, v);
        } else {
            plug(v, u, v);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        h.insert({u, v});
        h.insert({v, u});
        s[u].insert({u, v});
        s[v].insert({v, u});
    }
    memset(root, -1, sizeof root);
    dfs(1, 0);
    cout << res.size() << endl;
    for (auto u : res) {
        cout << get<0>(u) << ' ' << get<1>(u) << ' ' << get<2>(u) << ' ' << get<3>(u) << '\n';
    }
    return 0;
}
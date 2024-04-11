#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 1e5 + 5;
const int MAX_LG = 20;

namespace DSU {
    int p[MAX_N], r[MAX_N];
    void init(int n) { iota(p, p + n + 1, 0); fill_n(r, n + 1, 0); }
    int find(int x) { return x == p[x] ? x : (p[x] = find(p[x])); }
    bool union_(int x, int y) {
        x = find(x), y = find(y);
        if (x == y) return 0;
        if (r[x] < r[y]) swap(x, y);
        p[y] = x;
        r[x] += r[x] == r[y];
        return 1;
    }
}

int n, m;
vector<array<int, 2>> g[MAX_N];
int anc[MAX_LG][MAX_N], dep[MAX_N];
int dist[MAX_LG][MAX_N];

void dfs(int u) {
    for (int i = 1; i < MAX_LG; i++) {
        anc[i][u] = anc[i - 1][anc[i - 1][u]];
        dist[i][u] = max(dist[i - 1][u],  dist[i - 1][anc[i - 1][u]]);
    }
    for (auto& e : g[u]) if (e[0] != anc[0][u]) {
        anc[0][e[0]] = u;
        dist[0][e[0]] = e[1];
        dep[e[0]] = dep[u] + 1;
        dfs(e[0]);
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int n, m; cin >> n >> m;
    vector<array<int, 3>> ed(m);
    for (auto &e : ed)
        cin >> e[0] >> e[1] >> e[2];

    vector<int> idx(m); iota(idx.begin(), idx.end(), 0);
    sort(idx.begin(), idx.end(), [&](int i, int j) { return ed[i][2] < ed[j][2]; });
    DSU::init(n);
    vector<int> q;
    for (int i : idx) {
        auto &e = ed[i];
        if (DSU::union_(e[0], e[1])) {
            g[e[0]].push_back({e[1], e[2]});
            g[e[1]].push_back({e[0], e[2]});
        } else {
            q.push_back(i);
        }
    }

    anc[0][1] = 1;
    dfs(1);

    sort(q.begin(), q.end());
    for (int i : q) {
        int u = ed[i][0], v = ed[i][1];
        if (dep[u] > dep[v]) swap(u, v);
        int ans = 0;
        for (int i = MAX_LG - 1; i >= 0; i--) if (dep[v] - (1 << i) >= dep[u]) {
            ans = max(ans, dist[i][v]);
            v = anc[i][v];
        }
        if (u != v) {
            for (int i = MAX_LG - 1; i >= 0; i--) if (anc[i][u] != anc[i][v]) {
                ans = max(ans, max(dist[i][u], dist[i][v]));
                u = anc[i][u], v = anc[i][v];
            }
            ans = max(ans, max(dist[0][u], dist[0][v]));
        }
        cout << ans << "\n";
    }

    return 0;
}
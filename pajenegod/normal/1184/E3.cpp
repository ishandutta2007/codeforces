#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 1e5 + 5;
const int MAX_M = 1e6 + 5;
const int MAX_LG = 20;
const int MAX_W = 1e9;

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
int anc[MAX_LG][MAX_N], dep[MAX_N], mxw[MAX_LG][MAX_N], mnw[MAX_LG][MAX_N];
bool on_mst[MAX_M];
int ans[MAX_M];

void dfs(int u) {
    mnw[0][u] = MAX_W;
    for (int i = 1; i < MAX_LG; i++) {
        anc[i][u] = anc[i - 1][anc[i - 1][u]];
        mxw[i][u] = max(mxw[i - 1][u],  mxw[i - 1][anc[i - 1][u]]);
        mnw[i][u] = MAX_W;
    }
    for (auto& e : g[u]) if (e[0] != anc[0][u]) {
        anc[0][e[0]] = u;
        mxw[0][e[0]] = e[1];
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
    for (int i : idx) {
        auto &e = ed[i];
        if (on_mst[i] = DSU::union_(e[0], e[1])) {
            g[e[0]].push_back({e[1], e[2]});
            g[e[1]].push_back({e[0], e[2]});
        }
    }

    anc[0][1] = 1;
    dfs(1);

    for (int i = 0; i < m; i++) if (!on_mst[i]) {
        int u = ed[i][0], v = ed[i][1], w = ed[i][2];
        if (dep[u] > dep[v]) swap(u, v);
        int res = 0;
        for (int i = MAX_LG - 1; i >= 0; i--) if (dep[v] - (1 << i) >= dep[u]) {
            res = max(res, mxw[i][v]);
            mnw[i][v] = min(mnw[i][v], w);
            v = anc[i][v];
        }
        if (u != v) {
            for (int i = MAX_LG - 1; i >= 0; i--) if (anc[i][u] != anc[i][v]) {
                res = max(res, max(mxw[i][u], mxw[i][v]));
                mnw[i][v] = min(mnw[i][v], w), mnw[i][u] = min(mnw[i][u], w);
                u = anc[i][u], v = anc[i][v];
            }
            res = max(res, max(mxw[0][u], mxw[0][v]));
            mnw[0][v] = min(mnw[0][v], w), mnw[0][u] = min(mnw[0][u], w);
        }
        ans[i] = res;
    }

    for (int i = MAX_LG - 1; i > 0; i--) {
        for (int u = 1; u <= n; u++) {
            mnw[i - 1][u] = min(mnw[i - 1][u], mnw[i][u]);
            mnw[i - 1][anc[i - 1][u]] = min(mnw[i - 1][anc[i - 1][u]], mnw[i][u]);
        }
    }

    for (int i = 0; i < m; i++) {
        if (!on_mst[i]) cout << ans[i];
        else {
            int u = ed[i][0], v = ed[i][1];
            if (dep[u] > dep[v]) swap(u, v);
            cout << mnw[0][v];
        }
        cout << "\n";
    }

    return 0;
}
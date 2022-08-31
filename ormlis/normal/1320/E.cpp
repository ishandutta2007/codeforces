#include <bits/stdc++.h>

#define range(i, n) for(int i = 0; i < (n); ++i)
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define ar array

typedef long long ll;

using namespace std;
const int maxN = 2e5 + 100;


vector<int> g[maxN];
int up[maxN][20];
int tin[maxN], tout[maxN];
int h[maxN];
int T = 0;

void dfs(int v, int p) {
    up[v][0] = p;
    tin[v] = T++;
    for (int i = 1; i < 20; ++i) up[v][i] = up[up[v][i - 1]][i - 1];
    for (auto &u : g[v]) {
        if (u == p) continue;
        h[u] = h[v] + 1;
        dfs(u, v);
    }
    tout[v] = T++;
}

bool is_parent(int v, int p) {
    return tin[p] <= tin[v] && tout[v] <= tout[p];
}

int lca(int v, int u) {
    if (h[v] < h[u]) swap(u, v);
    for (int i = 19; i >= 0; --i) {
        if (h[up[v][i]] >= h[u]) v = up[v][i];
    }
    if (u == v) return v;
    for (int i = 19; i >= 0; --i) {
        if (up[v][i] != up[u][i]) v = up[v][i], u = up[u][i];
    }
    return up[v][0];
}

int dist(int a, int b) {
    return h[a] + h[b] - 2 * h[lca(a, b)];
}


vector<pair<int, int>> g2[maxN];

int n;

void solve_event() {
    int k, m;
    cin >> k >> m;
    vector<int> v(k), s(k);
    range(i, k) cin >> v[i] >> s[i];
    vector<int> u(m);
    range(i, m) cin >> u[i];
    auto a = u;
    range(i, k) a.push_back(v[i]);
    sort(all(a), [&](const int i, const int j) {
        return tin[i] < tin[j];
    });
    a.resize(unique(all(a)) - a.begin());
    int SZ = a.size();
    for(int i = 0; i + 1 < SZ; ++i) {
        int l = lca(a[i], a[i + 1]);
        a.push_back(l);
    }
    sort(all(a), [&](const int i, const int j) {
        return tin[i] < tin[j];
    });
    a.resize(unique(all(a)) - a.begin());
    for (auto &x : a) {
        g2[x].clear();
    }
    vector<int> stk;
    for (auto &x : a) {
        while (!stk.empty() && !is_parent(x, stk.back())) stk.pop_back();
        if (!stk.empty()) {
            int d = h[x] - h[stk.back()];
            g2[x].emplace_back(stk.back(), d);
            g2[stk.back()].emplace_back(x, d);
        }
        stk.push_back(x);
    }
    set<ar<int, 3>> q;
    map<int, ar<int, 3>> d;
    range(i, k) {
        d[v[i]] = {0, i, s[i]};
        q.insert({0, i, v[i]});
    }
    while (!q.empty()) {
        auto[step, j, t] = *q.begin();
        q.erase(q.begin());
        int ost = s[j] - d[t][2];
        for (auto &[to, w] : g2[t]) {
            int D = w - ost;
            int step2 = step;
            int p2 = 0;
            if (D <= 0) {
                p2 = s[j] + D;
            } else {
                step2 += (D + s[j] - 1) / s[j];
                p2 = D % s[j];
                if (p2 == 0) p2 = s[j];
            }
            if (!d.count(to)) {
                d[to] = {step2, j, p2};
                q.insert({step2, j, to});
                continue;
            }
            if (d[to] > ar<int, 3>{step2, j, p2}) {
                q.erase({d[to][0], d[to][1], to});
                d[to] = {step2, j, p2};
                q.insert({step2, j, to});
            }
        }
    }
    range(i, m) {
        cout << d[u[i]][1] + 1 << ' ';
    }
    cout << '\n';
}

void solve() {
    cin >> n;
    range(_, n - 1) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1, -1);
    int q; cin >> q;
    range(_, q) {
        solve_event();
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tests = 1;
    range(_, tests) {
        solve();
    }
    return 0;
}
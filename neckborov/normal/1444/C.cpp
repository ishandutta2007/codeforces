// #pragma GCC optimize("O3")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx")
#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;

const int N = 5e5 + 5;

vector<pair<int*, int>> changes;
int p[N], sz[N], col[N];

int getRoot(int v) {
    return v == p[v] ? v : getRoot(p[v]);
}
int getColor(int v) {
    return v == p[v] ? 0 : col[v] ^ getColor(p[v]);
}

bool unite(int v, int u, int rollback = 1) {
    int pv = getRoot(v);
    int pu = getRoot(u);
    if (pv == pu) {
        return getColor(v) != getColor(u);
    }
    if (sz[pv] < sz[pu]) {
        swap(v, u);
        swap(pv, pu);
    }
    if (rollback) {
        changes.emplace_back(p + pu, p[pu]);
        changes.emplace_back(sz + pv, sz[pv]);
    }

    p[pu] = pv;
    sz[pv] += sz[pu];
    if (getColor(v) == getColor(u)) {
        if (rollback) {
            changes.emplace_back(col + pu, col[pu]);
        }
        col[pu] ^= 1;
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m, k;
    cin >> n >> m >> k;
    iota(p, p + n, 0);
    fill(sz, sz + n, 1);
    vector<int> c(n);
    for (int i = 0; i < n; i++) {
        cin >> c[i];
        c[i]--;
    }
    vector<pair<int, int>> edges(m);
    for (int i = 0; i < m; i++) {
        cin >> edges[i].first >> edges[i].second;
        edges[i].first--;
        edges[i].second--;
        if (c[edges[i].first] < c[edges[i].second]) {
            swap(edges[i].first, edges[i].second);
        }
    }
    sort(edges.begin(), edges.end(), [&](auto a, auto b) {
        int x = c[a.first] - c[a.second];
        int y = c[b.first] - c[b.second];
        return x < y || x == y && c[a.first] < c[b.first];
    });
    bool ok = true;
    vector<int> good(k, 1);
    int tot = k;
    int last = 0;
    for (int i = 0; i < m && c[edges[i].first] == c[edges[i].second]; i++) {
        ok &= unite(edges[i].first, edges[i].second, 0);
        if (i + 1 == m || c[edges[i].first] != c[edges[i + 1].first]) {
            if (!ok) {
                good[c[edges[i].first]] = 0;
                tot--;
            }
            ok = true;
        }
        last = i;
    }
    ll ans = 1LL * tot * (tot - 1) / 2;
    int x, y;
    ok = true;
    for (int i = last + 1; i < m; i++) {
        tie(x, y) = edges[i];
        if (!good[c[x]] || !good[c[y]]) {
            continue;
        }
        ok &= unite(x, y);
        if (i + 1 == m || c[x] != c[edges[i + 1].first] || c[y] != c[edges[i + 1].second]) {
            if (!ok) {
                ans--;
            }
            while (!changes.empty()) {
                *(changes.back().first) = changes.back().second;
                changes.pop_back();
            }
            ok = true;
        }
    }
    cout << ans << endl;
    return 0;
}
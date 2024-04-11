#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <iomanip>
#include <queue>
#include <cassert>
#include <bitset>

using namespace std;

#define debug(x) cout << #x << " is " << x << '\n';
#define ld long double
#define int long long

const int mod = 1e9 + 7, p = 239, N = 2e5 + 5;

int F = 0;

struct edge {
    int f, c, w;
    edge(int c = 0, int w = 0) :
        f(0), c(c), w(w) {}
    int left() {
        return c - f;
    }
};

vector <edge> edges;
vector <vector <pair <int, int>>> g;

int make(int c, int w) {
    edges.push_back(edge(c, w));
    return edges.size() - 1;
}

void add(int u, int v, int c, int w) {
    g[u].push_back({ v, make(c, w) });
    g[v].push_back({ u, make(0, -w) });
}

pair <int, int> Bellman(int S, int T, int n) {
    vector <int> d(n, mod), p(n, S), e(n), f(n);
    d[S] = 0;
    f[S] = mod;
    while (true) {
        bool changed = false;
        for (int i = 0; i < n; ++i) {
            for (auto& x : g[i]) {
                if (!edges[x.second].left()) continue;
                if (edges[x.second].w + d[i] < d[x.first]) {
                    d[x.first] = edges[x.second].w + d[i];
                    changed = true;
                    p[x.first] = i;
                    e[x.first] = x.second;
                    f[x.first] = min(f[i], edges[x.second].left());
                }
            }
        }
        if (!changed) break;
    }
    int cur = T, flow = f[T], cost = 0;
    if (!flow) return { 0, 0 };
    while (cur != S) {
        cost += edges[e[cur]].w;
        cur = p[cur];
    }
    int l = 0, r = flow + 1;
    while (l + 1 < r) {
        int m = (l + r) / 2;
        if (cost * m <= F) l = m;
        else r = m;
    }
    flow = l;
    cur = T;
    cost *= flow;
    while (cur != S) {
        edges[e[cur]].f += flow;
        edges[e[cur] ^ 1].f -= flow;
        cur = p[cur];
    }
    return { flow, cost };
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout << fixed << setprecision(6);
    
    int n; cin >> n >> F;
    g.resize(n);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            int x; cin >> x;
            if (!x) continue;
            add(i, j, x, 0);
            add(i, j, mod, 1);
        }
    }

    int ans = 0;
    while (true) {
        auto got = Bellman(0, n - 1, n);
        if (!got.first) break;
        F -= got.second;
        ans += got.first;
    }

    cout << ans << '\n';

    return 0;
}
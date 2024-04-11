#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>

#define range(i, n) for (int i = 0; i < (n); ++i)
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define ar array
using namespace std;

// using namespace __gnu_pbds;
/*
typedef tree<
int,
null_type,
less<int>,
rb_tree_tag,
tree_order_statistics_node_update>
ordered_set;
*/

typedef long long ll;
typedef double ld;
typedef unsigned long long ull;

const int INFi = 1e9 + 5;
const int maxN = 2e5 + 5;
const int md = 998244353;
const ll INF = 2e18;

double getTime() { return clock() / (double) CLOCKS_PER_SEC; }

struct Dinic {
    struct Edge {
        int u, c, f;
    };
    vector<Edge> edges;
    vector<vector<int>> g;
    vector<int> nxt, d;
    int s, t, n;

    void build(int k) {
        n = k;
        g.resize(n);
        nxt.resize(n);
        d.resize(n);
    }

    void add_edge(int v, int u, int c) {
        int i = (int) edges.size();
        g[v].push_back(i);
        g[u].push_back(i + 1);
        edges.push_back({u, c, 0});
        edges.push_back({v, 0, 0});
    }

    void set_s(int v) {
        s = v;
    }

    void set_t(int v) {
        t = v;
    }

    bool bfs(int low) {
        d.assign(n, INFi);
        d[s] = 0;
        queue<int> q;
        q.push(s);
        while (!q.empty()) {
            int v = q.front();
            q.pop();
            for (auto &i : g[v]) {
                Edge &e = edges[i];
                if (low <= e.c - e.f && d[e.u] == INFi) {
                    q.push(e.u);
                    d[e.u] = d[v] + 1;
                }
            }
        }
        return d[t] != INFi;
    }

    int dfs(int v, int min_c, int low) {
        if (v == t) return min_c;
        for (int &i = nxt[v], j = g[v][i]; i < (int) g[v].size(); ++i, j = g[v][i]) {
            Edge &e = edges[j];
            int f;
            if (low <= e.c - e.f && d[e.u] == d[v] + 1 &&
                (f = dfs(e.u, min(min_c, e.c - e.f), low))) {
                e.f += f;
                edges[j ^ 1].f -= f;
                return f;
            }
        }
        return 0;
    }

    ll find_max_flow() {
        ll res = 0;
        for (int low = 1 << 30; low >= 1; low >>= 1) {
            while (bfs(low)) {
                nxt.assign(n, 0);
                while (int f = dfs(s, INFi, low)) {
                    res += f;
                }
            }
        }
        return res;
    }
};

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> b(n);
    range(i, n) cin >> a[i];
    range(i, n) cin >> b[i];
    vector<int> to(101, -1);
    Dinic d;
    d.build(n + 2);
    int s = n;
    int t = n + 1;
    d.set_s(s);
    d.set_t(t);
    ll res = 0;
    range(i, n) {
        if (b[i] >= 0) {
            res += b[i];
            d.add_edge(s, i, b[i]);
        } else {
            d.add_edge(i, t, -b[i]);
        }
        for (int j = 1; j <= 100; ++j) {
            if (a[i] % j == 0 && to[j] != -1) {
                d.add_edge(i, to[j], INFi);
            }
        }
        to[a[i]] = i;
    }
    cout << res - d.find_max_flow() << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    // cout << setprecision(15) << fixed;
    int tests = 1;
//    cin >> tests;
    range(_, tests) {
        solve();
    }
    return 0;
}
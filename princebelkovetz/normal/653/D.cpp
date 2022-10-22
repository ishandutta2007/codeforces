#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <string>
#include <cmath>
#include <set>
#include <stack>
#include <map>
#include <unordered_map>
#include <queue>
#include <iterator>
#include <sstream>
#include <cassert>
#include <locale>
#include <numeric>
#include <random>
#include <bitset>

#define int long long
#define ld long double
#define debug(x) cout << #x << " is " << x << '\n';

using namespace std;
const int root = 212, mod = 1e9 + 7, L = 62, N = 503, LIMIT = 1e18;

struct edge {
    int c, f;
    edge(int c, int f) : c(c), f(f) {}
    int left() {
        return c - f;
    }
};

vector <edge> edges;
vector <vector <pair <int, int>>> g;
vector <bool> used;
int make(int c) {
    edges.push_back(edge(c, 0));
    return edges.size() - 1;
}

void add(int u, int v, int w) {
    g[u].push_back({ v, make(w) });
    g[v].push_back({ u, make(0) });
}

int dfs(int v, int t, int x) {
    if (t == v) return x;
    used[v] = true;
    for (auto& u : g[v]) if (!used[u.first] and edges[u.second].left()) {
        int got = dfs(u.first, t, min(x, edges[u.second].left()));
        if (got) {
            edges[u.second].f += got, edges[u.second ^ 1].f -= got;
            return got;
        }
    }
    return 0;
}

int n, m, x;
int maxFlow() {
    int res = 0, flow = 0;
    used.assign(n + 1, false);
    while (true) {
        res = dfs(1, n, mod);
        if (!res) break;
        flow += res;
        used.assign(n + 1, false);
    }
    return flow >= x;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(8);

    cin >> n >> m >> x;
    vector <vector <int>> es(m, vector <int>(3));
    for (auto& x : es)
        for (auto& y : x) cin >> y;
    ld l = 0, r = mod;
    for (int its = 0; its < 150; ++its) {
        ld mid = (l + r) / 2;
        g.assign(n + 1, {});
        edges.clear();
        for (auto& x : es) {
            add(x[0], x[1], floor(x[2] / mid));
        }
        if (maxFlow()) l = mid;
        else r = mid;
    }

    cout << l * x << '\n';

    return 0;
}
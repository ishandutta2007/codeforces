#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <cmath>
#include <set>
#include <stack>
#include <map>
#include <cassert>
#include <numeric>

#define int long long
#define ld long double
#define debug(x) cout << #x << " is " << x << '\n';

using namespace std;
const int root = 212, mod = 1e18 + 7, N = 5e5 + 2, L = 30;

vector <vector <pair <int, int>>> g;
vector <int> ok;

struct DisjointSet {
    vector <int> p, h;
    DisjointSet(int n = 0) {
        p.resize(n);
        h.resize(n);
        iota(p.begin(), p.end(), 0);
    }
    int get(int a) {
        return p[a] = p[a] == a ? a : get(p[a]);
    }
    void unite(int a, int b) {
        a = get(a), b = get(b);
        p[a] = b;
        h[b] |= h[a];
    }
    bool same(int a, int b) {
        return get(a) == get(b);
    }
    bool have(int a) {
        return h[get(a)];
    }
};

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(6);

    int n, m; cin >> n >> m;
    g.resize(n + 1);
    ok.resize(n + 1);
    for (int i = 0, u, v, w; i < m; ++i) {
        cin >> u >> v >> w;
        g[u].push_back({ v, w });
        g[v].push_back({ u, w });
        if (w & 1 ^ 1)
            ok[u] = ok[v] = 1;
    }
    vector <DisjointSet> dsu(L, DisjointSet(n + 1));
    for (int i = 0; i < L; ++i) {
        for (int v = 1; v <= n; ++v)
            dsu[i].h[v] = ok[v];
        for (int v = 1; v <= n; ++v) {
            for (auto [u, w] : g[v]) {
                if (w & (1ll << i))
                    dsu[i].unite(u, v);
            }
        }
    }
    int q; cin >> q;
    while (q--) {
        int u, v; cin >> u >> v;
        bool canZero = false;
        for (int i = 0; i < 30; ++i)
            if (dsu[i].same(u, v)) canZero = true;
        bool canOne = false;
        for (int i = 1; i < 30; ++i)
            if (dsu[i].have(u)) canOne = true;
        bool canTwo = true;
        if (canZero) cout << "0\n";
        else if (canOne) cout << "1\n";
        else if (canTwo) cout << "2\n";
        else cout << "1337\n";
    }


    return 0;
}
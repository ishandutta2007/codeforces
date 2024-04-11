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

struct mint {
    int x;
    mint(int x = 0) : x (x % mod) {}
    mint operator+(mint a) const {
        int res = x + a.x;
        if (res >= mod) return res - mod;
        return res;
    }
    mint operator-(mint a) const {
        int res = x - a.x;
        if (res < 0) return res + mod;
        return res;
    }
    mint operator*(mint a) const {
        return x * a.x % mod;
    }
    bool operator==(mint a) const {
        return x == a.x;
    }
    mint bpow(int b) {
        if (b == 0) return 1;
        if (b & 1) return (*this).bpow(b - 1) * x;
        mint t = (*this).bpow(b / 2);
        return t * t;
    }
    mint operator/(mint a) const {
        return (*this) * a.bpow(mod - 2);
    }
    friend istream& operator>>(istream& in, mint& a) {
        return in >> a.x;
    }
    friend ostream& operator<<(ostream& out, const mint& a) {
        return out << a.x;
    }
};

struct Sparse {
    vector <vector <int>> t;
    vector <int> d, euler, tin, tout, lg;
    Sparse(vector <vector <int>>& g) {
        int n = g.size();
        d.resize(n);
        tin.resize(n);
        tout.resize(n);

        dfs(1, -1, g);

        int l = 1, m = euler.size();
        lg.resize(m + 1);
        while ((1ll << l) < m) l++;
        l++;

        for (int i = 2; i <= m; ++i)
            lg[i] = lg[i / 2] + 1;

        t.resize(l, vector <int>(m));
        t[0] = euler;
        for (int i = 1; i < l; ++i) {
            for (int j = 0; j < m - (1ll << (i - 1)); ++j) {
                int v = t[i - 1][j], u = t[i - 1][j + (1ll << (i - 1))];
                t[i][j] = (d[v] < d[u] ? v : u);
            }
        }
    }

    void dfs(int v, int p, vector <vector <int>>& g) {
        tin[v] = euler.size();
        euler.push_back(v);
        for (auto u : g[v]) {
            if (u == p) continue;
            d[u] = d[v] + 1;
            dfs(u, v, g);
            euler.push_back(v);
        }
        tout[v] = euler.size();
    }

    int lca(int v, int u) {
        int l = min(tin[u], tin[v]), r = max(tout[u], tout[v]);
        int lgr = lg[r - l];
        int v1 = t[lgr][l], v2 = t[lgr][r - (1ll << lgr)];
        return d[v1] < d[v2] ? v1 : v2;
    }

    int dist(int u, int v) {
        int w = lca(u, v);
        return d[u] + d[v] - 2 * d[w];
    }

};


signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout << fixed << setprecision(6);

    int n; cin >> n;
    vector <vector <int>> g(n + 1);
    vector <vector <mint>> F(n + 1, vector <mint>(n + 1));
    for (int i = 0, u, v; i < n - 1; ++i) {
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);

    }
    for (int i = 1; i <= n; ++i)
        F[0][i] = 1, F[i][0] = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            F[i][j] = (F[i - 1][j] + F[i][j - 1]) / 2;
        }
    }

    Sparse table(g);

    mint ans = 0;

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            for (int k = j + 1; k <= n; ++k) {
                int l1 = table.lca(i, j);
                int l2 = table.lca(i, k);
                int l3 = table.lca(j, k);
                int ll = l1 ^ l2 ^ l3;
                int d1 = table.dist(k, ll), d2 = table.dist(j, ll);
                ans = ans + F[d1][d2];
            }
        }
    }

    cout << ans / n << '\n';

    return 0;
}
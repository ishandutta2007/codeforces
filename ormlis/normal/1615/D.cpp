#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
#define rep1n(i, n) for (int i = 1; i <= (n); ++i)
#define repr(i, n) for (int i = (n) - 1; i >= 0; --i)
#define pb push_back
#define eb emplace_back
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define sz(a) (int)(a.size())
#define each(x, a) for (auto &x : a)
#define ar array
#define vec vector
#define range(i, n) rep(i, n)

using namespace std;

using ll = long long;
using ld = long double;
using str = string;
using pi = pair<int, int>;
using pl = pair<ll, ll>;

using vi = vector<int>;
using vl = vector<ll>;
using vpi = vector<pair<int, int>>;
using vvi = vector<vi>;

int Bit(int mask, int b) { return (mask >> b) & 1; }

template<class T>
bool ckmin(T &a, const T &b) {
    if (b < a) {
        a = b;
        return true;
    }
    return false;
}

template<class T>
bool ckmax(T &a, const T &b) {
    if (b > a) {
        a = b;
        return true;
    }
    return false;
}

const int INFi = 2e9;
const ll INF = 2e18;
const int maxN = 3e5 + 100;
const int LG = 20;

vector<pair<int, int>> g1[maxN];
vector<pair<int, int>> g2[maxN];
int to[maxN];
bool ok = true;
vector<ar<int, 3>> edges;

void dfs2(int v) {
    for(auto &[u, p] : g2[v]) {
        if (to[u] == -1) {
            to[u] = to[v] ^ p;
            dfs2(u);
        }
        if (to[u] != (to[v] ^ p)) ok = false;
    }
}

void dfs1(int v, int p, int x) {
    if (to[v] == -1) {
        to[v] = (__builtin_popcount(x) & 1);
        dfs2(v);
    }
    if (to[v] != (__builtin_popcount(x) & 1)) {
        ok = false;
    }
    for(auto &[u, w] : g1[v]) {
        if (u == p) continue;
        int x2 = x;
        if (w != -1) {
            x2 ^= w;
        } else {
            if (to[u] == -1) {
                to[u] = 0;
                dfs2(u);
            }
            int d = (__builtin_popcount(x)&1)^to[u];
            x2 ^= d;
            edges.push_back({v, u, d});
        }
        dfs1(u, v, x2);
    }
}

void solve() {
    int n, m; cin >> n >> m;
    for(int i = 1; i <= n; ++i) {
        g1[i].clear();
        g2[i].clear();
        to[i] = -1;
    }
    edges.clear();

    rep(_, n - 1) {
        int x, y, v; cin >> x >> y >> v;
        g1[x].emplace_back(y, v);
        g1[y].emplace_back(x, v);
        if (v != -1) {
            int t = __builtin_popcount(v)&1;
            g2[x].emplace_back(y, t);
            g2[y].emplace_back(x, t);
        }
    }
    rep(_, m) {
        int a, b, p; cin >> a >> b >> p;
        g2[a].emplace_back(b, p);
        g2[b].emplace_back(a, p);
    }
    ok = true;
    dfs1(1, -1, 0);
    if (!ok) {
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
    for(int i = 1; i <= n; ++i) {
        for(auto &[j, w] : g1[i]) {
            if (w == -1) continue;
            if (j < i) {
                cout << j << ' ' << i << ' ' << w << '\n';
            }
        }
    }
    for(auto &[a, b, c] : edges) cout << a << ' ' << b << ' ' << c << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    // cout << setprecision(20 - 7) << fixed;
    int t = 1;
    cin >> t;
    range(i, t) {
        solve();
    }
    return 0;
}
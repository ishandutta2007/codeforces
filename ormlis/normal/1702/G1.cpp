#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
#define rep1n(i, n) for (int i = 1; i <= (n); ++i)
#define repr(i, n) for (int i = (n) - 1; i >= 0; --i)
#define pb push_back
#define eb emplace_back
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define each(x, a) for (auto &x : a)
#define ar array
#define vec vector
#define range(i, n) rep(i, n)

using namespace std;

using ll = long long;
using ull = unsigned long long;
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
const int maxN = 2e5 + 30;
const int LG = 20;

vi g[maxN];
int h[maxN];

void dfs(int v, int p) {
    for(auto &u : g[v]) {
        if (u == p) continue;
        h[u] = h[v] + 1;
        dfs(u, v);
    }
}

int cur[maxN];
int mx = 0;

void dfs2(int v, int p, int c) {
    c += cur[v];
    mx = max(mx, c);
    for(auto &u : g[v]) {
        if (u == p) continue;
        dfs2(u, v, c);
    }
}

void solve() {
    int n; cin >> n;
    rep(_, n - 1) {
        int u, v; cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    h[1] = 0;
    dfs(1, -1);
    int q; cin >> q;
    rep(_, q) {
        int k; cin >> k;
        vi p(k);
        rep(i, k) cin >> p[i];
        int v = p[0];
        rep(i, k) if (h[p[i]] > h[v]) v = p[i];
        rep(i, k) cur[p[i]] = 1;
        dfs2(v, -1, 0);
        if (mx == k) cout << "YES\n";
        else cout << "NO\n";
        rep(i, k) cur[p[i]] = 0;
        mx = 0;
    }
    for(int i = 1; i <= n; ++i) {
        g[i].clear();
        h[i] = 0;
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    // cout << setprecision(15) << fixed;
    int t = 1;
    //cin >> t;
    range(i, t) {
        solve();
    }
    return 0;
}
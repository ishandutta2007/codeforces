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
using i128 = __int128;
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
const int LG = 20;
const int maxN = 1e6;
const int md = 998244353;

int a[maxN];
vi g[maxN];
set<int> s[maxN];
int ans = 0;

void dfs(int v, int p) {
    int val = a[v];
    if (p != -1) a[v] ^= a[p];
    s[v].insert(a[v]);
    bool ok = true;
    for(auto &u : g[v]) {
        if (u == p) continue;
        dfs(u, v);
        if (s[u].size() > s[v].size()) swap(s[u], s[v]);
        for(auto x : s[u]) {
            if (s[v].count(x ^ val)) ok = false;
        }
        for(auto x : s[u]) {
            s[v].insert(x);
        }
    }
    if (!ok || val == 0) {
        s[v].clear();
        ans++;
    }
}

void solve() {
    int n; cin >> n;
    for(int i = 1; i <= n; ++i) cin >> a[i];
    rep(_, n - 1) {
        int u, v; cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1, -1);
    cout << ans << '\n';
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    // cout << setprecision(15) << fixed;
    int t = 1;
    // cin >> t;
    range(i, t) {
        solve();
    }
    return 0;
}
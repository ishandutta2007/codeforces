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

const int INFi = 1e9 + 10;
const ll INF = 2e18;
const int maxN = 1e6 + 20;
const int LG = 100;
const int md = 998244353; //1e9 + 7, 1e9 + 9

vi g[maxN];
int sz[maxN];

void dfs(int v, int p) {
    sz[v] = 1;
    for (auto &u : g[v]) {
        if (u == p) continue;
        dfs(u, v);
        sz[v] += sz[u];
    }
}

int centroid(int v, int p, int n) {
    for (auto &u : g[v]) {
        if (u == p) continue;
        if (sz[u] * 2 >= n) return centroid(u, v, n);
    }
    return v;
}

void solve() {
    int n;
    cin >> n;
    for (int i = 2; i <= n; ++i) {
        int p;
        cin >> p;
        g[p].push_back(i);
        g[i].push_back(p);
    }
    dfs(1, -1);
    ll S = 0;
    int root = centroid(1, -1, n);
    vl res;
    for (auto &u : g[root]) res.push_back(sz[u]);
    if (root != 1) res.push_back(n - sz[root]);
    sort(all(res));
    vector<pair<int, int>> have;
    dfs(root, -1);
    for (int i = 1; i <= n; ++i) S += sz[i];
    for (auto &x : res) {
        if (have.empty() || have.back().first != x) have.emplace_back(x, 0);
        have.back().second++;
    }
    vector<int> sn;
    for (auto &[x, cnt] : have) {
        for (int t = 1; t <= cnt; t *= 2) {
            sn.push_back(x * t);
            cnt -= t;
        }
        if (cnt != 0) sn.push_back(x * cnt);
    }
    bitset<maxN> dp = 0;
    dp[0] = 1;
    for (auto &x : sn) dp |= (dp << x);
    ll ans = S;
    rep(i, n) {
        if (dp[i]) {
            ll val = S;
            val += 1ll * i * (n - 1 - i);
            ans = max(ans, val);
        }
    }
    cout << ans << '\n';
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
//    cout << setprecision(15) << fixed;
    int t = 1;
    // cin >> t;
    range(i, t) {
        solve();
    }
    return 0;
}
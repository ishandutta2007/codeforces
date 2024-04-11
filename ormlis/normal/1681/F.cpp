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

const int INFi = 1e9 + 10;
const ll INF = 2e18;
const int maxN = 5e5 + 30;
const int LG = 100;

map<int, pair<int, int>> dp[maxN];
vpi g[maxN];
int sz[maxN];

void merge(int v, int u) {
    if (dp[v].size() < dp[u].size()) swap(dp[u], dp[v]);
    for (auto &[x, y] : dp[u]) {
        dp[v][x].first += y.first;
        dp[v][x].second += y.second;
    }
    dp[u].clear();
}

ll ans = 0;

void dfs(int v, int p, int pc) {
    sz[v] = 1;
    for (auto &[u, x] : g[v]) {
        if (u == p) continue;
        dfs(u, v, x);
        sz[v] += sz[u];
        merge(v, u);
    }
    if (p != -1) {
        int UP = sz[v] - dp[v][pc].first;
        dp[v][pc].first = sz[v];
        int DOWN = dp[v][pc].second;
        dp[v][pc].second = UP;
        ans += 1ll * UP * DOWN;
    } else {
        for (auto &[_, t] : dp[v]) {
            int UP = sz[v] - t.first;
            int DOWN = t.second;
            ans += 1ll * UP * DOWN;
        }
    }
}

void solve() {
    int n;
    cin >> n;
    rep(_, n - 1) {
        int u, v, x;
        cin >> u >> v >> x;
        g[v].emplace_back(u, x);
        g[u].emplace_back(v, x);
    }
    dfs(1, -1, -1);
    cout << ans << '\n';
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
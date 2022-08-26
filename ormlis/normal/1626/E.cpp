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

const int INFi = 2e9;
const ll INF = 2e18;
const int maxN = 3e5 + 5;
const int LG = 20;

const int mod = 1e9 + 7;

int c[maxN];
vi g[maxN];
bool dp[maxN];
int sz[maxN];

void dfs(int v, int p) {
    sz[v] = c[v];
    if (c[v]) dp[v] = true;
    for(auto &u : g[v]) {
        if (u == p) continue;
        dfs(u, v);
        if (sz[u] >= 2) {
            dp[v] |= dp[u];
        } else if (c[u]) {
            dp[v] = true;
        }
        sz[v] += sz[u];
    }
}

bool ans[maxN];
int n;

void reroot(int v, int p) {
    vector<bool> to;
    int k = g[v].size();
    {
        bool val = (c[v] == 1);
        for (auto &u : g[v]) {
            if (sz[u] >= 2) {
                val |= dp[u];
            } else if (c[u]) {
                val = true;
            }
            to.push_back(val);
        }
        ans[v] = val;
    }
    vector<bool> to2;
    {
        reverse(all(g[v]));
        bool val = (c[v] == 1);
        for (auto &u : g[v]) {
            if (sz[u] >= 2) {
                val |= dp[u];
            } else if (c[u]) {
                val = true;
            }
            to2.push_back(val);
        }
        reverse(all(g[v]));
        reverse(all(to2));
    }
    rep(i, k) {
        if (g[v][i] == p) continue;
        int u = g[v][i];
        swap(sz[v], sz[u]);
        sz[v] = sz[u] - sz[v];
        dp[v] = (c[v] == 1);
        if (i) dp[v] |= to[i - 1];
        if (i + 1 < k) dp[v] |= to2[i + 1];
        reroot(u, v);
        swap(sz[v], sz[u]);
    }
}

void solve() {
    cin >> n;
    rep(i, n) cin >> c[i + 1];
    rep(_, n - 1) {
        int u, v; cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1, -1);
    reroot(1, -1);
    for(int i = 1; i <= n; ++i) cout << ans[i] << ' ';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    //cout << setprecision(20 - 7) << fixed;
    int t = 1;
    // cin >> t;
    range(i, t) {
        solve();
    }
    return 0;
}
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
const int maxN = 2e5 + 20;
const int LG = 30;

vi g[maxN];
int dp[maxN];

void dfs(int v, int p = -1) {
    dp[v] = 0;
    int ch = 0;
    for (auto &u : g[v]) {
        if (u == p) continue;
        dfs(u, v);
        dp[v] += dp[u];
        if (dp[u] == 0) ch++;
    }
    dp[v] += max(0, ch - 1);
}

int mn = INFi;

void reroot(int v, int p = -1) {
    int cur = 1;
    int ch = 0;
    for (auto &u : g[v]) {
        cur += dp[u];
        if (dp[u] == 0) ch++;
    }
    mn = min(mn, cur + max(0, ch - 1));
    for(auto &u : g[v]) {
        if (u == p) continue;
        dp[v] = cur - 1 - dp[u] + max(0, ch - 1 - (int)(dp[u] == 0));
        reroot(u, v);
    }
}

void solve() {
    int n;
    cin >> n;
    if (n == 1) {
        cout << "0\n";
        return;
    }
    rep(_, n - 1) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    mn = INFi;
    dfs(1);
    reroot(1);
    cout << mn << '\n';
    for (int i = 1; i <= n; ++i) g[i].clear();
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    cin >> t;
    range(i, t) {
        solve();
    }
    return 0;
}
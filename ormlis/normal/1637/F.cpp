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
const int maxN = 2e5 + 30;
const int LG = 19;

int h[maxN];
vi g[maxN];
ll ans = 0;

int dfs(int v, int p) {
    int mx = 0;
    for(auto &u : g[v]) {
        if (u == p) continue;
        mx = max(mx, dfs(u, v));
    }
    if (mx < h[v]) {
        ans += h[v] - mx;
        mx = h[v];
    }
    return mx;
}

void solve() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> h[i];
    rep(_, n - 1) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    int t =1;
    for(int i = 1; i <= n; ++i) if (h[i] > h[t]) t = i;
    vi have;
    for(auto &u : g[t]) have.push_back(dfs(u, t));
    sort(rall(have));
    have.push_back(0);
    ans += h[t] * 2 - have[0] - have[1];
    cout << ans << '\n';
}

signed main() {
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
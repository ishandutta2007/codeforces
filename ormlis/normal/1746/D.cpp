#include "bits/stdc++.h"


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
const int md = 1e9 + 7;

const int maxN = 2e5 + 5;
map<int, ll> dp[maxN];
int s[maxN];
vi g[maxN];

ll calc_dp(int v, int val) {
    if (dp[v].count(val)) return dp[v][val];
    ll result = 1ll * val * s[v];
    if (g[v].empty()) return dp[v][val] = result;
    int sz = g[v].size();
    int L = val / sz;
    int R = (val + sz - 1) / sz;
    vl res;
    for(auto u : g[v]) {
        ll cur = calc_dp(u, L);
        result += cur;
        ll nxt = calc_dp(u, R);
        res.push_back(nxt - cur);
    }
    sort(rall(res));
    int need = val - sz * L;
    assert(need < sz);
    rep(i, need) result += res[i];
    return dp[v][val] = result;
}

void solve() {
    int n, k; cin >> n >> k;
    for(int i = 2; i <= n; ++i) {
        int p; cin >> p;
        g[p].push_back(i);
    }
    for(int i = 1; i <= n; ++i) cin >> s[i];
    cout << calc_dp(1, k) << '\n';
    for(int i = 1; i <= n; ++i) {
        dp[i].clear();
        g[i].clear();
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
//    cout << setprecision(15) << fixed;
    int t = 1;
    cin >> t;
    rep(_, t) {
        solve();
    }
    return 0;
}
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
const int maxN = 1e5 + 20;

const int md = 998244353; //1e9 + 7, 1e9 + 9

inline int add(const int &a, const int &b) {
    return a + b >= md ? a + b - md : a + b;
}

inline int sub(const int &a, const int &b) {
    return a - b < 0 ? a - b + md : a - b;
}

inline int mul(const int &a, const int &b) {
    return (1ll * a * b) % md;
}

int binpow(int a, int b) {
    int res = 1;
    for(; b; b >>= 1, a = mul(a, a)) if (b & 1) res = mul(res,  a);
    return res;
}

int rev(int a) {
    return binpow(a, md - 2);
}


void solve() {
    int n, m;
    cin >> n >> m;
    vi a(n);
    rep(i, n) cin >> a[i];
    vvi g(n);
    rep(_, m) {
        int x, y; cin >> x >> y;
        x--;
        y--;
        g[x].push_back(y);
    }
    vi ts;
    vi used(n);
    function<void(int)> dfs = [&] (int v) {
        used[v] = 1;
        for(auto u : g[v]) {
            if (used[u]) continue;
            dfs(u);
        }
        ts.push_back(v);
    };
    rep(i, n) {
        if (!used[i]) dfs(i);
    }
    reverse(all(ts));
    vector<vector<ar<ll, 3>>> segs(n);
    for(auto i : ts) {
        if (a[i] != 0) segs[i].push_back({0, a[i] - 1, a[i]});
        sort(all(segs[i]));
        vector<ar<ll, 3>> res;
        for(auto [l, r, len] : segs[i]) {
            if (res.empty() || res.back()[1] + 1 < l) res.push_back({l, l - 1, 0});
            res.back()[2] = (res.back()[2] + len) % md;
            res.back()[1] += r - l + 1;
            res.back()[1] = min(res.back()[1], 1ll * INFi);
        }
        segs[i] = res;
        for(auto [l, r, len] : res) {
            l++;
            r = min(r + 1, 1ll * INFi);
            for(auto j : g[i]) {
                segs[j].push_back({l, r, len});
            }
        }
    }
    int v = ts.back();
    if (segs[v].empty()) {
        cout << "0\n";
        return;
    }
    ll ans = segs[v].back()[0];
    ans += segs[v].back()[2];
    ans %= md;
    cout << ans << '\n';
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    //cout << setprecision(15) << fixed;
    int t = 1;
     cin >> t;
    range(i, t) {
        solve();
    }
    return 0;
}
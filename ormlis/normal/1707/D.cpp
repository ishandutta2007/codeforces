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
const int LG = 20;
const int maxN = 2005;

int md;


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
    for (; b; b >>= 1, a = mul(a, a)) if (b & 1) res = mul(res, a);
    return res;
}

int rev(int a) {
    return binpow(a, md - 2);
}

int dp[maxN][maxN];
vi g[maxN];
int n;

void dfs(int v, int p) {
    vector<int> childs;
    for (auto &u : g[v]) {
        if (u == p) continue;
        dfs(u, v);
        childs.push_back(u);
    }
    int c = childs.size();
    vector<int> cur(c, 0);
    for (int k = 1; k < n; ++k) {
        vi pref(c, 1), suf(c, 1);
        rep(i, c) {
            pref[i] = dp[childs[i]][k];
            if (i) pref[i] = mul(pref[i], pref[i - 1]);
        }
        for (int i = c - 1; i >= 0; --i) {
            suf[i] = dp[childs[i]][k];
            if (i + 1 < c) suf[i] = mul(suf[i], suf[i + 1]);
        }
        dp[v][k] = (c == 0 ? 1 : pref[c - 1]);
        if (k != 1) {
            rep(i, c) {
                int u = childs[i];
                dp[v][k] = add(dp[v][k], mul(cur[i], sub(dp[u][k], dp[u][k - 1])));
            }
        }
        rep(i, c) {
            int val = 1;
            if (i) val = mul(val, pref[i - 1]);
            if (i + 1 < c) val = mul(val, suf[i + 1]);
            cur[i] = add(cur[i], val);
        }
        dp[v][k] = add(dp[v][k], dp[v][k - 1]);
    }
}

void solve() {
    cin >> n >> md;
    rep(_, n - 1) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for(auto &u : g[1]) {
        dfs(u, 1);
    }
    vi res(n);
    for(int k = 1; k < n; ++k) {
        res[k] = 1;
        for(auto &u : g[1]) {
            res[k] = mul(res[k], dp[u][k]);
        }
    }
    vvi C(n, vi(n));
    C[0][0] = 1;
    for(int i = 1; i < n; ++i) {
        C[i][0] = 1;
        for(int j = 1; j < n; ++j) {
            C[i][j] = add(C[i - 1][j - 1], C[i - 1][j]);
        }
    }
    for(int k = 1; k < n; ++k) {
        for(int d = k + 1; d < n; ++d) {
            res[d] = sub(res[d], mul(res[k], C[d][k]));
        }
        cout << res[k] << ' ';
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
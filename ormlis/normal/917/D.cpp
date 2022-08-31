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
const int maxN = 100 + 5;
const int LG = 30;


const int md = 1e9 + 7; //1e9 + 7, 1e9 + 9

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

const int maxF = 2e5 + 5;
int fact[maxF];
int rfact[maxF];

void init() {
    fact[0] = 1;
    for (int i = 1; i < maxF; ++i) fact[i] = mul(fact[i - 1], i);
    rfact[maxF - 1] = rev(fact[maxF - 1]);
    for (int i = maxF - 1; i >= 1; --i) {
        rfact[i - 1] = mul(rfact[i], i);
    }
}

int C(int n, int k) {
    if (k < 0 || n < k) return 0;
    return mul(fact[n], mul(rfact[k], rfact[n - k]));
}

vector<int> g[maxN];
int dp[maxN][maxN][maxN];
int N;

// dp[v][k][size[v]]

void calc(int v, int p) {
    // prod(sz[i] * N)
    dp[v][0][1] = N;
    for (auto &u : g[v]) {
        if (u == p) continue;
        calc(u, v);
        for (int k = N - 1; k >= 0; --k) {
            for (int sz = N; sz >= 0; --sz) {
                if (dp[v][k][sz] == 0) continue;
                int cur = dp[v][k][sz];
                dp[v][k][sz] = 0;
                for (int k2 = N - 1; k2 >= 0; --k2) {
                    for (int sz2 = N; sz2 >= 0; --sz2) {
                        if (dp[u][k2][sz2] == 0) continue;
                        int val = mul(dp[u][k2][sz2], cur);
                        dp[v][k + k2][sz] = add(dp[v][k + k2][sz], val);
                        val = mul(val, sz + sz2);
                        val = mul(val, rev(mul(N, mul(sz, sz2))));
                        dp[v][k + k2 + 1][sz + sz2] = add(dp[v][k + k2 + 1][sz + sz2], val);
                    }
                }
            }
        }
    }
}


void solve() {
    init();
    int n;
    cin >> n;
    N = n;
    rep(_, n - 1) {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    calc(1, -1);
    vi ans(n);
    rep(k, N) {
        rep(sz, N + 1) {
            ans[k] = add(ans[k], dp[1][k][sz]);
        }
        ans[k] = mul(ans[k], rev(mul(N, N)));
    }
    for (int k = n - 1; k >= 0; --k) {
        for (int t = k + 1; t < n; ++t) {
            ans[k] = sub(ans[k], mul(ans[t], C(t, k)));
        }
    }
    rep(i, n) cout << ans[i] << ' ';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    //cout << setprecision(20 - 7) << fixed;
    int t = 1;
    //cin >> t;
    range(i, t) {
        solve();
    }
    return 0;
}
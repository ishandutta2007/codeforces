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
const int maxN = 5e6 + 30;
const int LG = 100;


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

int n, k;

int ans_dp[maxN];
int sz_dp[maxN];
vi g[maxN];

int answer = 0;

void dfs(int v, int p) {
    sz_dp[v] = 1;
    ans_dp[v] = 0;
    int cnt = 0;
    for (auto &u : g[v]) {
        if (u == p) continue;
        dfs(u, v);
        sz_dp[v] += sz_dp[u];
        ans_dp[v] = add(ans_dp[v], ans_dp[u]);
        cnt = sub(cnt, C(sz_dp[u], k));
    }
    cnt = add(cnt, C(sz_dp[v], k));
    ans_dp[v] = add(ans_dp[v], mul(cnt, sz_dp[v]));
}

void solve(int v) {
    sz_dp[v] = 1;
    ans_dp[v] = 0;
    int cnt = 0;
    for (auto &u : g[v]) {
        sz_dp[v] += sz_dp[u];
        ans_dp[v] = add(ans_dp[v], ans_dp[u]);
        cnt = sub(cnt, C(sz_dp[u], k));
    }
    cnt = add(cnt, C(sz_dp[v], k));
    ans_dp[v] = add(ans_dp[v], mul(cnt, sz_dp[v]));
    answer = add(answer, ans_dp[v]);
}

void reroot(int v, int p) {
    solve(v);
    int SZ = 1;
    int ANS = 0;
    int CNT = 0;
    for (auto &u : g[v]) {
        SZ += sz_dp[u];
        ANS = add(ANS, ans_dp[u]);
        CNT = sub(CNT, C(sz_dp[u], k));
    }
    for (auto &u : g[v]) {
        if (u == p) continue;
        sz_dp[v] = SZ - sz_dp[u];
        ans_dp[v] = sub(ANS, ans_dp[u]);
        int cnt = add(CNT, C(sz_dp[u], k));
        cnt = add(cnt, C(sz_dp[v], k));
        ans_dp[v] = add(ans_dp[v], mul(cnt, sz_dp[v]));
        reroot(u, v);
    }
}

void solve() {
    cin >> n >> k;
    rep(_, n - 1) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1, 0);
    reroot(1, 0);
    cout << answer << '\n';
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    // cout << setprecision(15) << fixed;
    int t = 1;
//    cin >> t;
    init();
    range(i, t) {
        solve();
    }
    return 0;
}
#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>

#define range(i, n) for (int i = 0; i < (n); ++i)
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define ar array
using namespace std;

// using namespace __gnu_pbds;
/*
typedef tree<
int,
null_type,
less<int>,
rb_tree_tag,
tree_order_statistics_node_update>
ordered_set;
*/

typedef long long ll;
typedef double ld;
typedef unsigned long long ull;

const int INFi = 1e9 + 5;
const int maxN = 3e5 + 5;
const int md = 998244353;
const ll INF = 2e18;

double getTime() { return clock() / (double) CLOCKS_PER_SEC; }

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
    if (b <= 0) return 1;
    if (b % 2) return mul(a, binpow(a, b - 1));
    int m = binpow(a, b / 2);
    return mul(m, m);
}

int rev(int a) {
    return binpow(a, md - 2);
}

const int maxF = 3e5 + 5;
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
int sz[maxN];
bool isGood[maxN];

int dfs(int v, int p) {
    int cnt = 1;
    sz[v] = g[v].size();
    if (p) g[v].erase(find(all(g[v]), p));
    for (auto &u : g[v]) {
        cnt = mul(cnt, mul(2, dfs(u, v)));
    }
    return cnt;
}

int dp[maxN];
int ch[maxN];
int ct = 0;

void dfs2(int v, int p, int k) {
    isGood[v] = (int) sz[v] < k;
    for (auto &u : g[v]) {
        ch[v] -= dp[u];
        dfs2(u, v, k);
        ch[v] += dp[u];
        isGood[v] &= isGood[u];
    }
    for (int i = (int) g[v].size() - 1; i >= 0; --i) {
        if (isGood[g[v][i]]) {
            swap(g[v][i], g[v][(int) g[v].size() - 1]);
            g[v].pop_back();
        }
    }
    if (dp[v] == -1) ct--;
    if (((p != 0) + ch[v]) % k == 0) {
        dp[v] = 0;
    } else if (ch[v] % k == 0 && p) {
        dp[v] = 1;
    } else {
        dp[v] = -1;
        ct++;
    }
}

void solve() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) g[i].clear(), isGood[i] = false, dp[i] = 0, ch[i] = 0;
    ct = 0;
    range(_, n - 1) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    int mn = INFi;
    for (int v = 1; v <= n; ++v) {
        for (auto &u : g[v]) {
            mn = min(mn, (int) max(g[v].size(), g[u].size()));
        }
    }
    vector<int> result(n + 1);
    result[1] = dfs(1, 0);
    for (int k = 2; k <= mn; ++k) {
        dfs2(1, 0, k);
        result[k] = (ct == 0);
    }
    for (int k = mn; k >= 2; --k) {
        for (int w = k * 2; w <= mn; w += k) {
            if (result[w]) result[k] = 0;
        }
        if (result[k]) result[1] = sub(result[1], 1);
    }
    for (int i = 1; i <= n; ++i) cout << result[i] << ' ';
    cout << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    // cout << setprecision(15) << fixed;
    int tests = 1;
    init();
    cin >> tests;
    range(_, tests) {
        solve();
    }
    return 0;
}
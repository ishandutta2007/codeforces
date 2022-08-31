#include <bits/stdc++.h>

#define ar array
#define all(arr) (arr).begin(), (arr).end()
#define range(i, n) for (int i=0; (i) < n; ++(i))
#define rall(arr) (arr).rbegin(), (arr).rend()

typedef unsigned long long ll;

using namespace std;
const ll INF = 2e18;
const int INFi = 2e9;
const int maxN = 2e5 + 5;
const int P = 998244353;
const int md = 1e9 + 7;

double getTime() { return clock() / (double) CLOCKS_PER_SEC; };

vector<int> g[maxN];
int dp[maxN];

int mul(int a, int b) {
    return (1ll * a * b) % md;
}

int add(int a, int b) {
    if (a + b >= md) return a + b - md;
    return a + b;
}

int sub(int a, int b) {
    if (a - b < 0) return a - b + md;
    return a - b;
}

int binpow(int a, int b) {
    if (b <= 0) return 1;
    if (b % 2) return mul(a, binpow(a, b - 1));
    int mid = binpow(a, b / 2);
    return mul(mid, mid);
}

int rev(int a) {
    return binpow(a, md - 2);
}

bool flag[maxN];

void dfs1(int v, int p) {
    bool is_list = true;
    dp[v] = 1;
    for(auto u: g[v]) {
        if (u == p) continue;
        is_list = false;
        dfs1(u, v);
        dp[v] = mul(dp[v], dp[u]);
    }
    flag[v] = is_list;
    if (!is_list) dp[v] = mul(dp[v], 2);
}

int ans = 0;

void dfs2(int v, int p) {
    ans = add(ans, dp[v]);
    for(auto u: g[v]) {
        if (u == p) continue;
        int pref_u = dp[u];
        dp[v] = mul(dp[v], rev(pref_u));
        if (g[v].size() == 1) dp[v] = 1;
        dp[u] = mul(dp[u], dp[v]);
        if (flag[u]) dp[u] = mul(dp[u], 2);
        dfs2(u, v);
        dp[u] = pref_u;
        dp[v] = mul(dp[v], pref_u);
    }
}

void solve() {
    int n;
    cin >> n;
    range(i, n - 1) {
        int v, u;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs1(1, -1);
    dfs2(1, -1);
    cout << ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int tests = 1;
    range(_, tests) {
        solve();
    }
    return 0;
}
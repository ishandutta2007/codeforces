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
typedef long double ld;
typedef unsigned long long ull;

const int INFi = 2e9 + 5;
const int maxN = 305;
const int md = 998244353;
const ll INF = 2e18;

double getTime() { return clock() / (double) CLOCKS_PER_SEC; }


int add(int a, int b) {
    if (a + b >= md) return a + b - md;
    return a + b;
}

int sub(int a, int b) {
    if (a - b < 0) return a - b + md;
    return a - b;
}

int mul(int a, int b) {
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

int fact[maxN];

void init() {
    fact[0] = 1;
    for (int i = 1; i < maxN; ++i) fact[i] = mul(fact[i - 1], i);
}

int C(int n, int k) {
    if (k > n || k < 0) return 0;
    return mul(fact[n], rev(mul(fact[k], fact[n - k])));
}

vector<int> g[maxN];
int dp[maxN][2][maxN];
int pref_sum[maxN][2][maxN];
int suf_sum[maxN][2][maxN];

int d;
int n;

void dfs(int v, int p) {
    for (auto &u : g[v]) {
        if (u == p) continue;
        dfs(u, v);
    }
    {
        for (int mn_used = 0; mn_used <= d; ++mn_used) {
            dp[v][0][mn_used] = 0;
            int ways = 1;
            int d2 = d - mn_used;
            for (auto &u : g[v]) {
                if (u == p) continue;
                int sum = 0;
                sum = add(sum, suf_sum[u][0][max(0, mn_used - 1)]);
                if (d2) sum = add(sum, pref_sum[u][1][d2 - 1]);
                ways = mul(ways, sum);
            }
            int ways2 = 1;
            for (auto &u : g[v]) {
                if (u == p) continue;
                int sum = 0;
                sum = add(sum, suf_sum[u][0][mn_used]);
                if (d2) sum = add(sum, pref_sum[u][1][d2 - 1]);
                ways2 = mul(ways2, sum);
            }
            if (mn_used) ways = sub(ways, ways2);
            dp[v][0][mn_used] = ways;
        }
    }
    {
        for (int mx_clear = 0; mx_clear < d; ++mx_clear) {
            dp[v][1][mx_clear] = 0;
            int d2 = d - mx_clear;
            int ways = 1;
            for (auto &u : g[v]) {
                if (u == p) continue;
                int sum = 0;
                if (mx_clear) sum = add(sum, pref_sum[u][1][mx_clear - 1]);
                sum = add(sum, suf_sum[u][0][d2]);
                ways = mul(ways, sum);
            }
            int ways2 = 1;
            for (auto &u : g[v]) {
                if (u == p) continue;
                int sum = 0;
                if (mx_clear >= 2) sum = add(sum, pref_sum[u][1][mx_clear - 2]);
                sum = add(sum, suf_sum[u][0][d2]);
                ways2 = mul(ways2, sum);
            }
            if (mx_clear) ways = sub(ways, ways2);
            dp[v][1][mx_clear] = ways;
            /*
            if (mx_clear) {
                for (auto &u : g[v]) {
                    if (u == p) continue;
                    int sum = 0;
                    sum = add(sum, pref_sum[u][1][mx_clear - 1]);
                    sum = add(sum, suf_sum[u][0][d2]);
                    ways = mul(ways, rev(sum));
                    dp[v][1][mx_clear] = add(dp[v][1][mx_clear], mul(ways, dp[u][1][mx_clear - 1]));
                    sum = sub(sum, dp[u][1][mx_clear - 1]);
                    ways = mul(ways, sum);
                }
            } else {
                dp[v][1][0] = ways;
            }*/
        }
    }
    range(j, 2) {
        pref_sum[v][j][0] = dp[v][j][0];
        range(i, d + 2) pref_sum[v][j][i + 1] = add(pref_sum[v][j][i], dp[v][j][i + 1]);
        suf_sum[v][j][d + 1] = dp[v][j][d + 1];
        for(int i = d; i >= 0; --i) suf_sum[v][j][i] = add(suf_sum[v][j][i + 1], dp[v][j][i]);
    }
}

void solve() {
    cin >> n;
    range(_, n - 1) {
        int a, b; cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    int CNT = binpow(2, n);
    int ans = sub(0, CNT);
    for(d = 0; d <= n; ++d) {
        dfs(1, -1);
        int cnt = suf_sum[1][0][0];
        //  cnt   < d
        cnt = sub(CNT, cnt);
        ans = add(ans, cnt);
    }
    ans = mul(ans, rev(CNT));
    cout << ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    // cout << setprecision(15) << fixed;
    int tests = 1;
    //cin >> tests;
    range(_, tests) {
        solve();
    }
    return 0;
}
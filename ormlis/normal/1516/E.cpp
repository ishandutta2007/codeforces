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
const int maxN = 3e5;
const int md = 1e9 + 7;
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
int rfact[maxN];

void init() {
    fact[0] = 1;
    for (int i = 1; i < maxN; ++i) fact[i] = mul(fact[i - 1], i);
    rfact[maxN - 1] = rev(fact[maxN - 1]);
    for(int i = maxN - 1; i >= 1; --i) rfact[i - 1] = mul(rfact[i], i);
}

int C(int n, int k) {
    if (k > n || k < 0) return 0;
    int res = 1;
    for(int i = n; i > n - k; --i) res = mul(res, i);
    return mul(res, rfact[k]);
}

int A(int n, int k) {
    if (k > n || k < 0) return  0;
    return mul(fact[n], rfact[n - k]);
}

void solve() {
    init();
    int n, k; cin >> n >> k;
    // dp[k1][n1][last]
    vector<int> ans(k + 1);
    vector<int> Ct(2 * k + 1);
    range(i, Ct.size()) Ct[i] = C(n, i);
    vector<vector<int>> dp(k + 1, vector<int> (k * 2 + 1, 0));
    dp[0][0] = ans[0] = 1;
    for(int k1 = 1; k1 <= k; ++k1) {
        for(int t = k1 + 1; t <= min(n, k1 * 2); ++t) {
            int res = 0;
            for(int o1 = 2; o1 <= t && o1 - 1 <= k1; ++o1) {
                res = add(res, mul(A(t - 1, o1 - 1), dp[k1 - (o1 - 1)][t - o1]));
            }
            dp[k1][t] = res;
            ans[k1] = add(ans[k1], mul(res, Ct[t]));
        }
    }
    for(int i = 2; i <= k; ++i) ans[i] = add(ans[i], ans[i - 2]);
    for(int i = 1; i <= k; ++i) cout << ans[i] << ' ';
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
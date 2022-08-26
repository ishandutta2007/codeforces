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
const int maxN = 405;
const int md = 998244353;
const ll INF = 2e18;

double getTime() { return clock() / (double) CLOCKS_PER_SEC; }

int dp[maxN][maxN];
int mt[maxN];
int C[maxN][maxN];

int m;
void init() {
    range(i, maxN) C[i][0] = 1;
    for(int i = 1; i < maxN; ++i) {
        for(int j = 1; j <= i; ++j) {
            C[i][j] = C[i - 1][j] + C[i - 1][j - 1];
            if (C[i][j] >= m) C[i][j] -= m;
            //assert(C[i][j] < m);
        }
    }
}

void solve() {
    int n; cin >> n >> m;
    init();
    dp[1][1] = 1;
    mt[1] = 1;
    for(int i = 2; i <= n; ++i) {
        mt[i] = mt[i - 1] * 2;
        while(mt[i] >= m) mt[i] -= m;
        //assert(mt[i] < m);
    }
    for(int i = 2; i <= n; ++i) {
        dp[i][1] = mt[i];
        for(int j = 2; j <= i; ++j) {
            for(int l = i - 2; l >= 1; --l) {
                int d = dp[l][j - 1];
                if (d == 0) continue;
                d = (1ll * d * C[i - j + 1][i - l - 1]) % m;
                d = (1ll * d * mt[i - l - 1]) % m;
                dp[i][j] += d;
                if (dp[i][j] >= m) dp[i][j] -= m;
                //assert(dp[i][j] < m);
            }
        }
    }
    int result = 0;
    for(int i = 1; i <= n; ++i) {
        result += dp[n][i];
        if (result >= m) result -= m;
    }
    cout << result << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    // cout << setprecision(15) << fixed;
    int tests = 1;
    // cin >> tests;
    range(_, tests) {
        solve();
    }
    return 0;
}
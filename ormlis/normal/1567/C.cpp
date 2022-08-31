#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>

#define range(i, n) for (int i = 0; i < (n); ++i)
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define ar array

using namespace std;
//using namespace __gnu_pbds;


typedef long long ll;
typedef double ld;
typedef unsigned long long ull;

/*
typedef tree<
        pair<ll, int>,
        null_type,
        less<pair<ll, int>>,
        rb_tree_tag,
        tree_order_statistics_node_update>
        ordered_set;
*/

const int INFi = 1e9 + 5;
const int md = 998244353;
const ll INF = 2e18;
const int maxN = 2e6 + 1;

double getTime() { return clock() / (double) CLOCKS_PER_SEC; }

void solve() {
    int n; cin >> n;
    vector<ll> dp(4);
    dp[0] = 1;
    while(n) {
        int x = n % 10;
        n /= 10;
        vector<ll> dp2(4);
        range(mask, 4) {
            int need = x;
            if (mask & 1) need--;
            range(a, need + 1) {
                dp2[mask >> 1] += dp[mask];
            }
            need += 10;
            range(a, 10) {
                int b = need - a;
                if (b < 0 || b > 9) continue;
                dp2[(mask >> 1) | 2] += dp[mask];
            }
        }
        swap(dp, dp2);
    }
    cout << dp[0] - 2 << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    // cout << setprecision(15) << fixed;
    int tests = 1;
    cin >> tests;
    range(_, tests) {
        solve();
    }
    return 0;
}
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

const int INFi = 2e9 + 5;
const int maxN = 2e5 + 5;
const int md = 998244353;
const ll INF = 2e18;

double getTime() { return clock() / (double) CLOCKS_PER_SEC; }

void solve() {
    int n; cin >> n;
    vector<vector<int>> cnt(2, vector<int> (2));
    range(i, n) {
        int x, y; cin >> x >> y;
        x /= 2;
        y /= 2;
        cnt[x%2][y%2]++;
    }
    ll ans = 0;
    range(i, 2) {
        range(j, 2) {
            ll x = cnt[i][j];
            ans += 1ll * x * (x - 1) * (x - 2) / 6;
        }
    }
    range(i, 2) {
        range(j, 2) {
            ll x1 = cnt[i][j];
            ans += 1ll * x1 * (x1 - 1) / 2 * (n - x1);
        }
    }
    cout << ans << '\n';
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
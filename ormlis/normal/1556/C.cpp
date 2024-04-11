#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>

#define range(i, n) for (int i = 0; i < (n); ++i)
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define ar array
using namespace std;

/*
using namespace __gnu_pbds;

typedef tree<
        pair<int, int>,
        null_type,
        less<pair<int, int>>,
        rb_tree_tag,
        tree_order_statistics_node_update>
        ordered_set;
*/

typedef long long ll;
typedef double ld;
typedef unsigned long long ull;

const int INFi = 1e9 + 5;
const int md = 1e9 + 7;
const ll INF = 2e18;
const int maxN = 5e5 + 1;

double getTime() { return clock() / (double) CLOCKS_PER_SEC; }

void solve() {
    int n; cin >> n;
    vector<int> c(n);
    range(i, n) cin >> c[i];
    ll ans = 0;
    for(int start = 1; start < n; start += 2) {
        ll cur = 0;
        ll mx = 0;
        for(int j = start; j < n; j += 2) {
            if (j != start) {
                cur += c[j - 2];
                mx = max(mx, cur);
                cur -= c[j - 1];
            }
            if (mx > c[start - 1]) break;
            if (cur + c[j] < mx) continue;
            ll L = mx - cur;
            ll R = c[start - 1] - cur;
            R = min(R, 1ll * c[j]);
            if (L <= R) ans += R - L + 1;
        }
        ans--;
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
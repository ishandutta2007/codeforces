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

void solve() {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    range(i, n) cin >> a[i];
    range(i, n) cin >> b[i];
    ll sm = 0;
    range(i, n) sm += 1ll * a[i] * b[i];
    ll ans = sm;
    range(c, n) {
        ll cur = sm;
        for (int i = 1; i <= n; ++i) {
            if (c - i < 0 || c + i >= n) break;
            cur -= 1ll * a[c - i] * b[c - i];
            cur -= 1ll * a[c + i] * b[c + i];
            cur += 1ll * a[c - i] * b[c + i];
            cur += 1ll * a[c + i] * b[c - i];
            ans = max(ans, cur);
        }
    }
    range(c1, n - 1) {
        ll cur = sm;
        for (int i = 0; i <= n; ++i) {
            if (c1 - i < 0 || c1 + i + 1 >= n) break;
            cur -= 1ll * a[c1 - i] * b[c1 - i];
            cur -= 1ll * a[c1 + i + 1] * b[c1 + 1 + i];
            cur += 1ll * a[c1 - i] * b[c1 + 1 + i];
            cur += 1ll * a[c1 + 1 + i] * b[c1 - i];
            ans = max(ans, cur);
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
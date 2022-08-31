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
const int md = 1e9 + 7;
const ll INF = 2e18;

double getTime() { return clock() / (double) CLOCKS_PER_SEC; }

void solve() {
    int n; cin >> n;
    vector<int> a(n), b(n);
    range(i, n) cin >> a[i];
    range(i,n ) cin >> b[i];
    sort(rall(a));
    sort(rall(b));
    for(int i = 1; i < n; ++i) a[i] += a[i - 1];
    for(int i = 1; i < n; ++i) b[i] += b[i - 1];
    int l = -1;
    int r = n * 4 + 5;
    auto check = [&] (ll x) {
        ll ch = (x + n) - ((x + n) / 4);
        ll su1 = 1ll * min(ch, x) * 100;
        ll su2 = 0;
        int t = max(ch - x, 0ll);
        if (t != 0) {
            su1 += a[t - 1];
        }
        int t2 = min(n * 1ll, ch);
        if (t2 != 0) su2 += b[t2 - 1];
        return su1 >= su2;
    };
    if (check(0)) r = 0;
    while(r - l > 1) {
        int mid = (r + l) / 2;
        if (check(mid)) {
            r = mid;
        } else {
            l = mid;
        }
    }
    cout << r << '\n';
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
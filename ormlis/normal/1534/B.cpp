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
const int maxN = 3e5 + 5;
const int md = 1e9 + 7;
const ll INF = 2e18;

double getTime() { return clock() / (double) CLOCKS_PER_SEC; }

void solve() {
    int n; cin >> n;
    vector<int> a(n);
    range(i, n) cin >> a[i];
    vector<int> ord(n);
    iota(all(ord), 0);
    sort(all(ord), [&] (const int &i, const int &j) {
        return a[i] > a[j];
    });
    ll ans = a[0];
    range(i, n - 1) ans += abs(a[i] - a[i + 1]);
    ans += a[n - 1];
    for(auto &i : ord) {
        int d = 0;
        if (i) d = max(d, a[i - 1]);
        if (i + 1 < n) d = max(d, a[i + 1]);
            if (d < a[i]) {
                ans -= a[i] - d;
                a[i] = d;
            }
    }
    cout << ans << "\n";
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
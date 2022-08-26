#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

#define range(i, n) for (int i = 0; i < (n); ++i)
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define ar array

using namespace std;
using namespace __gnu_pbds;


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
const int maxN = 3e5 + 5;

double getTime() { return clock() / (double) CLOCKS_PER_SEC; }

void solve() {
    int n; cin >> n;
    vector<ll> a(n);
    range(i, n) cin >> a[i];
    sort(all(a));
    int m; cin >> m;
    ll sum = accumulate(all(a), 0ll);
    range(_, m) {
        ll x, y; cin >> x >> y;
        int j = lower_bound(all(a), x) - a.begin();
        ll answer = INF;
        if (j != n) {
            answer = min(answer, y - (sum - a[j]));
        }
        if (j != 0) {
            ll need = max(0ll, y - (sum - a[j - 1]));
            answer = min(answer, need + x - a[j - 1]);
        }
        cout << max(0ll, answer) << '\n';
    }
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
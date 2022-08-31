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
    ll a, b, c, m; cin >> a >> b >> c >> m;
    if (a + b + c - 3 < m) {
        cout << "NO\n";
        return;
    }
    vector<ll> d = {a, b, c};
    sort(all(d));
    a = d[0];
    b = d[1];
    c = d[2];
    ll k = c - (a + b) - 1;
    if (k > m) {
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
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
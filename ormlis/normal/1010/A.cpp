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
const int maxN = 2e5 + 1;

double getTime() { return clock() / (double) CLOCKS_PER_SEC; }

void solve() {
    int n, m; cin >> n >> m;
    double c = 1, d = 0;
    vector<int> a(n), b(n);
    range(i, n) cin >> a[i];
    range(i, n) cin >> b[i];
    range(i, n) {
        ld k = 1.0 - 1.0 / (ld)a[i];
        c *= k;
        d *= k;
        d -= (ld)m / (ld)a[i];

        k = 1.0 - 1.0 / (ld)b[i];
        c *= k;
        d *= k;
        d -= (ld)m / (ld)b[i];
    }
    // k * x + b = 0
    if (c == 0) {
        cout << "-1\n";
        return;
    }
    cout << (-d) / c << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(15) << fixed;
    int tests = 1;
    // cin >> tests;
    range(_, tests) {
        solve();
    }
    return 0;
}
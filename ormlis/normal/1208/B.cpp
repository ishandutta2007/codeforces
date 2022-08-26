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

const int INFi = 1e9 + 5;
const int maxN = 2e5 + 5;
const int md = 998244353;
const ll INF = 2e18;

double getTime() { return clock() / (double) CLOCKS_PER_SEC; }

void solve() {
    int n; cin >> n;
    int r = -1;
    vector<int> a(n);
    range(i, n) cin >> a[i];
    map<int, int> c;
    range(i, n) {
        if (c.count(a[i])) r = max(r, c[a[i]]);
        c[a[i]] = i;
    }
    if (r == -1) {
        cout << "0\n";
        return;
    }
    int ans = n;
    set<int> was;
    range(l, n) {
        ans = min(ans, r - l + 1);
        if (was.count(a[l])) break;
        r = max(r, c[a[l]]);
        was.insert(a[l]);
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
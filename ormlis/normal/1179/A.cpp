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
const int md = 998244353;
const ll INF = 2e18;
const int maxN = 1e5 + 1;

double getTime() { return clock() / (double) CLOCKS_PER_SEC; }

void solve() {
    int n, q; cin >> n >> q;
    deque<int> a(n);
    range(i, n) cin >> a[i];
    vector<pair<int, int>> ans;
    range(_, n) {
        int A = a[0], B = a[1];
        ans.push_back({A, B});
        a.pop_front();
        a.pop_front();
        a.push_front(max(A, B));
        a.push_back(min(A, B));
    }
    range(_, q) {
        ll m; cin >> m;
        if (m <= n) {
            cout << ans[m - 1].first << ' ' << ans[m - 1].second << '\n';
            continue;
        }
        m -= n + 1;
        m %= n - 1;
        cout << a[0] << ' ' << a[m + 1] << '\n';
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
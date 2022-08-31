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
    int m; cin >> m;
    vector<vector<int>> a(2, vector<int> (m));
    range(i, 2) range(j, m) cin >> a[i][j];
    vector<int> p(m);
    p[0] = 0;
    range(i, m - 1) p[i + 1] = p[i] + a[1][i];
    vector<int> s(m);
    for(int i = m - 1; i >= 1; --i) {
        s[i - 1] = s[i] + a[0][i];
    }
    int ans = INFi;
    range(i, m) {
        ans = min(ans, max(s[i], p[i]));
    }
    cout << ans << '\n';
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
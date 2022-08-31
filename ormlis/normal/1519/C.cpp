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
    int n; cin >> n;
    vector<vector<int>> to(n);
    vector<int> u(n);
    range(i, n) {
        cin >> u[i];
        u[i]--;
    }
    range(i, n) {
        int x; cin >> x;
        to[u[i]].push_back(x);
    }
    vector<ll> ans(n + 1, 0);
    range(i, n) {
        int sz = to[i].size();
        if (sz == 0) continue;
        sort(rall(to[i]));
        vector<ll> p(sz + 1);
        p[0] = to[i][0];
        for(int j = 1; j < sz; ++j) p[j] = p[j - 1] + to[i][j];
        for(int k = 1; k <= sz; ++k) {
            ans[k] += p[sz-(sz % k) - 1];
        }
    }
    for(int k = 1; k <= n; ++k) cout << ans[k] << ' ';
    cout << '\n';
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
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
    int n, m; cin >> n >> m;
    vector<vector<pair<int, int>>> to(n + m + 1);
    for(int i = 1; i <= n; ++i) for(int j = 1; j <= m; ++j) to[i + j].emplace_back(i, j);
    int l = 2;
    int r = n + m;
    while(r > l) {
        reverse(all(to[r]));
        assert(to[l].size() == to[r].size());
        range(i, (int)to[l].size()) {
            cout << to[l][i].first << ' ' << to[l][i].second << '\n';
            cout << to[r][i].first << ' ' << to[r][i].second << '\n';
        }
        r--;
        l++;
    }
    if (l == r) {
        int sz = to[l].size();
        range(i, (sz + 1) / 2) {
            cout << to[l][i].first << ' ' << to[l][i].second << '\n';
            if (i * 2 + 1 != sz) cout << to[l][sz - 1 - i].first << ' ' << to[l][sz - 1 - i].second << '\n';
        }
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
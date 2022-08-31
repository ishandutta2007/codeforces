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
    string t = "abc";
    int n, m; cin >> n >> m;
    string s; cin >> s;
    vector<vector<int>> dp;
    do {
        vector<int> cur(n);
        int res = 0;
        range(i, n) {
            if (s[i] != t[i % 3]) res++;
            cur[i] = res;
        }
        dp.push_back(cur);
    } while(next_permutation(all(t)));
    range(_, m) {
        int l, r; cin >> l >> r;
        l--; r--;
        int ans = INFi;
        range(j, (int)dp.size()) {
            int cur = dp[j][r];
            if (l) cur -= dp[j][l - 1];
            ans = min(ans, cur);
        }
        cout << ans << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    // cout << setprecision(15) << fixed;
    int tests = 1;
    //cin >> tests;
    range(_, tests) {
        solve();
    }
    return 0;
}
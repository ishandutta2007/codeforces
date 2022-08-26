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
const int md = 31607;
const ll INF = 2e18;

double getTime() { return clock() / (double) CLOCKS_PER_SEC; }


void solve() {
    string s, t;
    cin >> s >> t;
    int n = s.size();
    int m = t.size();
    vector<vector<int>> dp(n, vector<int>(m + 1));
    range(i, n) {
        if (t[0] == s[i]) {
            dp[i][1] = 1;
        }
        if (i != 0) {
            for (int j = 1; j < m; ++j) {
                if (t[j] == s[i] && dp[i - 1][j]) {
                    dp[i][j + 1] = 1;
                }
            }
        }
        if (dp[i][m]) {
            cout << "YES\n";
            return;
        }
    }
    for (int i = n - 2; i >= 0; --i) {
        for (int j = 1; j < m; ++j) {
            if (t[j] == s[i] && dp[i + 1][j]) {
                dp[i][j + 1] = 1;
            }
        }
        if (dp[i][m]) {
            cout << "YES\n";
            return;
        }
    }
    cout << "NO\n";
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
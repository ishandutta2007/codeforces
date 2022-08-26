#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>

#define range(i, n) for (int i = 0; i < (n); ++i)
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define ar array
using namespace std;

/*
using namespace __gnu_pbds;

typedef tree<
        pair<int, int>,
        null_type,
        less<pair<int, int>>,
        rb_tree_tag,
        tree_order_statistics_node_update>
        ordered_set;
*/

typedef long long ll;
typedef double ld;
typedef unsigned long long ull;

const int INFi = 1e9 + 5;
const int md = 998244353;
const ll INF = 2e18;
const int maxN = 5e5 + 1;

double getTime() { return clock() / (double) CLOCKS_PER_SEC; }

vector<int> Zfunc(string &s) {
    int n = s.size();
    vector<int> z(n);
    int l = 0, r = 0;
    for(int i = 1; i < n; ++i) {
        if (i < r) {
            z[i] = min(r - i, z[i - l]);
        }
        while(i + z[i] < n && s[z[i]] == s[i + z[i]]) z[i]++;
        if (i + z[i] > r) {
            r = i + z[i];
            l = i;
        }
    }
    return z;
}

void solve() {
    int n; cin >> n;
    string s; cin >> s;
    vector<vector<int>> dp(n, vector<int> (n, 0));
    range(i, n) {
        string w = s.substr(i) + "$" + s;
        auto z = Zfunc(w);
        int start = n - i + 1;
        int R = 0;
        dp[i][0] = 1;
        range(j, i) {
            int len = z[start + j];
            while(R < len) {
                dp[i][R] = max(dp[i][R], dp[j][R]);
                R++;
            }
            if (i + len < n && j + len < n && s[i + len] > s[j + len]) {
                dp[i][len] = max(dp[i][len], dp[j][n - j - 1] + 1);
            }
        }
        for(int j = 1; i + j < n; ++j) dp[i][j] = max(dp[i][j], dp[i][j - 1] + 1);
    }
    int mx = 0;
    range(i, n) range(j, n) mx = max(mx, dp[i][j]);
    cout << mx << '\n';
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
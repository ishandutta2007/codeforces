#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int N = 3e5+10, MOD = 1e9+7;

ll count_slime(ll t, int x, int y) {
    vector<vector<ll>> dp(x + 1, vector<ll>(y + 1));
    dp[0][0] = t;
    for (int i = 0; i <= x; i++) {
        for (int j = 0; j <= y; j++) {
            if (i) dp[i][j] += dp[i-1][j] / 2;
            if (j) dp[i][j] += (dp[i][j-1] + 1) / 2;
        }
    }
    return dp[x][y];
}
void solve() {
    ll t; int x, y; cin >> t >> x >> y;
    cout << (count_slime(t - x - y + 1, x, y) > count_slime(t - x - y, x, y) ? "YES\n" : "NO\n");
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T = 1;
    cin >> T;
    while (T--) solve();
}
#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int N = 2e5+10, MOD = 1e9+7;

void solve() {
    int n; cin >> n;
    vector<int> dp(n);
    int x = 0;
    map<int, int> mp;
    mp[0] = 0;
    for (int i = 0; i < n; i++) {
        int c; cin >> c;
        x ^= c;

        if (i) dp[i] = dp[i-1];
        if (mp.count(x)) {
            dp[i] = max(dp[i], mp[x] + 1);
        }
        mp[x] = max(mp[x], dp[i]);
    }
    cout << n - dp[n-1] << '\n';
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T = 1;
    cin >> T;
    while (T--) solve();
}
#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int N = 1e5+10, MOD = 1e9+7;

void solve() {
    int n; cin >> n;
    vector<int> a(n); for (auto& x : a) cin >> x, --x;
    vector<int> dp(n, -MOD);
    int ans = 0;
    for (int i = 0; i < n; i++) {
        vector<int> cnt(n);
        int max_freq = 0;
        for (int j = i-1; ; j--) {
            if (j < 0 || a[j] == a[i]) {
                int len = i - j - 1;
                if (2 * max_freq <= len && len % 2 == 0) {
                    dp[i] = max(dp[i], 1 + (j >= 0 ? dp[j] : 0));
                }
            }
            if (j < 0) break;
            max_freq = max(max_freq, ++cnt[a[j]]);
        }
        std::fill(cnt.begin(), cnt.end(), 0);
        max_freq = 0;
        for (int j = i+1; j < n; j++) {
            max_freq = max(max_freq, ++cnt[a[j]]);
        }
        int len = n - i - 1;
        if (2 * max_freq <= len && len % 2 == 0)
            ans = max(ans, dp[i]);
    }
    cout << ans << '\n';
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T = 1;
    cin >> T;
    while (T--) solve();
}
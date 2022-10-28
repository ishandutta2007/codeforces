#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int N = 6e5+10, MOD = 1e9+7;

bitset<N> dp;

void solve() {
    int n, d; cin >> n >> d;
    dp[0] = 1;
    while (n--) {
        int x; cin >> x;
        dp |= dp << x;
    }
    int ans = 0;
    int cnt = 0;
    int start = 0;
    for (int i = 0; i < N; ) {
        ans = i;
        cnt++;

        int best = i;
        for (int j = max(start, i); j <= i + d; j++) if (dp[j]) best = j;
        if (best == i) break;
        start = i + d - 1;
        i = best;
    }
    cout << ans << ' ' << cnt - 1 << '\n';
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int MAXN = 5e3+10, MOD = 1e9+7;

int n, k, a[MAXN];
int dp[MAXN][MAXN];

void solve(){
    cin >> n >> k;
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a, a+n);

    for (int i = n-1; i >= 0; i--) {
        int nxt = upper_bound(a, a+n, a[i]+5)-a;
        for (int j = 1; j <= k; j++) {
            dp[i][j] = max(dp[i][j], nxt-i+dp[nxt][j-1]);
            dp[i][j] = max(dp[i][j], dp[i+1][j]);
        }
    }
    int ans = 0;
    for (int i = 1; i <= k; i++) ans = max(ans, dp[0][i]);
    cout << ans << '\n';
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int T=1;
    //cin >> T;
    while (T--) solve();
}
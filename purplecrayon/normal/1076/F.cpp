#include "bits/stdc++.h"
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int MAXN = 3e5+10, MOD = 1e9+7;

int n;
ll a[MAXN], b[MAXN], dp[MAXN][2], k;

void solve(){
    cin >> n >> k;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];
    for (int i = 0; i < n; i++) {
        dp[i][0] = a[i]-b[i]*k+dp[i-1][0];
        dp[i][1] = b[i]-a[i]*k+dp[i-1][1];
        dp[i][0] = max(dp[i][0], 0ll), dp[i][1] = max(dp[i][1], 0ll);
    }
    for (int i = 0; i < n; i++) for (int j : {0, 1})
        if (dp[i][j] > k) {
            cout << "NO\n";
            return;
        }

    cout << "YES\n";
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int T=1;
    //cin >> T;
    while (T--) solve();
}
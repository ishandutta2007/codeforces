#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int MAXN = 5e2+10, MOD = 1e9+7;

int n, a[MAXN], dp[MAXN][MAXN];
int dp_ans[MAXN];

void solve(){
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    memset(dp, -1, sizeof(dp));
    for (int l = n-1; l >= 0; l--) {
        for (int r = l; r < n; r++) {
            if (l == r) dp[l][r] = a[l|r];
            else {
                for (int m = l; m < r; m++) {
                    if (dp[l][m] != -1 && dp[m+1][r] != -1 && dp[l][m] == dp[m+1][r])
                        dp[l][r] = (dp[l][m]|dp[m+1][r])+1;
                }
            }
        }
    }
    for (int i = 0; i < n; i++) {
        dp_ans[i] = n;
        for (int j = i; j >= 0; j--) if (dp[j][i] != -1) {
            dp_ans[i] = min(dp_ans[i], (j?dp_ans[j-1]:0)+1);
        }
    }
    cout << dp_ans[n-1] << '\n';
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int T=1;
    //cin >> T;
    while (T--) solve();
}
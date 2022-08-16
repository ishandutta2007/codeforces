#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int MAXN = 3e3+10, MOD = 1e9+7;

int n, a[MAXN];
vector<int> loc[MAXN];
int dp[MAXN][MAXN];

void solve() {
    cin >> n;
    for (int i = 0; i < n; i++) loc[i].clear();
    for (int i = 0; i < n; i++) {
        cin >> a[i], --a[i];
        loc[a[i]].push_back(i);
    }
    for (int r = 0; r < n; r++) {
        for (int l = r; l >= 0; l--) {
            if (l == r) { dp[l][r] = 1; continue; }
            dp[l][r] = MOD;
            for (int k : loc[a[l]]) if (l <= k && k <= r) {
                if (k < r) dp[l][r] = min(dp[l][r], dp[l][k] + dp[k+1][r]);
                if (k > l) dp[l][r] = min(dp[l][r], dp[l+1][k-1] + dp[k][r]);
            }
        }
    }
    cout << dp[0][n-1] - 1 << '\n';
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int T=1;
    cin >> T;
    while (T--) solve();
}
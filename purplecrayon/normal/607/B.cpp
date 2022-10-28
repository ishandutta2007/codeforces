#include <bits/stdc++.h>
using namespace std;

#define sz(v) (int)v.size()
// #define f first
// #define s second
typedef vector<int> vi;
typedef long long ll;
typedef long double ld;
const int MAXN = 510, MAXM = 2e5+10, MAXL = 20, ALP = 26, INF = 1e9+10, MOD = 1e9+7;
const string  no = "NO\n", yes = "YES\n";
const int hA[4] = {1, 0, -1, 0}, kA[4] = {0, 1, 0, -1};
// const ll INF = 1e18+10;

int n, a[MAXN], pal[MAXN][MAXN], dp[MAXN][MAXN];

void solve(){
    int n; cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++){
        for (int j = i; j < n; j++){
            bool bad = 0;
            for (int k1=i, k2=j; k1 <= k2 && !bad; k1++, k2--){
                if (a[k1] != a[k2]) bad = 1;
            }
            pal[i][j] = !bad;
        }
    }
    memset(dp, 0, sizeof(dp));
    for (int i = n-1; i >= 0; i--){
        for (int j = i; j < n; j++){
            dp[i][j] = (pal[i][j] ? 1 : INF);
            // if (i < j) dp[i][j] = min(dp[i][j], min(1+dp[i+1][j], 1+dp[i][j-1]));
            for (int k = i; k < j; k++){
                dp[i][j] = min(dp[i][j], dp[i][k]+dp[k+1][j]);
            }
            for (int k = i+2; k <= j; k++) if (a[i] == a[k]) {
                dp[i][j] = min(dp[i][j], dp[i+1][k-1]+dp[k+1][j]);
            }
        }
    }
    cout << dp[0][n-1];
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int t=1; 
    // cin >> t; 
    while (t--) solve();
}
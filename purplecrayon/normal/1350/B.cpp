#include <bits/stdc++.h>
using namespace std;

#define sz(v) (int)v.size()
// #define f first
// #define s second
typedef vector<int> vi;
typedef long long ll;
typedef long double ld;
const int MAXN = 4e3+10, MAXM = 2e5+10, MAXL = 20, ALP = 26, INF = 1e9+10, MOD = 1e9+7, MAXK = 810;
const string  no = "NO\n", yes = "YES\n";
const int hA[4] = {1, 0, -1, 0}, kA[4] = {0, 1, 0, -1};
// const ll INF = 1e18+10;

void solve(){
    int n; cin >> n;
    vector<int> a(n, 0); for (auto& it : a) cin >> it;
    vector<int> dp(n, 1);
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j*j <= i; j++) if (i%j == 0 && a[j-1] < a[i-1]) {
            //consider j, i indices
            dp[i-1] = max(dp[i-1], dp[j-1]+1);
        }
        for (int j = 1; j*j <= i; j++) if (i%j == 0 && a[(i/j)-1] < a[i-1]){
            //consider i/j, i indices
            dp[i-1] = max(dp[i-1], dp[(i/j)-1]+1);
        }
        ans = max(ans, dp[i-1]);
    }
    cout << ans << "\n";
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int t=1; 
    cin >> t; 
    while (t--) solve();
}
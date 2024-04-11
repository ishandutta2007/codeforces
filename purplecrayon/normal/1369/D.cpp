#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
const int MAXN = 2e6+10, ALP = 26, MAXL = 20, INF = 1e9+10, MOD = 1e9+7;

ll n, dp[MAXN];

void solve(){
    cin >> n;
    cout << dp[n] << "\n";
}
int main(){
    int t=1;cin >> t;
    dp[0] = dp[1] = 0;
    for (int i = 2; i <= MAXN-1; i++){
        dp[i] = (2*dp[i-2]+dp[i-1]+(i%3==0?4:0))%MOD;
    }
    while (t--) solve();
}
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MAXN = 1e5+10, ALP=27;

int a[MAXN];
bool dp[MAXN][2];

void solve(){
    int n; cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    memset(dp, 0, sizeof(dp));
    dp[n-1][0] = dp[n-1][1] = 1;
    for (int i = n-2; i >= 0; i--){
        if (a[i+1]!=1) dp[i][1] = !dp[i+1][0];
        else dp[i][1] = !dp[i+1][1];
        if (a[i] != 1){
            if(a[i+1] != 1) dp[i][0] = (!dp[i][1])||(!dp[i+1][0]);
            else dp[i][0] = (!dp[i][1])||(!dp[i+1][1]);
        }
    }
    // cout << n << "\n";
    // for (int i = 0; i < n; i++) cout << dp[i][0] << " " << dp[i][1] << "\n";
    int ans = dp[0][0];
    if (a[0] == 1) ans = dp[0][1];
    cout << (ans?"First\n":"Second\n");
}

int main(){
    int t; cin >> t;
    while (t--) solve();
}
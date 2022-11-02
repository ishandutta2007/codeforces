#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<int> a;
    int last = -1;
    for(int i = 0;i < n;i++) {
        int now;
        cin >> now;
        if (now != last) a.push_back(now);
        last = now;
    }
    n = a.size();
    vector<vector<int>> dp;
    dp.resize(n);
    for(int i = 0;i < n;i++) dp[i].resize(n,10000);
    dp[0][n - 1] = 0;
    for(int l = 0;l < n;l++) {
        if (l != 0) dp[l][n - 1] = dp[l - 1][n - 1] + 1;
        for(int r = n - 2;r >= l;r--) {
            if (l == 0) {
                dp[l][r] = dp[l][r + 1] + 1;
            }else {
                dp[l][r] = min(dp[l - 1][r], dp[l][r + 1]) + 1;
                if (a[r + 1] == a[l - 1]) dp[l][r] = dp[l - 1][r + 1] + 1;
            }
        }
    }
    int ans = 100000;
    for(int i = 0;i < n;i++) ans = min(ans,dp[i][i]);
    cout << ans;
}
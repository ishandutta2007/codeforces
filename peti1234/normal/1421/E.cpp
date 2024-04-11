#include <bits/stdc++.h>

using namespace std;
long long dp[200002][3][2][2], n, k;
int main()
{
    cin >> n >> k;
    if (n==1) {cout << k << "\n"; return 0;}
    for (int i=0; i<3; i++) for (int j=0; j<2; j++) for (int k=0; k<2; k++) dp[1][i][j][k]=-1e18;
    dp[1][1][0][0]=-k, dp[1][0][1][0]=k;
    for (int i=2; i<=n; i++) {
        cin >> k;
        for (int j=0; j<3; j++) {
            int el=(j+2)%3;
            dp[i][j][0][0]=dp[i-1][el][1][0]-k;
            dp[i][j][1][0]=dp[i-1][j][0][0]+k;
            dp[i][j][0][1]=max({dp[i-1][j][0][1]+k, dp[i-1][el][0][1]-k, dp[i-1][j][1][0]+k, dp[i-1][el][0][0]-k});
        }
    }
    cout << dp[n][(4-n%3)%3][0][1] << "\n";
    return 0;
}
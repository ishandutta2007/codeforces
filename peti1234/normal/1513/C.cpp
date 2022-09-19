#include <bits/stdc++.h>

using namespace std;
const int c=200002, k=10;
long long mod=1e9+7, dp[k][k][c], w, n, m;
int main()
{
    for (int i=0; i<k; i++) {
        dp[i][i][0]=1;
    }
    for (int i=1; i<c; i++) {
        for (int kezd=0; kezd<k; kezd++) {
            for (int ert=0; ert<k; ert++) {
                dp[kezd][(ert+1)%k][i]+=dp[kezd][ert][i-1];
            }
            dp[kezd][1][i]+=dp[kezd][9][i-1];
        }
        for (int a=0; a<k; a++) {
            for (int b=0; b<k; b++) {
                dp[a][b][i]%=mod;
            }
        }
    }
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> w;
    while (w--) {
        cin >> n >> m;
        long long sum=0;
        while (n>0) {
            int a=n%10;
            n/=10;
            for (int s=0; s<k; s++) {
                sum+=dp[a][s][m];
            }
        }
        cout << sum%mod << "\n";
    }
    return 0;
}
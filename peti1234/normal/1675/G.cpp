#include <bits/stdc++.h>

using namespace std;
const int c=255;
int n, sum, t[c], dp[c][2*c][c], ans=1e6;
int main()
{
    cin >> n >> sum;
    for (int i=n; i>=1; i--) {
        cin >> t[i];
    }
    for (int i=1; i<=n; i++) {
        for (int j=0; j<=2*sum; j++) {
            for (int k=0; k<=sum; k++) {
                dp[i][j][k]=1e6;
            }
        }
    }
    for (int k=0; k<=sum; k++) {
        dp[1][t[1]+sum][k]=0;
    }
    for (int i=2; i<=n; i++) {
        for (int ert2=0; ert2<=2*sum; ert2++) {
            for (int el=0; el<=sum; el++) {
                int ert=ert2-sum, dif=ert-t[i], el2=el+dif+sum;
                if (0<=el2 && el2<=2*sum) {
                    dp[i][ert2][el]=min(dp[i][ert2][el], dp[i-1][el2][el]+abs(dif));
                }
                dp[i][ert2][el+1]=dp[i][ert2][el];

            }
        }
    }
    for (int j=sum; j<=2*sum; j++) {
        for (int k=0; k<=j-sum; k++) {
            ans=min(ans, dp[n][j][k]);
        }
    }
    cout << ans << "\n";
    return 0;
}
/*
8 16
5 1 0 2 2 2 2 2
*/
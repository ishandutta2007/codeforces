#include <bits/stdc++.h>

using namespace std;
int dp[22][12][4][4], n, t, sum;
int main()
{
    cin >> n >> t;
    for (int i=0; i<4; i++) {
        for (int j=i+1; j<4; j++) {
            dp[2][0][i][j]=1;
        }
    }
    for (int i=3; i<=n; i++) {
        for (int j=0; j<=t; j++) {
            for (int a=0; a<4; a++) {
                for (int b=0; b<4; b++) {
                    for (int c=0; c<4; c++) {
                        int alap=dp[i-1][j][a][b];
                        if (b!=c) {
                            if (b>max(a, c)) {
                                dp[i][j+1][b][c]+=alap;
                            } else {
                                dp[i][j][b][c]+=alap;
                            }
                        }
                    }
                }
            }
        }
    }
    for (int i=0; i<4; i++) {
        for (int j=0; j<i; j++) {
            sum+=dp[n][t][i][j];
        }
    }
    cout << sum << "\n";
    return 0;
}
#include <bits/stdc++.h>

using namespace std;
const int c=16, kk=(1<<c), sok=1e9;
int n, m, s[c][kk+1], dp[c][c][kk], el[c][c], utel[c][c], valasz;
// n, m, s feladatban
// dp[kezd][veg][mask]
// el[i][j] i-bl j-be minimlis l
// utel[i][j] i-bl j-be utols l
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    for (int i=0; i<n; i++) {
        for (int j=1; j<=m; j++) {
            cin >> s[i][j];
        }
    }
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            el[i][j]=sok, utel[i][j]=sok;
            for (int k=1; k<=m; k++) {
                el[i][j]=min(el[i][j], abs(s[i][k]-s[j][k]));
                if (k!=m) {
                    utel[i][j]=min(utel[i][j], abs(s[i][k]-s[j][k+1]));
                }
            }
        }
    }
    for (int i=0; i<n; i++) {
        dp[i][i][1<<i]=sok;
    }
    for (int mask=0; mask<(1<<n); mask++) {
        for (int kezd=0; kezd<n; kezd++) {
            for (int veg=0; veg<n; veg++) {
                // dp[kezd][veg][mask];
                // kezd -> ..... -> veg (11010101)
                for (int uj=0; uj<n; uj++) {
                    if ((mask&(1<<uj))==0) {
                        // uj csucs nincs benne a maskban
                        int s=mask+(1<<uj);
                        // dp[kezd][veg][mask], el[veg][uj]
                        dp[kezd][uj][s]=max(dp[kezd][uj][s], min(dp[kezd][veg][mask], el[veg][uj]));
                    }
                }
            }
        }
    }
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            valasz=max(valasz, min(dp[i][j][(1<<n)-1], utel[j][i]));
        }
    }
    cout << valasz << endl;
    return 0;
}
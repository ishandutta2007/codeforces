#include <bits/stdc++.h>

using namespace std;
#define rep(n) for (int i=1; i<=n; i++)
const long long c=5002, sok=1e15;
long long n, kezd, veg, hely[c];
long long balle[c], balfel[c], jobble[c], jobbfel[c];
long long dp[c][c];
int main()
{
    cin >> n >> kezd >> veg;
    rep(n) cin >> hely[i];
    rep(n) cin >> jobbfel[i];
    rep(n) cin >> balfel[i];
    rep(n) cin >> balle[i];
    rep(n) cin >> jobble[i];
    rep(n) dp[0][i]=sok;
    rep(n) for (int j=0; j<=n; j++) dp[i][j]=sok;
    rep(n) {
        for (int j=0; j<=n; j++) {
            int ki=j-(veg<i), be=j-(kezd<i);
            if (i==kezd) {
                dp[i][j+1]=min(dp[i][j+1], dp[i-1][j]+jobble[i]-hely[i]);
                if (j>1 || (j==1 && (veg>i || kezd==n))) dp[i][j]=min(dp[i][j], dp[i-1][j]+balle[i]+hely[i]);
            }
            else if (i==veg) {
                dp[i][j+1]=min(dp[i][j+1], dp[i-1][j]+balfel[i]-hely[i]);
                if (j>1 || (j==1 && (kezd>i || veg==n))) dp[i][j]=min(dp[i][j], dp[i-1][j]+jobbfel[i]+hely[i]);
            }
            else {
                dp[i][j+1]=min(dp[i][j+1], dp[i-1][j]+jobble[i]+balfel[i]-2*hely[i]);
                if (ki) dp[i][j]=min(dp[i][j], dp[i-1][j]+jobble[i]+jobbfel[i]);
                if (be) dp[i][j]=min(dp[i][j], dp[i-1][j]+balle[i]+balfel[i]);
                if (be && ki && (be+ki>2 || i==n)) dp[i][j-1]=min(dp[i][j-1], dp[i-1][j]+balle[i]+jobbfel[i]+2*hely[i]);
            }
        }
    }
    cout << dp[n][1] << "\n";
    return 0;
}
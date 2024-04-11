#include <bits/stdc++.h>

using namespace std;
const int c=105, c2=c*c;
int n, t[c], dif[c], mini[c];
long long dp[c][c2], kom[c][c2], sum, q, mod=1000000007;
map<int, long long> valasz;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    dp[0][0]=1;
    for (int i=0; i<c2; i++) {
        kom[0][i]=1;
    }
    for (int i=1; i<=n; i++) {
        cin >> t[i];
    }
    for (int i=2; i<=n; i++) {
        cin >> dif[i];
        sum+=dif[i];
        mini[i]=mini[i-1]+sum;
    }
    int kis=-mini[n]/n-10, nagy=kis+220;
    for (int ert=kis; ert<=nagy; ert++) {
        for (int i=1; i<=n; i++) {
            int x=t[i];
            int kell=mini[i]+i*ert;
            for (int j=0; j<c2; j++) {
                dp[i][j]=kom[i-1][j];
                if (j>x) {
                    dp[i][j]-=kom[i-1][j-x-1];
                }
                dp[i][j]+=mod, dp[i][j]%=mod;
                if (j<kell) {
                    dp[i][j]=0;
                }
                kom[i][j]=dp[i][j];
                if (j) {
                    kom[i][j]+=kom[i][j-1];
                    kom[i][j]%=mod;
                }
            }
        }
        valasz[ert]=kom[n][c2-1];
    }
    int q;
    cin >> q;
    while (q--) {
        int ert;
        cin >> ert;
        ert=max(kis, min(ert, nagy));
        cout << valasz[ert] << "\n";
    }
    return 0;
}
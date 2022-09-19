#include <bits/stdc++.h>

using namespace std;
const int c=105;
long long mod, dp[c][c][c], alatt[c][c];
bool v[c][c][c];
long long solve(int len, int db, int ert) {
    ert=max(ert, 0);
    if (ert==1 && len>=1) {
        db--;
    }
    if (len==0 || db<0 || db>len || db>0 && db+ert>len+1 || db>len/2+1) {
        return (db==0 ? 1 : 0);
    }
    if (!v[len][db][ert]) {
        long long sum=0;
        for (int pos=1; pos<=len; pos++) {
            for (int db2=0; db2<=db; db2++) {
                sum+=solve(pos-1, db2, ert-1)*solve(len-pos, db-db2, ert-1)%mod*alatt[len-1][pos-1]%mod;
            }
        }
        dp[len][db][ert]=sum%mod;
        v[len][db][ert]=1;
    }
    return dp[len][db][ert];
}
int main()
{
    ios_base::sync_with_stdio(false);
    int n, m, k;
    cin >> n >> m >> k >> mod;
    alatt[0][0]=1;
    for (int i=1; i<=n; i++) {
        for (int j=0; j<=i; j++) {
            alatt[i][j]=(alatt[i-1][j]+(j>0 ? alatt[i-1][j-1] : 0))%mod;
        }
    }
    cout << solve(n, k, m) << "\n";
    return 0;
}
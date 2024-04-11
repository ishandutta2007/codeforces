#include <bits/stdc++.h>

typedef long long ll;
using namespace std;
int MOD;
ll dp1[404][404], dp2[404][404], dp3[404][404];
ll DP[404], ans[404];
ll comb[808][808];

int main(){
    int n;
    scanf("%d %d", &n, &MOD);
    for (int i=1;i<808;i++){
        comb[i][0] = 1, comb[i][i] = 1;
        for (int j=1;j<i;j++) comb[i][j] = (comb[i-1][j-1]+comb[i-1][j])%MOD;
    }
    dp1[2][1] = 1, dp2[2][2] = 1;
    DP[1] =  1, DP[2] = 2;
    for (int i=3;i<=n;i++){
        for (int j=1;j<=i-1;j++){
            for (int k=j+1;k<=i;k++) dp2[i][k] = (dp2[i][k]+dp2[i-1][j]+dp1[i-1][j])%MOD;
            for (int k=1;k<=j;k++) dp1[i][k] = (dp1[i][k]+dp1[i-1][j])%MOD;
        }
        for (int j=1;j<=i;j++) DP[i] = (DP[i]+dp1[i][j]+dp2[i][j])%MOD;
    }
    dp3[1][1] = 1, dp3[2][2] = 2;
    for (int i=3;i<=n;i++){
        dp3[i][i] = DP[i];
        for (int x=2;x<=i-1;x++){
            for (int j=1;j<=x-1;j++) dp3[i][j+i-x] = (dp3[i][j+i-x]+((dp3[x-1][j]*DP[i-x])%MOD*comb[j+i-x][i-x])%MOD)%MOD;
        }
        for (int j=1;j<=i;j++) ans[i] = (ans[i]+dp3[i][j])%MOD;
    }
    printf("%lld\n", ans[n]);
    return 0;
}
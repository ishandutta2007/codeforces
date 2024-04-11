#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int MOD = 998244353;
string a, b;
int dp[1010][1010][2];

int add(int a, int b){
    int ret = a+b;
    if (ret>=MOD) return ret-MOD;
    else return ret;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> a >> b;
    int n = a.size(), m = b.size();
    for (int i=1;i<=n;i++){
        dp[i][0][1] = 0;
        dp[i][0][0] = 1;
        if (i>1 && a[i-1]!=a[i-2]) dp[i][0][0] = add(dp[i][0][0], dp[i-1][0][0]);
        //printf("%d: %d\n", i, dp[i][0][0]);
    }
    int ans=0;
    for (int j=1;j<=m;j++){
        dp[0][j][0] = 0;
        dp[0][j][1] = 1;
        if (j>1 && b[j-1]!=b[j-2]) dp[0][j][1] = add(dp[0][j][1], dp[0][j-1][1]);
        for (int i=1;i<=n;i++){
            if (a[i-1]!=b[j-1]) dp[i][j][0] = add(dp[0][j][1], dp[i-1][j][1]), dp[i][j][1] = add(dp[i][0][0], dp[i][j-1][0]);
            if (i==1 && a[i-1]!=b[j-1]) dp[i][j][0] = (dp[i][j][0]+MOD-dp[0][j][1])%MOD;
            if (j==1 && a[i-1]!=b[j-1]) dp[i][j][1] = (dp[i][j][1]+MOD-dp[i][0][0])%MOD;
            if (i>1 && a[i-1]!=a[i-2]) dp[i][j][0] = add(dp[i][j][0], dp[i-1][j][0]);
            if (j>1 && b[j-1]!=b[j-2]) dp[i][j][1] = add(dp[i][j][1], dp[i][j-1][1]);
            //printf("%d %d: %d %d\n", i, j, dp[i][j][0], dp[i][j][1]);
            ans = add(ans, add(dp[i][j][0], dp[i][j][1]));
        }
    }
    printf("%d\n", ans);
    return 0;
}
#include <bits/stdc++.h>

typedef long long ll;
using namespace std;
const int MOD = 1e9+7;
ll dp[101][10010];
int a[101], b[101];

int main(){
    int n;
    scanf("%d", &n);
    for (int i=0;i<n;i++){
        scanf("%d", a+i);
    }
    for (int i=0;i<n-1;i++){
        scanf("%d", b+i);
    }
    int q, x;
    scanf("%d %d", &q, &x);
    ll S = x;
    for (int j=max(x, 0);j<=a[0];j++) dp[0][j] = 1;
    for (int i=1;i<n;i++){
        x += b[i-1];
        S += x;
        for (int j=max(S, 0LL);j<10010;j++){
            for (int k=0;k<=a[i];k++){
                if (j-k<0) break;
                dp[i][j] += dp[i-1][j-k];
                if (dp[i][j]>=MOD) dp[i][j] -= MOD;
            }
        }
    }
    ll ans = 0;
    for (int j=0;j<10010;j++){
        ans += dp[n-1][j];
        if (ans>=MOD) ans -= MOD;
    }
    printf("%lld\n", ans);

    return 0;
}
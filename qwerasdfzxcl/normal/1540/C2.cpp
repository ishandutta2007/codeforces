#include <bits/stdc++.h>

typedef long long ll;
using namespace std;
const int MOD = 1e9+7;
ll dp[101][10011], ans[202000];
int a[101], b[101], n;

void solve(int x){
    int X = x;
    ll S = x;
    for (int i=0;i<=n;i++) fill(dp[i], dp[i]+10011, 0);
    for (int j=max(x, 0);j<=a[0];j++) dp[0][j] = 1;
    for (int i=1;i<n;i++){
        x += b[i-1];
        S += x;
        ll cur = 0;
        for (int k=0;k<=a[i];k++){
            if (max(S, 0LL)-k<0) break;
            cur += dp[i-1][max(S, 0LL)-k];
            if (cur>=MOD) cur -= MOD;
        }
        for (int j=max(S, 0LL);j<10010;j++){
            dp[i][j] = cur;
            cur += dp[i-1][j+1];
            if (j-a[i]>=0) cur -= dp[i-1][j-a[i]];
            cur %= MOD;
            if (cur<0) cur += MOD;
        }
    }
    for (int j=0;j<10010;j++){
        ans[X+100100] += dp[n-1][j];
        if (ans[X+100100]>=MOD) ans[X+100100] -= MOD;
    }
}

int main(){
    scanf("%d", &n);
    ll tmp2 = 0;
    for (int i=0;i<n;i++){
        scanf("%d", a+i);
        tmp2 += a[i];
    }
    for (int i=0;i<n-1;i++){
        scanf("%d", b+i);
    }
    int x = 100100;
    ll S = x, X = x;
    for (int i=1;i<n;i++){
        X += b[i-1];
        S += X;
    }
    while(S>tmp2){
        x--; S -= n;
    }
    for (int i=0;i<111;i++) solve(x-i);
    x -= 111;
    for (;x+100100>=0;x--) ans[x+100100] = ans[x+100101];

    int q;
    scanf("%d", &q);
    while(q--){
        int tmp;
        scanf("%d", &tmp);
        printf("%lld\n", ans[tmp+100100]);
    }
    return 0;
}
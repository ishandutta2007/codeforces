#include <bits/stdc++.h>

typedef long long ll;
using namespace std;
const int SHIFT = 150000;
int MOD;
ll dp[300300], S[300300], dp2[300300], S2[300300];

void get_prfsum(){
    S[0] = dp[0];
    for (int i=1;i<300300;i++){
        S[i] = (S[i-1]+dp[i]);
        if (S[i]>=MOD) S[i] -= MOD;
    }
    S2[0] = dp2[0];
    for (int i=1;i<300300;i++){
        S2[i] = (S2[i-1]+dp2[i]);
        if (S2[i]>=MOD) S2[i] -= MOD;
    }
}

int main(){
    int n;
    scanf("%d %d", &n, &MOD);
    if (n==1){
        printf("0\n"); return 0;
    }

    ll *a = dp+SHIFT, *b = S+SHIFT, *c = dp2+SHIFT, *d = S2+SHIFT;
    c[-1] = 1;
    c[0] = 2;
    c[1] = 1;
    a[-1] = 1;
    get_prfsum();
    for (int i=3;i<=n;i++){
        int mx = i*(i-1)/2;
        ll cur = a[mx]*i%MOD;
        for (int j=mx;j>=-mx;j--){
            ll tmp = a[j];
            a[j] = cur;
            cur += (c[j]-tmp)*i%MOD;
            cur -= (d[j+i-1] - d[j-1]);
            cur += a[j-1]*i%MOD;
            cur %= MOD;
            if (cur<0) cur += MOD;
        }

        cur = 0;
        for (int j=i;j>0;j--) cur = (cur+c[mx-(i-j)]*j)%MOD;
        for (int j=mx;j>=-mx;j--){
            c[j] = cur;
            cur -= (d[j+i-1] - d[j-1]);
            cur += (d[j-1] - d[j-i-1]);
            cur %= MOD;
            if (cur<0) cur += MOD;
        }
        get_prfsum();
    }
    ll ans = (S[300299] - b[0]+MOD);
    if (ans>=MOD) ans -= MOD;
    printf("%lld\n", ans);
    return 0;
}
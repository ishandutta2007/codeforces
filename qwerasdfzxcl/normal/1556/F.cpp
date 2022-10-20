#include <bits/stdc++.h>

typedef long long ll;
using namespace std;
const int MOD = 1e9+7;
int n;
ll a[20], dp[1<<20], dp2[1<<20], vs[20][20], ans = 0;

ll pw(ll t, ll e){
    if (!e) return 1;
    ll ret = pw(t, e/2);
    if (e&1) return ret*ret%MOD*t%MOD;
    return ret*ret%MOD;
}

ll INV(ll x){return pw(x, MOD-2);}

void solve(int x){
    ll val = 1;
    for (int z=1;z<(1<<n)-1;z++) if (!(z&(1<<x))){
        val -= dp2[z];
        if (val<0) val += MOD;
    }
    ans += val;
    if (ans>=MOD) ans -= MOD;
}

void init(){
    for (int i=0;i<n;i++){
        for (int j=0;j<n;j++){
            vs[i][j] = a[i]*INV(a[i]+a[j])%MOD;
        }
    }
    for (int z=0;z<(1<<n);z++){
        dp[z] = 1;
        for (int i=0;i<n;i++) if (z&(1<<i)){
            for (int j=0;j<n;j++) if (!(z&(1<<j))){
                dp[z] *= vs[i][j];
                dp[z] %= MOD;
            }
        }
    }
    for (int z=1;z<(1<<n)-1;z++){
        dp2[z] = dp[z];
        for (int i=z;i>0;i=(i-1)&z) if (i!=z){
            ll tmp = dp2[i];
            for (int j=0;j<n;j++) if (z&(1<<j) && !(i&(1<<j))){
                for (int k=0;k<n;k++) if (!(z&(1<<k))){
                    tmp *= vs[j][k];
                    tmp %= MOD;
                }
            }
            dp2[z] -= tmp;
            if (dp2[z]<0) dp2[z] += MOD;
        }
    }
}

int main(){
    scanf("%d", &n);
    for (int i=0;i<n;i++) scanf("%lld", a+i);
    if (n==1) {printf("1\n"); return 0;}
    init();
    for (int i=0;i<n;i++) solve(i);
    printf("%lld\n", ans);
    return 0;
}
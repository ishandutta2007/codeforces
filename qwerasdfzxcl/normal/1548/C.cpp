#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")

typedef long long ll;
using namespace std;
const int MOD = 1e9+7;
ll fact[3003000], dp[3003000], ncr30[3003000], ncr31[3003000], INV[3003000];

ll pw(ll a, int e){
    if (!e) return 1;
    ll ret = pw(a, e/2);
    if (e&1) return ret*ret%MOD*a%MOD;
    return ret*ret%MOD;
}

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n, q;
    cin >> n >> q;
    for (int i=1;i<=3*n+1;i++) INV[i] = pw(i, MOD-2);
    ncr30[0] = 1;
    for (int i=1;i<=3*n;i++){
        ncr30[i] = ncr30[i-1]*(n*3-i+1)%MOD*INV[i]%MOD;
    }
    ncr31[0] = 1;
    for (int i=1;i<=3*n+1;i++){
        ncr31[i] = ncr31[i-1]*(n*3-i+2)%MOD*INV[i]%MOD;
    }

    dp[0] = n+1;
    for (int i=1;i<=3*n;i++){
        ll tmp = ncr31[i+1];
        ll tmp2 = (dp[i-1]-ncr30[i-1])*3%MOD;
        ll tmp3 = 0;
        if (i>=2) tmp3 = dp[i-2] - ncr30[i-2];
        ll tmp4 = ncr30[i]*2%MOD;
        if (tmp2<0) tmp2 += MOD;
        if (tmp3<0) tmp3 += MOD;

        //printf("%lld %lld %lld %lld\n", tmp, tmp2, tmp3, tmp4);

        dp[i] = (tmp - tmp2 - tmp3 + tmp4)%MOD * INV[3]%MOD;
        if (dp[i]<0) dp[i] += MOD;
    }
    //for (int i=0;i<=n*3;i++) printf("%lld ", dp[i]);
    //printf("\n");
    while(q--){
        int x;
        cin >> x;
        cout << dp[x] << '\n';
    }
    return 0;
}
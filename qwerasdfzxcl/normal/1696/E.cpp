#include <bits/stdc++.h>

typedef long long ll;
using namespace std;
const int MOD = 1e9+7;
ll fact[400400], factINV[400400];

ll pw(ll a, ll e){
    if (!e) return 1;
    ll ret = pw(a, e/2);
    if (e&1) return ret * ret %MOD *a %MOD;
    return ret*ret%MOD;
}

ll INV(ll x){return pw(x, MOD-2);}

ll ncr(ll n, ll r){
    return fact[n] * factINV[r] % MOD * factINV[n-r] % MOD;
}

int main(){
    fact[0] = 1;
    factINV[0] = 1;
    for (int i=1;i<400400;i++) fact[i] = fact[i-1] * i % MOD;
    factINV[400399] = INV(fact[400399]);
    for (int i=400398;i;i--) factINV[i] = factINV[i+1] * (i+1) % MOD;

    int n;
    scanf("%d", &n);
    ll ans = 0;
    for (int i=0;i<=n;i++){
        int x;
        scanf("%d", &x);
        if (x==0) continue;
        ans += ncr(i+x, i+1);
        if (ans >= MOD) ans -= MOD;
    }
    printf("%lld\n", ans);
    return 0;
}
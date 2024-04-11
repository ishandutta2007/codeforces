#include <bits/stdc++.h>

typedef long long ll;
using namespace std;
const int MOD = 998244353;
int a[100100];
ll fact[100100], factINV[100100];

ll pw(ll a, ll e){
    if (!e) return 1;
    ll ret = pw(a, e/2);
    if (e&1) return ret*ret%MOD*a%MOD;
    return ret*ret%MOD;
}

ll INV(ll x){return pw(x, MOD-2);}

ll ncr(ll n, ll r){
    return fact[n] * factINV[n-r] % MOD * factINV[r] % MOD;
}

ll calc(int x, int y){
    //printf("calc %d %d\n", x, y);
    ll ret = 0;
    if (x > y) swap(x, y);
    for (int i=0;i<=x;i++) ret = (ret + ncr(x, i) * ncr(y, i) % MOD) % MOD;
    return ret;
}

void solve(){
    int n;
    scanf("%d", &n);

    ll S = 0;
    for (int i=1;i<=n;i++){
        scanf("%d", a+i);
        S += a[i];
    }

    if (S==0) {printf("%lld\n", pw(2, n-1)); return;}

    ll curf = 0, curb = 0, pt = n, ans = 1;
    for (int i=1, r=1;i<=n;i=r){
        curf += a[i];
        if (curf*2 >= S) break;

        int cnt1 = 1, cnt2 = 0;

        ++r;
        while(r<=n && a[r]==0) ++r, ++cnt1;

        while(curb < curf) {curb += a[pt]; pt--;}
        if (curb!=curf) continue;

        cnt2 = 1;
        while(pt && a[pt]==0) pt--, cnt2++;
        if (curb==0) cnt2--;

        ans = ans * calc(cnt1, cnt2) % MOD;
    }

    int cnt = 0;
    curf = 0;
    for (int i=1;i<=n;i++){
        curf += a[i];
        if (curf*2==S) cnt++;
    }

    ans = ans * pw(2, cnt) % MOD;
    printf("%lld\n", ans);
}

int main(){
    fact[0] = factINV[0] = 1;
    for (int i=1;i<100100;i++) fact[i] = (fact[i-1] * i) % MOD;
    factINV[100099] = INV(fact[100099]);
    for (int i=100098;i;i--) factINV[i] = (factINV[i+1] * (i+1)) % MOD;

    int t;
    scanf("%d", &t);
    while(t--){
        solve();
    }
    return 0;
}
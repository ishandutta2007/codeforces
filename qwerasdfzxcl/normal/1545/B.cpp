#include <bits/stdc++.h>

typedef long long ll;
using namespace std;
const int MOD = 998244353;
char a[100100];
ll fact[200200];

ll pw(ll a, ll e){
    if (!e) return 1;
    ll ret = pw(a, e/2);
    if (e&1) return ret*ret%MOD*a%MOD;
    return ret*ret%MOD;
}

ll INV(ll x){
    return pw(x, MOD-2);
}

ll calc(int x, int y){
    int n = x+y, r = x;
    ll ret = ((fact[n]*INV(fact[r]))%MOD*INV(fact[n-r]))%MOD;
    return ret;
}

void solve(){
    int n;
    scanf("%d", &n);
    scanf("%s", a);
    int cnt1 = 0, cnt2 = 0;
    for (int i=0;i<n-1;){
        if (a[i+1]=='1' && a[i]=='1'){
            cnt1++; i += 2;
        }
        else i++;
    }
    for (int i=0;i<n;i++) if (a[i]=='0') cnt2++;
    printf("%lld\n", calc(cnt1, cnt2));
}

int main(){
    fact[0] = 1;
    for (int i=1;i<200200;i++) fact[i] = (fact[i-1]*i)%MOD;
    int t;
    scanf("%d", &t);
    while(t--){
        solve();
    }
    return 0;
}
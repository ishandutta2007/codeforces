#include <bits/stdc++.h>

typedef long long ll;
using namespace std;
const int MOD = 1e9+7;
int cnt[101], a[200200], b[200200];

ll pw(ll a, ll e){
    if (!e) return 1;
    ll ret = pw(a, e/2);
    if (e&1) return ret*ret%MOD*a%MOD;
    return ret*ret%MOD;
}

int main(){
    int n;
    scanf("%d", &n);
    int val = 0, mn = 1e9;
    for (int i=0;i<n;i++){
        scanf("%d", a+i);
        if (a[i]&1) continue;
        val++;

        int tmp = 0;
        while(a[i]%2==0){
            tmp++;
            a[i] /= 2;
        }
        cnt[tmp]++;
        b[i] = tmp;

        if (cnt[tmp]>=2) mn = min(mn, tmp);
    }

    ll ans = (pw(2, n) - pw(2, val) + MOD) %MOD;
    if (mn==1e9){
        printf("%lld\n", ans);
        return 0;
    }

    for (int z=1;z<=32;z++){
        int val1 = 0, val2 = 0;
        for (int i=0;i<n;i++){
            if (b[i]==z) val1++;
            if (b[i]>z) val2++;
        }
        if (val1<=1) continue;
        ans = (ans + pw(2, val2)*(pw(2, val1-1)-1)%MOD) %MOD;
    }
    printf("%lld\n", ans);
    return 0;
}
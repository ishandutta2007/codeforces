#include <bits/stdc++.h>
#define lcm _lcm_____

typedef long long ll;
using namespace std;
const ll MOD = 1e9+7;
ll lcm[42], dp[52];

ll calc(ll x, ll y, ll val){
    return y/val - (x-1)/val;
}

void solve(){
    ll a = 3, b;
    scanf("%lld", &b);
    if (b<=3){
        if (b==1) printf("2\n");
        if (b==2) printf("5\n");
        if (b==3) printf("7\n");
        return;
    }
    //for (int i=2;i<=6;i++) printf("%lld ", dp[i]);
    ll ans = 0;
    for (int i=1;i<40;i++){
        ans += (dp[i+1]+1)*(calc(a, b, lcm[i])-calc(a, b, lcm[i+1]));
    }
    ans += (dp[41]+1)*(calc(a, b, lcm[40]));
    ans += 5;
    ans %= MOD;
    printf("%lld\n", ans);
}

int main(){
    int t;
    scanf("%d", &t);
    for (int i=1;i<52;i++) dp[i] = i-1;
    ll cur = 1;
    for (int i=1;i<=40;i++){
        lcm[i] = cur;
        ll tmp = __gcd(cur, (ll)i+1);
        cur /= tmp;
        cur *= i+1;
    }
    while(t--) solve();
    return 0;
}
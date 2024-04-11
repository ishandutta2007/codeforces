#include <iostream>
#include <algorithm>

using namespace std;
typedef long long ll;
const int mod = 998244353;

ll fac(int x){
    ll temp = 1;
    for(int i=1;i<=x;i++){
        temp *= i;
        temp %= mod;
    }
    return temp;
}

ll inv(ll x){
    int k = 0;
    ll ans = 1, temp = x;
    while((1LL<<k) <= mod-2){
        if((1LL<<k) & (mod-2)){
            ans *= temp;
            ans %= mod;
        }
        temp *= temp;
        temp %= mod;
        k++;
    }

    return ans;
}

ll comb(int x){
    ll temp = fac(2*x), temp2 = inv(fac(x));
    temp2 *= temp2;
    temp2 %= mod;
    temp *= temp2;
    temp %= mod;
    return temp;
}

ll a[150002], b[150002];

int main()
{
    int n;
    scanf("%d", &n);
    for(int i=0;i<n;i++){
        scanf("%lld", &a[i]);
    }
    for(int i=0;i<n;i++){
        scanf("%lld", &b[i]);
    }

    sort(a, a+n);
    sort(b, b+n);

    ll sum = 0;

    for(int i=0;i<n;i++){
        sum += abs(b[i] - a[n-1-i]);
        sum %= mod;
    }

    ll ans = sum;
    ans *= comb(n);
    ans %= mod;

    printf("%lld", ans);
}
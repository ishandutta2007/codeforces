#include <bits/stdc++.h>

typedef long long ll;
using namespace std;
ll mod=998244353;
ll a[200002];

ll ppow(ll a, ll b){
    if (b==0) return 1;
    ll tmp=ppow(a, b/2);
    if (b%2==0) return(tmp*tmp)%mod;
    return (((tmp*tmp)%mod)*a)%mod;
}

int main(){
    ll n;
    scanf("%lld", &n);
    a[1]=1;
    a[2]=1;
    for (int i=3;i<=n;i++) a[i]=(a[i-1]+a[i-2])%mod;
    ll y=ppow(2, mod-1-n);
    ll ans=(y*a[n])%mod;
    printf("%lld", ans);
    return 0;
}
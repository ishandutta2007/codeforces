#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
ll a[400000];
ll mod=998244353;

ll power(int a, int b, int c)
{
    if (b==1)
        return a%c;
    else
    {
        ll ans=power(a, b/2, c)%c;
        if (b%2==0)
            return (ans*ans)%c;
        else
            return (((ans*ans)%c)*a)%c;
    }
}

ll factorial(int a, int p)
{
    if (a==0)
        return 1;
    else
        return (a*factorial(a-1, p))%p;
}

ll ncr(int n){
    ll x, y0, y1, z0, z1;
    x=factorial(2*n, mod);
    y0=factorial(n, mod);
    z0=factorial(n, mod);
    y1=power(y0, mod-2, mod);
    z1=power(z0, mod-2, mod);
    ll ans=(((x*y1)%mod)*z1)%mod;
    return ans;
}

int main()
{
    ll n;
    scanf("%lld", &n);
    for (ll i=0;i<2*n;i++){
        scanf("%lld", &a[i]);
    }
    sort(a, a+(2*n));
    ll ans=0;
    for (ll i=0;i<n;i++){
        ans += a[n]-a[i];
        ans %= mod;
    }
    for (ll i=n+1;i<2*n;i++){
        ans += a[i]-a[n];
        ans %= mod;
    }
    ll tmp=ncr(n);
    ans *= tmp;
    ans %= mod;
    printf("%lld", ans);
    return 0;
}
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const ll c=500002;
ll n, k, mod=998244353, fakt[c], inv[c], sum, db[c];
ll oszt(ll a) {
    ll ans=1, p=mod-2;
    while(p) {
        if (p%2) ans*=a, ans%=mod;
        p/=2, a*=a, a%=mod;
    }
    return ans;
}
int main()
{
    cin >> n >> k, fakt[0]=1, inv[0]=1;
    for (int i=1; i<=n; i++) fakt[i]=fakt[i-1]*i%mod, inv[i]=oszt(fakt[i]);
    for (int i=1; n/i>=k; i++) {
        long long p=fakt[n/i-1]*inv[k-1]%mod*inv[n/i-k]%mod;
        sum+=p, sum%=mod;
    }
    cout << sum << "\n";
    return 0;
}
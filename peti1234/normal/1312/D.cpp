#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
ll n, m, fakt[200002], mod=998244353, sum=1;
ll oszt(ll a) {
    ll ans=1, p=mod-2;
    while(p) {
        if (p%2) ans*=a, ans%=mod;
        a*=a, a%=mod, p/=2;
    }
    return ans;
}
int main()
{
    cin >> n >> m, fakt[0]=1;
    if (n>m+1) {
        cout << 0;
        return 0;
    }
    for (int i=1; i<=max(n, m); i++) {
        fakt[i]=fakt[i-1]*i%mod;
        if (i<=n-3) sum*=2, sum%=mod;
    }
    cout << sum*(n-2)%mod*fakt[m]%mod*oszt(fakt[n-1])%mod*oszt(fakt[m-n+1])%mod;
    return 0;
}
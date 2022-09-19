#include <bits/stdc++.h>

using namespace std;
const int c=300002;
int w;
long long n, t[c], mod=998244353, fakt[c], sum;
long long oszt(long long a) {
    long long ans=1, p=mod-2;
    while(p) {
        if (p%2) ans*=a, ans%=mod;
        a*=a, a%=mod, p/=2;
    }
    return ans;
}
int main()
{
    ios_base::sync_with_stdio(false), cin.tie(0);
    cin >> n, n*=2;
    fakt[0]=1;
    for (int i=1; i<=n; i++) fakt[i]=fakt[i-1]*i%mod;
    for (int i=1; i<=n; i++) {
        cin >> t[i];
    }
    sort(t+1, t+n+1);
    for (int i=1; i<=n/2; i++) sum-=t[i];
    for (int i=n/2+1; i<=n; i++) sum+=t[i];
    sum%=mod;
    cout << sum*fakt[n]%mod*oszt(fakt[n/2])%mod*oszt(fakt[n/2])%mod << "\n";
    return 0;
}
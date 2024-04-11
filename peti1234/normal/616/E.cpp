#include <bits/stdc++.h>

using namespace std;
long long n, m, gy, ans, mod=1e9+7;
long long sum(long long l, long long r) {
    l%=mod, r%=mod;
    return (r*(r+1)/2%mod-l*(l+1)/2%mod+mod)%mod;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    gy=sqrt(n);
    if (m>n) {
        ans=n%mod*((m-n)%mod)%mod;
        m=n;
    }
    for (long long i=1; i<=gy; i++) {
        long long kov=n/(i+1);
        if (kov<m) {
            ans+=n%mod*((m-kov)%mod)%mod-i*sum(kov, m)%mod;
            m=kov;
        }
    }
    for (long long i=1; i<=m; i++) {
        ans+=n%i;
    }
    cout << (ans%mod+mod)%mod << "\n";
    return 0;
}
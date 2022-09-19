#include <bits/stdc++.h>

using namespace std;
const int c=1000005;
long long n, ans, fakt[c], inv[c], mod=1e9+7;
long long oszt(long long a) {
    long long ans=1, p=mod-2;
    while (p) {
        if (p%2) {
            ans*=a, ans%=mod;
        }
        a*=a, a%=mod;
        p/=2;
    }
    return ans;
}
long long alatt(long long a, long long b) {
    if (a<0 || a<b) {
        return 0;
    }
    return fakt[a]*inv[b]%mod*inv[a-b]%mod;
}
int main()
{
    cin >> n;
    fakt[0]=1, inv[0]=1;
    for (int i=1; i<=n; i++) {
        fakt[i]=fakt[i-1]*i%mod;
        inv[i]=oszt(fakt[i]);
    }
    for (int i=0; i<=n; i++) {
        if ((n-i)%2) {
            continue;
        }
        long long ert=(i==0 ? 1 : alatt(n-i-1, i-1)*n%mod*oszt(i)%mod);
        //cout << i << " " << ert << "\n";
        ans+=2*ert*fakt[n-i]%mod;
    }
    cout << ans%mod << "\n";
    return 0;
}
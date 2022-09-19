#include <bits/stdc++.h>

using namespace std;
const int c=200002;
long long mod=998244353, n, k, sp, sum=1, ans, fakt[c], hat[c], inv[c], t[c];
long long oszt(long long a) {
    long long ans=1, p=mod-2;
    while(p) {
        if (p%2) ans*=a, ans%=mod;
        a*=a, a%=mod, p/=2;
    }
    return ans;
}
long long alatt(int a, int b) {
    return fakt[a]*inv[b]%mod*inv[a-b]%mod;
}
int main()
{
    fakt[0]=1, inv[0]=1, hat[0]=1;
    cin >> n >> k;
    if (k==1) {
        cout << 0 << "\n";
        return 0;
    }
    for (int i=1; i<=n; i++) fakt[i]=fakt[i-1]*i%mod, inv[i]=oszt(fakt[i]), hat[i]=hat[i-1]*(k-2)%mod;
    for (int i=1; i<=n; i++) {
        sum*=k, sum%=mod;
        cin >> t[i];
        sp+=(t[i]==t[i-1]);
    }
    sp+=(t[1]==t[n]);
    n-=sp;
    for (int i=0; i<=n/2; i++) {
        ans+=alatt(n, 2*i)*alatt(2*i, i)%mod*hat[n-2*i]%mod;
        ans%=mod;
    }
    for (int i=0; i<sp; i++) {
        ans*=k, ans%=mod;
    }
    cout << (sum-ans+mod)*inv[2]%mod << "\n";
    return 0;
}
// n==1
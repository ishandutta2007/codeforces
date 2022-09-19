#include <bits/stdc++.h>

using namespace std;
const int c=1e6+2;
long long n, m, sum, mod=1e9+7;
long long fakt[c], inv[c];
long long gyh(long long a, long long b) {
    if (b<0) {
        b+=mod-1;
    }
    long long ans=1;
    while(b) {
        if (b%2) {
            ans*=a, ans%=mod;
        }
        a*=a, a%=mod;
        b/=2;
    }
    return ans;
}
long long alatt(long long a, long long b) {
    if (a<0 || a<b) return 0;
    return fakt[a]*inv[b]%mod*inv[a-b]%mod;
}
int main()
{
    cin >> n >> m;
    fakt[0]=1, inv[0]=1;
    for (int i=1; i<=max(n, m); i++) {
        fakt[i]=fakt[i-1]*i%mod;
        inv[i]=gyh(fakt[i], mod-2);
    }
    for (int i=1; i<=min(n-1, m); i++) {
        sum+=alatt(n-2, i-1)*gyh(m, n-i-1)%mod*alatt(m-1, i-1)%mod*fakt[i-1]%mod*(i+1)%mod*gyh(n, n-i-2)%mod;
        sum%=mod;
    }
    cout << sum << "\n";
    return 0;
}
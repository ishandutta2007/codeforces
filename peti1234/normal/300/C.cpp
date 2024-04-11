#include <bits/stdc++.h>

using namespace std;
const int c=1e6+2;
long long a, b, n, mod=1e9+7, fakt[c], inv[c], ans;
long long oszt(long long a) {
    long long ans=1, p=mod-2;
    while(p) {
        if (p%2) {
            ans*=a, ans%=mod;
        }
        a*=a, a%=mod;
        p/=2;
    }
    return ans;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> a >> b >> n;
    fakt[0]=1, inv[0]=1;
    for (int i=1; i<=n; i++) {
        fakt[i]=fakt[i-1]*i%mod;
        inv[i]=oszt(fakt[i]);
    }
    for (int i=0; i<=n; i++) {
        long long sum=i*a+(n-i)*b;
        bool jo=1;
        while(sum>0) {
            if (sum%10!=a && sum%10!=b) {
                jo=0;
            }
            sum/=10;
        }
        if (jo) {
            ans+=fakt[n]*inv[i]%mod*inv[n-i]%mod;
            ans%=mod;
        }
    }
    cout << ans << "\n";
    return 0;
}
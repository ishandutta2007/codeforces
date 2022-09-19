#include <bits/stdc++.h>

using namespace std;
const int c=500005;
long long n, fakt[c], inv[c], ans, mod=1e9+7;
long long oszt(long long a) {
    long long ans=1, p=mod-2;
    while (p) {
        if (p%2) {
            ans=ans*a%mod;
        }
        a=a*a%mod;
        p/=2;
    }
    return ans;
}
long long alatt(long long a, long long b) {
    if (a<b || b<0) return 0;
    return fakt[a]*inv[b]%mod*inv[a-b]%mod;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    fakt[0]=1, inv[0]=1;
    for (int i=1; i<c; i++) {
        fakt[i]=fakt[i-1]*i%mod;
        inv[i]=oszt(fakt[i]);
    }
    for (long long i=0; i<=n; i++) {
        // (i, i), (i+1, i), (i+2, i), (i+x-1, i) ... == (i+x, i+1)
        long long x;
        cin >> x;
        if (x==0) continue;
        //cout << "fontos " << i+x << " " << i+1 << "\n";
        ans=(ans+alatt(i+x, i+1))%mod;
        //cout << "lep " << alatt(i+x, i+1) << "\n";
        //cout << fakt[i+x] << " " << inv[i+1] << " " << inv[x-1] << "\n";
    }
    cout << ans << "\n";
    return 0;
}
/*
1
2
1 2
*/
#include <bits/stdc++.h>

using namespace std;
const int c=1000005;
long long ans, db, rossz, n, m, fakt[c], inv[c], mod=1e9+7;
long long po(long long a, long long p) {
    long long ans=1;
    while (p) {
        if (p%2) ans=ans*a%mod;
        a=a*a%mod;
        p/=2;
    }
    return ans;
}
long long oszt(long long a) {
    return po(a, mod-2);
}
long long alatt(long long a, long long b) {
    return fakt[a]*inv[b]%mod*inv[a-b]%mod;
}
int main()
{
    cin >> n >> m;
    fakt[0]=1, inv[0]=1;
    for (int i=1; i<=max(n, m); i++) {
        fakt[i]=fakt[i-1]*i%mod;
        inv[i]=oszt(fakt[i]);
    }
    db=po(m, n);
    ans=db;
    for (int i=1; i<=n; i++) {
        rossz=(rossz+alatt(n, i-1)*po(m-1, n-i+1))%mod;
        ans=(ans+po(m, i)*(db-rossz+mod))%mod;
    }
    cout << ans << "\n";
    return 0;
}
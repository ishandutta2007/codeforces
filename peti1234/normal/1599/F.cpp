#include <bits/stdc++.h>

using namespace std;
const int c=200005;
long long n, q, t[c], s1[c], s2[c], mod=1e9+7;
long long oszt(long long a) {
    long long ans=1, p=mod-2;
    while (p) {
        if (p%2) ans=ans*a%mod;
        a=a*a%mod, p/=2;
    }
    return ans;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> q;
    for (int i=1; i<=n; i++) {
        cin >> t[i];
        s1[i]=(s1[i-1]+t[i])%mod;
        s2[i]=(s2[i-1]+t[i]*t[i])%mod;
    }
    for (int i=1; i<=q; i++) {
        long long l, r, db, d, sum, kezd;
        cin >> l >> r >> d;
        sum=(s1[r]-s1[l-1]+mod)%mod, db=r-l+1;
        kezd=((sum-db*(db-1)/2%mod*d%mod)%mod+mod)%mod*oszt(db)%mod;
        long long ert=(kezd*kezd%mod*db+(db-1)*db%mod*(2*db-1)%mod*d%mod*d%mod*oszt(6)%mod+kezd*d%mod*db%mod*(db-1)%mod)%mod;
        cout << (ert==(s2[r]-s2[l-1]+mod)%mod ? "Yes" : "No") << "\n";
    }
    return 0;
}
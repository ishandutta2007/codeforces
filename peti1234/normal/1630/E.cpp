
#include <bits/stdc++.h>

using namespace std;
const int c=1000005;
long long w, n, db[c], cnt[c], cmp[c], fakt[c], s, mod=998244353;
vector<int> o, d2;
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
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    fakt[0]=1;
    for (int i=1; i<c; i++) {
        fakt[i]=fakt[i-1]*i%mod;
    }
    cin >> w;
    while (w--) {
        cin >> n;
        for (int i=1; i<=n; i++) {
            int x;
            cin >> x;
            db[x]++;
        }
        for (int i=1; i<=n; i++) {
            s=__gcd(s, db[i]);
            if (db[i]) {
                d2.push_back(db[i]);
            }
        }
        for (int i=n; i>=1; i--) {
            if (s%i==0) {
                o.push_back(i);
            }
        }
        if (s==n) {
            cout << 1 << "\n";
            for (int i=1; i<=n; i++) db[i]=0;
            o.clear(), d2.clear();
            s=0;
            continue;
        }
        long long sumdb=0, sumua=0;
        for (auto x:o) {
            long long spec=0, ert=fakt[n/x];
            for (auto y:d2) {
                ert=ert*fakt[y]%mod*oszt(fakt[y/x])%mod;
            }
            for (auto y:d2) {
                spec=(spec+ert*(y/x)%mod*(y/x-1)%mod*oszt((n/x)*(n/x-1)%mod))%mod;
            }
            spec=spec*n%mod;
            for (auto y:o) {
                if (y%x==0) {
                    ert=(ert+mod-cnt[y])%mod;
                    spec=(spec+mod-cmp[y])%mod;
                }
            }
            cnt[x]=ert, cmp[x]=spec;
            sumdb=(sumdb+cnt[x]*x)%mod, sumua=(sumua+cmp[x]*x)%mod;
        }
        cout << (n+mod-sumua*oszt(sumdb)%mod)%mod << "\n";

        o.clear(), d2.clear();
        for (int i=1; i<=n; i++) {
            db[i]=0, cnt[i]=0, cmp[i]=0;
        }
        s=0;
    }
    return 0;
}
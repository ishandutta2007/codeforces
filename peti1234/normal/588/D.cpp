#include <bits/stdc++.h>

using namespace std;
const int c=1000005;
long long n, k, l, db, mar, s, cnt[c], regipref[c], uj[c], ujpref[c], t[c], ans, mod=1e9+7;
map<int, int> m, id;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> l >> k;
    db=l/n, mar=l%n;
    for (int i=0; i<n; i++) {
        cin >> t[i];
        m[t[i]]++;
    }
    for (auto p:m) {
        id[p.first]=++s;
        cnt[s]=p.second;
    }
    for (int i=0; i<=s; i++) {
        regipref[i]=1;
    }
    for (int j=1; j<=min(k, db+1); j++) {
        for (int i=1; i<=s; i++) {
            uj[i]=(regipref[i])%mod;
            ujpref[i]=(ujpref[i-1]+uj[i]*cnt[i])%mod;
        }
        ans=(ans+ujpref[s]*((db-j+1)%mod))%mod;
        for (int i=0; i<mar; i++) {
            ans=(ans+uj[id[t[i]]])%mod;
        }
        for (int i=1; i<=n; i++) {
            regipref[i]=ujpref[i];
            uj[i]=0, ujpref[i]=0;
        }
    }
    cout << ans << "\n";
    return 0;
}
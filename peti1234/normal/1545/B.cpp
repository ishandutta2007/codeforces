#include <bits/stdc++.h>

using namespace std;
const int c=100005;
long long fakt[c], inv[c], mod=998244353;
int w, n, par, db, ut;
string s;
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
long long alatt(int a, int b) {
    if (a<b || a<0) {
        return 0;
    }
    return fakt[a]*inv[b]%mod*inv[a-b]%mod;
}
int main()
{
    ios_base::sync_with_stdio(false);
    fakt[0]=1, inv[0]=1;
    for (int i=1; i<c; i++) {
        fakt[i]=fakt[i-1]*i%mod;
        inv[i]=oszt(fakt[i]);
    }
    cin >> w;
    while (w--) {
        cin >> n >> s;
        par=0, db=0, ut=0;
        for (int i=0; i<n; i++) {
            if (s[i]=='1') {
                db++;
                if (ut==1) {
                    par++;
                    ut=0;
                } else {
                    ut=1;
                }
            } else {
                ut=0;
            }
        }
        cout << alatt(n-db+par, par) << "\n";
    }
    return 0;
}
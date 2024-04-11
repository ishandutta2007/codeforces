#include <bits/stdc++.h>

using namespace std;
const int c=200005;
long long w, n, fakt[c], t[c], mod=998244353;
long long oszt(long long a) {
    long long ans=1, p=mod-2;
    while (p) {
        if (p%2) ans=ans*a%mod;
        a=a*a%mod;
        p/=2;
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    fakt[0]=1;
    for (int i=1; i<c; i++) {
        fakt[i]=fakt[i-1]*i%mod;
    }
    cin >> w;
    while (w--) {
        cin >> n;
        for (int i=1; i<=n; i++) {
            cin >> t[i];
        }
        sort(t+1, t+n+1);
        if (t[n]==t[n-1]) {
            cout << fakt[n] << "\n";
        } else if (t[n]-t[n-1]>1) {
            cout << 0 << "\n";
        } else {
            int db=0;
            for (int i=1; i<=n; i++) {
                if (t[i]+1==t[n]) {
                    db++;
                }
            }
            cout << fakt[n]*db%mod*oszt(db+1)%mod << "\n";
        }
    }
    return 0;
}
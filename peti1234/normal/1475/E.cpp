#include <bits/stdc++.h>

using namespace std;
const int c=1002;
long long w, fakt[c], inv[c], n, k, db[c], mod=1e9+7;
long long oszt(long long a) {
    long long ans=1, p=mod-2;
    while (p) {
        if (p%2) {
            ans*=a, ans%=mod;
        }
        a*=a, a%=mod;
        p/=2;
    }
    return ans;
}
long long alatt(long long a, long long b) {
    if (b>a || b<0) {
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
        cin >> n >> k;
        for (int i=1; i<=n; i++) {
            db[i]=0;
        }
        for (int i=1; i<=n; i++) {
            int x; cin >> x;
            db[x]++;
        }
        long long ans=1;
        for (int i=n; i>=1; i--) {
            if (db[i]>=k) {
                ans=alatt(db[i], k);
                break;
            }
            k-=db[i];
        }
        cout << ans << "\n";
    }
    return 0;
}
/*
1
4 2
1 1 1 1
*/
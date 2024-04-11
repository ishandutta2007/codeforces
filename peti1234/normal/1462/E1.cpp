#include <bits/stdc++.h>

using namespace std;
const int c=200002;
long long w, db[c], kom[c], fakt[c], inv[c], n, m, k, o=0, ans, mod=1000000007;
long long oszt(long long a) {
    long long ans=1, p=mod-2;
    while(p) {
        if (p%2) {
            ans*=a, ans%=mod;
        }
        a*=a, a%=mod, p/=2;
    }
    return ans;
}
long long alatt(long long a, long long b) {
    if (a<b || b<0) return 0;
    if (b==0) {
        return 1;
    }
    if (b==1) {
        return a;
    }
    if (b==2) {
        return a*(a-1)/2;
    }
    if (b==3) {
        return a*(a-1)*(a-2)/6;
    }
    //return fakt[a]*inv[b]%mod*inv[a-b]%mod;
}
int main()
{
    cin >> w;
    while(w--) {
        //cin >> n >> m >> k;
        cin >> n, m=3, k=2;
        fakt[0]=1, inv[0]=1;
        for (int i=1; i<=n; i++) {
            fakt[i]=fakt[i-1]*i%mod;
            inv[i]=oszt(fakt[i]);
        }
        for (int i=1; i<=n; i++) {
            db[i]=0, kom[i]=0;
        }
        for (int i=1; i<=n; i++) {
            int x; cin >> x;
            db[x]++;
        }
        for (int i=1; i<=n; i++) {
            kom[i]=kom[i-1]+db[i];
        }
        ans=0;
        for (int i=1; i<=n; i++) {
            int pos=max(o, i-k-1);
            for (int j=1; j<=db[i]; j++) {
                //ans+=alatt(db[i], j)*alatt(kom[i-1]-kom[pos], m-j)%mod;
                ans+=alatt(db[i], j)*alatt(kom[i-1]-kom[pos], m-j);
                //ans%=mod;
            }
        }
        cout << ans << "\n";
    }
    return 0;
}
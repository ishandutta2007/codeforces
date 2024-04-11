#include <bits/stdc++.h>

using namespace std;
const int c=300005;
long long fib[c], f2[c], t[c], pref[c], add[c], n, q, mod=1e9+9;
vector<pair<int, int> > sz;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> q;
    for (int i=1; i<=n; i++) {
        cin >> t[i];
        pref[i]=(pref[i-1]+t[i])%mod;
    }
    fib[1]=1, f2[1]=1;
    for (int i=2; i<=n; i++) {
        fib[i]=(fib[i-2]+fib[i-1])%mod;
        f2[i]=(f2[i-1]+fib[i])%mod;
    }
    for (int i=1; i<=q; i++) {
        int id, l, r;
        cin >> id >> l >> r;
        if (id==1) {
            sz.push_back({l, r});
            add[l]=(add[l]+1)%mod;
            if (r+1<=n) add[r+1]=(add[r+1]+mod-fib[r-l+2])%mod;
            if (r+2<=n) add[r+2]=(add[r+2]+mod-fib[r-l+1])%mod;
        } else {
            long long ans=pref[r]-pref[l-1]+mod;
            for (auto p:sz) {
                int a=p.first, b=p.second;
                if (l<=b && r>=a) {
                    int kezd=max(a, l)-a+1, veg=min(b, r)-a+1;
                    ans=(ans+f2[veg]-f2[kezd-1]+mod);
                }
            }
            cout << ans%mod << "\n";
        }
        if (sz.size()==800) {
            for (int i=1; i<=n; i++) {
                if (i>1) add[i]=(add[i-2]+add[i-1]+add[i])%mod;
                t[i]=(t[i]+add[i]);
                if (t[i]>=mod) t[i]-=mod;
                pref[i]=(pref[i-1]+t[i]);
                if (pref[i]>=mod) pref[i]-=mod;
            }
            for (int i=1; i<=n; i++) add[i]=0;
            sz.clear();
        }
    }
    return 0;
}
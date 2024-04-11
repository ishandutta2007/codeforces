#include <bits/stdc++.h>

using namespace std;
const int c=200005;
long long w, n, l, r, a, b, fakt[c], inv[c], mod=1e9+7;
long long oszt(long long a) {
    long long ans=1, p=mod-2;
    while (p) {
        if (p%2) {
            ans*=a, ans%=mod;
        }
        p/=2;
        a*=a, a%=mod;
    }
    return ans;
}
long long alatt(int a, int b) {
    if (a<b || a<0 || b<0) {
        return 0;
    }
    return fakt[a]*inv[b]%mod*inv[a-b]%mod;
}
int main()
{
    fakt[0]=1, inv[0]=1;
    for (int i=1; i<c; i++) {
        fakt[i]=fakt[i-1]*i%mod;
        inv[i]=oszt(fakt[i]);
    }
    cin >> w;
    while (w--) {
        cin >> n >> l >> r;
        a=1-l, b=r-n;
        if (a>b) {
            swap(a, b);
        }

        long long ans=0;
        int f1=n/2, f2=(n%2 ? f1+1 : 2e9);

        ans+=a*(alatt(n, f1))+a*(alatt(n, f2));
        ans%=mod;

        ans+=alatt(n, f1+1)-alatt(n-b+a, f1+1);
        ans+=alatt(n, f2+1)-alatt(n-b+a, f2+1);
        ans+=2*mod, ans%=mod;
        int n2=n-(b-a)-2, dif=1;
        for (int i=1; i<=n; i++) {
            ans+=alatt(n2, f1-dif), ans+=alatt(n2, f2-dif);
            ans%=mod;
            n2-=2, dif++;
        }
        cout << ans << "\n";
    }
    return 0;
}
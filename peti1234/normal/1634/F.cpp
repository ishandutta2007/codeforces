#include <bits/stdc++.h>

using namespace std;
const int c=300005, k=5;
long long n, q, mod, fib[c], ert[c], db;
void add(int a, int b, int s) {
    if (s==-1) b=mod-b;
    if (ert[a]) db--;
    ert[a]=(ert[a]+b)%mod;
    if (ert[a]) db++;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> q >> mod;
    fib[1]=1%mod;
    for (int i=2; i<=n; i++) {
        fib[i]=(fib[i-1]+fib[i-2])%mod;
    }
    for (int i=1; i<=n; i++) {
        cin >> ert[i];
    }
    for (int i=1; i<=n; i++) {
        int x;
        cin >> x;
        ert[i]=(ert[i]+mod-x)%mod;
    }
    for (int i=n; i>=1; i--) {
        if (i>=2) {
            ert[i]=(ert[i]+2*mod-ert[i-1]-ert[i-2])%mod;
        }
        if (ert[i]) {
            db++;
        }
    }
    for (int i=1; i<=q; i++) {
        char c;
        cin >> c;
        int s=(c=='A' ? 1 : -1);
        int l, r;
        cin >> l >> r;
        add(l, 1, s);
        if (r+1<=n) add(r+1, fib[r-l+2], -s);
        if (r+2<=n) add(r+2, fib[r-l+1], -s);
        cout << (db==0 ? "YES" : "NO") << "\n";
    }
    return 0;
}
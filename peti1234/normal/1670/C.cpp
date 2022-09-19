#include <bits/stdc++.h>

using namespace std;
const int c=100005;
int w, n, k, a[c], b[c], ki[c], si[c], ert[c], ans, mod=1e9+7;
int holvan(int a) {
    return (ki[a] ? ki[a]=holvan(ki[a]) : a);
}
int unio(int a, int b) {
    a=holvan(a), b=holvan(b);
    if (a!=b) {
        ki[a]=b;
        si[b]+=si[a];
        si[a]=0;
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while (w--) {
        cin >> n;
        for (int i=1; i<=n; i++) {
            si[i]=1;
        }
        for (int i=1; i<=n; i++) {
            cin >> a[i];
        }
        for (int i=1; i<=n; i++) {
            cin >> b[i];
            unio(a[i], b[i]);
        }
        for (int i=1; i<=n; i++) {
            int x;
            cin >> x;
            if (x!=0) {
                int s=holvan(x);
                if (x==a[i]) ert[s]|=1;
                else ert[s]|=2;
            }
        }
        ans=1;
        for (int i=1; i<=n; i++) {
            if (holvan(i)==i && si[i]>1) {
                if (ert[i]==3) ans=1;
                if (ert[i]==0) ans=2*ans%mod;
            }
        }
        //cout << "valasz.......................... ",
        cout << ans << "\n";

        for (int i=1; i<=n; i++) {
            a[i]=b[i]=ki[i]=si[i]=ert[i]=0;
        }
    }
    return 0;
}
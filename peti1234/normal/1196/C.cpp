#include <bits/stdc++.h>
 
using namespace std;
 
int main()
{
    int q;
    cin >> q;
    for (int i=1; i<=q; i++) {
        int p=100000;
        int n;
        cin >> n;
        int kisx=-p, nagyx=p, kisy=-p, nagyy=p;
        for (int i=1; i<=n; i++) {
            int a, b, c, d, e, f;
            cin >> a >> b >> c >> d >> e >> f;
            if (c==0) {
                kisx=max(kisx, a);
            }
            if (d==0) {
                nagyy=min(nagyy, b);
            }
            if (e==0) {
                nagyx=min(nagyx, a);
            }
            if (f==0) {
                kisy=max(kisy, b);
            }
        }
        if (kisx>nagyx || kisy>nagyy) {
            cout << 0 << "\n";
        } else {
            cout << 1 << " " << kisx << " " << kisy << "\n";
        }
    }
    return 0;
}
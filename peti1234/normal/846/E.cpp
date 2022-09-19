#include <bits/stdc++.h>

using namespace std;
const int c=100002;
long long n, a[c], b[c], as, bs, dif, x[c], k[c], pr;
int main()
{
    cin >> n;
    for (int i=1; i<=n; i++) cin >> a[i], as+=a[i];
    for (int i=1; i<=n; i++) cin >> b[i], bs+=b[i];
    dif=as-bs;
    for (int i=2; i<=n; i++) {
        cin >> x[i] >> k[i];
    }
    if (dif<0) pr=1;
    for (int i=n; i>=2; i--) {
        long long d=(b[i]-a[i]);
        //cout << "ert " << i << " " << d << " " << x[i] << " " << k[i] << endl;
        if (d<=0) {
            a[x[i]]-=d;
        } else {
            double p=log(d)+log(k[i]);
            if (p>40.0) {
                pr=1;
                break;
            }
            else {
                //cout << "torol " << x[i] << " " << a[x[i]] << " " << d*k[i] << endl;
                a[x[i]]-=d*k[i];
                dif-=(d-1)*k[i];
                if (dif<0) {
                    pr=1;
                    break;
                }
            }
        }
    }
    if (a[1]<b[1]) pr=1;
    if (pr) cout << "NO\n";
    else cout << "YES\n";
    return 0;
}
/*
5
2 1 1 2 3
1 2 2 2 1
1 2
1 3
2 4
1 4
*/
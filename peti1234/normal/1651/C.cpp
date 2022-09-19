#include <bits/stdc++.h>

using namespace std;
const int k=200005;
long long w, n, a, aa, b, bb, c, cc, d, dd, x[k], y[k];
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while (w--) {
        cin >> n;
        for (int i=1; i<=n; i++) cin >> x[i];
        for (int i=1; i<=n; i++) cin >> y[i];
        a=x[1], b=x[n], c=y[1], d=y[n];
        aa=bb=cc=dd=1e9;
        for (int i=1; i<=n; i++) {
            aa=min(aa, abs(y[i]-x[1]));
            bb=min(bb, abs(y[i]-x[n]));
            cc=min(cc, abs(x[i]-y[1]));
            dd=min(dd, abs(x[i]-y[n]));
        }
        cout << min(min(abs(a-c), aa+cc)+min(abs(b-d), bb+dd), min(abs(a-d), aa+dd)+min(abs(b-c), bb+cc)) << "\n";

    }
    return 0;
}
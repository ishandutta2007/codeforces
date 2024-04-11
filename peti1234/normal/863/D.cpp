#include <bits/stdc++.h>

using namespace std;
const int c=200005;
int n, a[c], q, t[c], l[c], r[c], m, x;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> q >> m;
    for (int i=1; i<=n; i++) {
        cin >> a[i];
    }
    for (int i=1; i<=q; i++) {
        cin >> t[i] >> l[i] >> r[i];
    }
    for (int i=1; i<=m; i++) {
        cin >> x;
        for (int i=q; i>=1; i--) {
            if (l[i]<=x && x<=r[i]) {
                if (t[i]==1) {
                    x--;
                    if (x<l[i]) {
                        x=r[i];
                    }
                }
                if (t[i]==2) {
                    x=l[i]+r[i]-x;
                }
            }
        }
        cout << a[x] << " ";
    }
    return 0;
}
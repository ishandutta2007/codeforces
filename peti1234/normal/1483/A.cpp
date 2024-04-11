#include <bits/stdc++.h>

using namespace std;
const int c=200002;
int w, n, m, a[c], b[c], db[c], pos, kr;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while (w--) {
        cin >> n >> m;
        kr=(m+1)/2;
        for (int i=1; i<=m; i++) {
            int x;
            cin >> x;
            cin >> a[i];
            b[i]=0;
            for (int j=2; j<=x; j++) {
                cin >> b[i];
            }
            db[a[i]]++;
        }
        pos=0;
        for (int i=1; i<=n; i++) {
            if (db[i]>db[pos]) {
                pos=i;
            }
        }
        for (int i=1; i<=m; i++) {
            if (db[pos]>kr && a[i]==pos && b[i]!=0) {
                swap(a[i], b[i]);
                db[pos]--;
            }
        }
        if (db[pos]>kr) {
            cout << "NO\n";
        } else {
            cout << "YES\n";
            for (int i=1; i<=m; i++) {
                cout << a[i] << " ";
            }
            cout << "\n";
        }
        for (int i=1; i<=n; i++) {
            db[i]=0;
        }
        for (int i=1; i<=m; i++) {
            a[i]=0, b[i]=0;
        }
    }
    return 0;
}
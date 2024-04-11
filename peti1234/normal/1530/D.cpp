#include <bits/stdc++.h>

using namespace std;
const int c=200005;
int w, n, t[c], db[c], uj, ans[c], inv[c], jo;
bool v[c];
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while (w--) {
        cin >> n;
        for (int i=1; i<=n; i++) {
            cin >> t[i];
            db[t[i]]++;
        }
        uj=1;
        for (int i=1; i<=n; i++) {
            if (!v[t[i]]) {
                ans[i]=t[i];
                inv[t[i]]=i;
                jo++;
                v[t[i]]=1;
            } else {
                while (db[uj] || v[uj]) {
                    uj++;
                }
                ans[i]=uj;
                inv[uj]=i;
                v[uj]=1;
            }
        }
        for (int i=1; i<=n; i++) {
            if (ans[i]==i) {
                int valt=inv[t[i]];
                //cout << "csere " << i << " " << valt << "\n";
                swap(ans[i], ans[valt]);
                swap(inv[i], inv[t[i]]);
            }
        }
        cout << jo << "\n";
        for (int i=1; i<=n; i++) {
            cout << ans[i] << " ";
        }
        cout << "\n";
        /*
        for (int i=1; i<=n; i++) {
            cout << inv[i] << " ";
        }
        cout << "\n";
        */
        uj=0, jo=0;
        for (int i=1; i<=n; i++) {
            t[i]=0, db[i]=0, ans[i]=0, inv[i]=0, v[i]=0;
        }
    }
    return 0;
}
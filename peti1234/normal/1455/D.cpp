#include <bits/stdc++.h>

using namespace std;
const int c=502;
int w, n, x, db, t[c];
int main()
{
    cin >> w;
    while(w--) {
        cin >> n >> x, db=0;
        for (int i=1; i<=n; i++) {
            cin >> t[i];
            if (t[i]<t[i-1]) db++;
        }
        for (int i=0; i<=n; i++) {
            if (!db) {
                cout << i << "\n";
                break;
            }
            for (int j=1; j<n; j++) {
                if (t[j]>x) {
                    if (t[j]>t[j+1] && x<=t[j+1]) db--;
                    swap(x, t[j]);
                    break;
                }
            }
        }
        if (db) {
            cout << -1 << "\n";
        }
    }
    return 0;
}
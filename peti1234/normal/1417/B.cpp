#include <bits/stdc++.h>

using namespace std;
int w, n, sz, db, cnt, t[100002];
int main()
{
    cin >> w;
    while(w--) {
        cin >> n >> sz, db=0, cnt=0;
        for (int i=1; i<=n; i++) {
            cin >> t[i];
            if (2*t[i]==sz) db++;
        }
        for (int i=1; i<=n; i++) {
            if (2*t[i]<sz) cout << 0 << " ";
            if (2*t[i]>sz) cout << 1 << " ";
            if (2*t[i]==sz) {
                cnt++;
                if (2*cnt<=db) cout << 0 << " ";
                else cout << 1 << " ";
            }
        }
        cout << "\n";
    }
    return 0;
}
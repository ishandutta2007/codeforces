#include <bits/stdc++.h>

using namespace std;
const int c=100002;
int w, n, pos, cel, db, t[c], h[c];
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while(w--) {
        cin >> n, pos=0, cel=0, db=0;
        for (int i=1; i<=n; i++) {
            cin >> t[i] >> h[i];
        }
        for (int i=1; i<=n; i++) {
            int ert=t[i]-t[i-1];
            if (pos<cel) {
                pos=min(cel, pos+ert);
            } else {
                pos=max(cel, pos-ert);
            }
            if (pos==cel) {
                if (i==n || abs(h[i]-pos)<=t[i+1]-t[i]) {
                    db++;
                }
                cel=h[i];
            } else {
                if (h[i]>=min(pos, cel) && h[i]<=max(pos, cel) && (i==n || abs(pos-h[i])<=t[i+1]-t[i])) {
                    db++;
                }
            }
        }
        cout << db << "\n";
    }
    return 0;
}
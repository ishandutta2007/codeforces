#include <bits/stdc++.h>

using namespace std;
const int c=2002;
int w, n, xo, t[c], pref[c], suf[c];
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while (w--) {
        cin >> n;
        xo=0;
        for (int i=1; i<=n; i++) {
            cin >> t[i];
            xo^=t[i];
            pref[i]=xo;
        }
        suf[n+1]=0;
        int x=n+1, y=0;
        for (int i=n; i>=1; i--) {
            suf[i]=suf[i+1]^t[i];
            if (suf[i]==xo && !y) {
                y=i;
            }
        }
        for (int i=1; i<=n; i++) {
            if (pref[i]==xo) {
                x=i;
                break;
            }
        }
        if (xo==0 || x<y) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
    return 0;
}
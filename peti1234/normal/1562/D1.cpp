#include <bits/stdc++.h>

using namespace std;
const int c=300005;
int w, n, q, t[c], pref[c];
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while (w--) {
        cin >> n >> q;
        for (int i=1; i<=n; i++) {
            char c;
            cin >> c;
            t[i]=(c=='+' ? 1 : -1);
            if (i%2) {
                t[i]*=-1;
            }
            pref[i]=pref[i-1]+t[i];
        }
        for (int i=1; i<=q; i++) {
            int l, r;
            cin >> l >> r;
            if (pref[l-1]==pref[r]) {
                cout << 0 << "\n";
            } else {
                if ((r-l)%2) {
                    cout << 2 << "\n";
                } else {
                    cout << 1 << "\n";
                }
            }
        }
    }
    return 0;
}
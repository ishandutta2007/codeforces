#include <bits/stdc++.h>

using namespace std;
const int c=200002;
int w, n, q, cnt, ert[c], maxi[c], mini[c], vmax[c], vmin[c], np, kp;
string s;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while (w--) {
        cin >> n >> q >> s;
        np=0, kp=0, cnt=0;
        for (int i=1; i<=n; i++) {
            if (s[i-1]=='+') {
                cnt++;
            } else {
                cnt--;
            }
            np=max(np, cnt), kp=min(kp, cnt);
            maxi[i]=np, mini[i]=kp, ert[i]=cnt;
        }
        np=n, kp=n;
        for (int i=n; i>=1; i--) {
            if (ert[i]>ert[np]) np=i;
            if (ert[i]<ert[kp]) kp=i;
            vmax[i]=ert[np]-ert[i], vmin[i]=ert[kp]-ert[i];
        }
        for (int i=1; i<=q; i++) {
            int a, b; cin >> a >> b;
            int x=max(maxi[a-1], ert[a-1]+vmax[b]), y=min(mini[a-1], ert[a-1]+vmin[b]);
            cout << x-y+1 << "\n";
        }
    }
    return 0;
}
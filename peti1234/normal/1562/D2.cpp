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
        pref[0]=c;
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
                    cout << l << " ";
                    l++;
                } else {
                    cout << 1 << "\n";
                }

                int kezd=pref[l-1], veg=pref[r], ert=(kezd+veg)/2+(kezd>=veg);

                int lo=l-1, hi=r, mid;
                while (hi-lo>1) {
                    mid=(hi+lo)/2;
                    if (kezd<veg && pref[mid]<=ert || kezd>veg && pref[mid]>=ert) {
                        lo=mid;
                    } else {
                        hi=mid;
                    }
                }
                cout << lo+1 << "\n";
            }
        }
    }
    return 0;
}
#include <bits/stdc++.h>

using namespace std;
const int c=200002;
long long w, n, t[c], ps[c], pn[c], osum, esum, dif, ert[c], psmin[c], pnmin[c];
bool jo;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while (w--) {
        cin >> n, osum=0, esum=0, jo=0;
        for (int i=1; i<=n; i++) {
            cin >> t[i];
            if (i%2) {
                osum+=t[i];
                ert[i]=osum-esum;
            } else {
                esum+=t[i];
                ert[i]=esum-osum;
            }
        }
        dif=(osum-esum)/2;
        psmin[n+1]=pnmin[n+1]=2e9;
        for (int i=n; i>=1; i--) {
            psmin[i]=psmin[i+1], pnmin[i]=pnmin[i+1];
            if (i%2) {
                pnmin[i]=min(pnmin[i], ert[i]);
            } else {
                psmin[i]=min(psmin[i], ert[i]);
            }
            //cout << i << " " << psmin[i] << " " << pnmin[i] << endl;
        }
        if (!dif && min(psmin[1], pnmin[1])>=0) {
            jo=1;
        }
        for (int i=1; i<n; i++) {
            if (i%2) {
                if (t[i]-t[i+1]==dif && ert[i]>=dif && pnmin[i+1]>=2*dif && psmin[i+1]>=-2*dif) {
                    jo=1;
                }
            } else {
                if (t[i+1]-t[i]==dif && ert[i]>=-dif && pnmin[i+1]>=2*dif && psmin[i+1]>=-2*dif) {
                    jo=1;
                }
            }


            if (ert[i]<0) {
                break;
            }
        }
        if ((osum+esum)%2) jo=0;
        cout << (jo ? "YES" : "NO") << "\n";
    }
    return 0;
}
/*
1
3
1 1 2
*/
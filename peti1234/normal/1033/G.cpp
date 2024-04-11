#include <bits/stdc++.h>

using namespace std;
int n, m;
long long t[102], aa, ab, ba, bb;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    for (int i=1; i<=n; i++) {
        cin >> t[i];
    }
    for (int s=2; s<=2*m; s++) {
        int kis=max(1, s-m), nagy=s-kis;
        int sima=kis-1, nagydb=0, enagy=0, mnagy=0;
        for (int i=1; i<=n; i++) {
            int ert=t[i]%s;
            sima=max(sima, min(ert, s-ert-1));
            mnagy=max(mnagy, ert/2);
            if (mnagy>enagy) {
                swap(enagy, mnagy);
            }
            if (ert>=(s+1)/2) {
                nagydb++;
            }
        }
        sima=max(sima, mnagy);
        int dif=sima-kis+1;
        aa+=dif, bb+=dif;
        kis+=dif, nagy-=dif;

        dif=max(0, enagy-kis+1);
        if (nagydb%2) {
            ab+=2*dif;
        } else {
            aa+=dif, bb+=dif;
        }
        kis+=dif, nagy-=dif;

        dif=nagy-kis+1;
        if (nagydb%2) {
            ab+=dif;
        } else {
            ba+=dif;
        }
    }

    cout << aa << " " << bb << " " << ab << " " << ba << "\n";
    return 0;
}
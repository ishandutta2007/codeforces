#include <bits/stdc++.h>

using namespace std;
int w, n, fel, le, el, maxi;
bool baj;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while (w--) {
        cin >> n;
        cin >> el;
        maxi=el;
        fel=le=-1;
        baj=0;
        for (int i=2; i<=n; i++) {
            int x; cin >> x;
            maxi=max(maxi, x);
            if (x>=el) {
                if (fel!=x-el && fel!=-1) {
                    baj=1;
                }
                fel=x-el;
            }
            if (x<=el) {
                if (le!=el-x && le!=-1) {
                    baj=1;
                }
                le=el-x;
            }
            el=x;
        }
        if (baj) {
            cout << -1 << "\n";
        } else if (min(fel, le)<=0) {
            cout << 0 << "\n";
        } else {
            if (maxi>=fel+le) {
                cout << -1 << "\n";
            } else {
                cout << fel+le << " " << fel << "\n";
            }
        }
    }
    return 0;
}
/*
1
3
7 3 4
*/
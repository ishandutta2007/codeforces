#include <bits/stdc++.h>

using namespace std;
const int c=1000;
int w, db[c+2], n, pos, k;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while (w--) {
        cin >> n >> pos >> k;
        for (int i=0; i<=c; i++) {
            db[i]=0;
        }
        for (int i=1; i<=k; i++) {
            int x;
            cin >> x;
            if (abs(pos-x)<=c) {
                db[abs(pos-x)]++;
            }
        }
        for (int i=0; i<=c; i++) {
            int ert=(pos-i>=1)+(pos+i<=n)-(i==0);
            if (db[i]<ert) {
                cout << i << "\n";
                break;
            }
        }
    }
    return 0;
}
#include <bits/stdc++.h>

using namespace std;
int w, n, x, ut, db;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while (w--) {
        cin >> x >> n >> x;
        ut=x+1, db=0;
        for (int i=1; i<n; i++) {
            cin >> x;
            if (x+1==ut) {
                db--;
            } else {
                db++, ut=x;
            }
        }
        if (ut==1) {
            db--;
        }
        //cout << "valasz: ";
        cout << db << "\n";
    }
    return 0;
}
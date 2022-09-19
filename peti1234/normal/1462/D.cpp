#include <bits/stdc++.h>

using namespace std;
int w, n, t[3002], maxi, ert;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while(w--) {
        cin >> n, maxi=0, ert=0;
        for (int i=1; i<=n; i++) {
            cin >> t[i];
        }
        for (int i=1; i<=n; i++) {
            ert+=t[i];
            int jo=1, sum=0, db=0;
            for (int j=1; j<=n; j++) {
                sum+=t[j];
                if (sum>ert) {
                    jo=0;
                }
                if (sum==ert) {
                    db++, sum=0;
                }
            }
            if (sum!=0) {
                jo=0;
            }
            if (jo) {
                maxi=max(maxi, db);
            }
        }
        cout << n-maxi << "\n";
    }
    return 0;
}
/*
1
4
1 2 2 1
*/
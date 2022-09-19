#include <bits/stdc++.h>

using namespace std;
int w, n, t[102], maxi, db;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while (w--) {
        cin >> n, maxi=db=0;
        for (int i=1; i<=n; i++) {
            cin >> t[i];
            if (t[i]!=t[i-1]) {
                maxi=max(maxi, db);
                db=0;
            }
            db++;
        }
        cout << max(maxi, db) << "\n";
    }
    return 0;
}
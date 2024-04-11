#include <bits/stdc++.h>

using namespace std;
long long maxi=0, ans, x, n, w, db;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while(w--) {
        cin >> n >> maxi;
        ans=0, db=0;
        for (long long i=1; i<n; i++) {
            cin >> x;
            ans=max(ans, maxi-x);
            maxi=max(maxi, x);
        }
        while(ans>0) ans/=2, db++;
        cout << db << "\n";
    }
    return 0;
}
// Egyszer a feladat.
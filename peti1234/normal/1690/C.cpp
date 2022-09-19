#include <bits/stdc++.h>

using namespace std;
const int c=200005;
int w, n, kezd[c], veg[c], maxi;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while (w--) {
        cin >> n;
        maxi=0;
        for (int i=1; i<=n; i++) {
            cin >> kezd[i];
        }
        for (int i=1; i<=n; i++) {
            maxi=max(maxi, kezd[i]);
            cin >> veg[i];
            cout << veg[i]-maxi << " ";
            maxi=max(maxi, veg[i]);
        }
        cout << "\n";
    }
    return 0;
}
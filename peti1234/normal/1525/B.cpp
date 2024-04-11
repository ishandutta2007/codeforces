#include <bits/stdc++.h>

using namespace std;
int w, n, t[52], baj;
int main()
{
    cin >> w;
    while (w--) {
        cin >> n;
        baj=0;
        for (int i=1; i<=n; i++) {
            cin >> t[i];
            if (t[i]!=i) {
                baj=1;
            }
        }
        if (!baj) {
            cout << 0 << "\n";
        } else {
            if (t[1]==1 || t[n]==n) {
                cout << 1 << "\n";
            } else if (t[1]==n && t[n]==1) {
                cout << 3 << "\n";
            } else {
                cout << 2 << "\n";
            }
        }
    }
    return 0;
}
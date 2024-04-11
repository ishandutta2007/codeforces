#include <bits/stdc++.h>

using namespace std;
const int c=1000002;
int w, n, le[c], fel[c], ert, kezd, veg;
string s;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while (w--) {
        cin >> s;
        n=s.size(), kezd=ert=5e5;
        for (char i:s) {
            if (i=='1') {
                fel[ert++]++;
            } else {
                le[ert--]++;
            }
        }
        veg=ert;
        ert=kezd;
        for (int i=0; i<n; i++) {
            if (le[ert] && (!fel[ert] || fel[ert-1])) {
                cout << 0;
                le[ert--]--;
            } else {
                cout << 1;
                fel[ert++]--;
            }
        }
        cout << "\n";
    }
    return 0;
}
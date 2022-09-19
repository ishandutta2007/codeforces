#include <bits/stdc++.h>

using namespace std;
const int c=200005;
int w, n, k, maxi, pref[c][3];
string s;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while (w--) {
        cin >> n >> k;
        cin >> s;
        for (int i=1; i<=n; i++) {
            int ert=(s[i-1]=='R' ? 0 : s[i-1]=='G' ? 1 : 2);
            ert=(i-ert+3)%3;
            for (int j=0; j<3; j++) pref[i][j]=pref[i-1][j];
            pref[i][ert]++;
        }
        for (int i=k; i<=n; i++) {
            for (int j=0; j<3; j++) {
                maxi=max(maxi, pref[i][j]-pref[i-k][j]);
            }
        }
        cout << k-maxi << "\n";
        maxi=0;
    }
    return 0;
}
#include <bits/stdc++.h>

using namespace std;
int w, n;
string a, b;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while (w--) {
        cin >> n >> a >> b;
        int da=0, db=0;
        bool baj=0;
        for (int i=0; i<n; i++) {
            if (i>0 && (da || db) && ((a[i]==b[i]) != (a[i-1]==b[i-1]))) {
                baj=1;
            }
            if (a[i]=='1') {
                da++;
            } else {
                da--;
            }
            if (b[i]=='1') {
                db++;
            } else {
                db--;
            }
        }
        if (a[n-1]!=b[n-1] && (da || db)) {
            baj=1;
        }
        cout << (baj? "NO" : "YES") << "\n";
    }
    return 0;
}
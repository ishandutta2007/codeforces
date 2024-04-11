#include <bits/stdc++.h>

using namespace std;
int w, n, db;
string sz[202];
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while(w--) {
        cin >> n;
        for (int i=0; i<n; i++) {
            cin >> sz[i];
        }
        db=(sz[0][1]=='1')+(sz[1][0]=='1')+(sz[n-1][n-2]=='0')+(sz[n-2][n-1]=='0');
        cout << min(db, 4-db) << "\n";
        if (db>2) {
            if (sz[0][1]!='1') cout << 1 << " " << 2 << "\n";
            if (sz[1][0]!='1') cout << 2 << " " << 1 << "\n";
            if (sz[n-2][n-1]!='0') cout << n-1 << " " << n << "\n";
            if (sz[n-1][n-2]!='0') cout << n << " " << n-1 << "\n";
        } else {
            if (sz[0][1]!='0') cout << 1 << " " << 2 << "\n";
            if (sz[1][0]!='0') cout << 2 << " " << 1 << "\n";
            if (sz[n-2][n-1]!='1') cout << n-1 << " " << n << "\n";
            if (sz[n-1][n-2]!='1') cout << n << " " << n-1 << "\n";
        }
    }
    return 0;
}
#include <bits/stdc++.h>

using namespace std;
int w, db, n, m;
int main()
{
    cin >> w;
    while(w--) {
        cin >> n >> m, db=-2;
        for (int i=1; i<=n; i++) for (int j=1; j<=m; j++) {
            char c; cin >> c;
            if (i==n && c!='R') db++;
            if (j==m && c!='D') db++;
        }
        cout << db << "\n";
    }
    return 0;
}
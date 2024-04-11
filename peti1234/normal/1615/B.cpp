#include <bits/stdc++.h>

using namespace std;
const int c=200005;
int w, db[c][20];
int main()
{
    ios_base::sync_with_stdio(false);
    for (int i=1; i<c; i++) {
        for (int j=0; j<20; j++) {
            db[i][j]=db[i-1][j]+(i & (1<<j) ? 1 : 0);
        }
    }
    cin >> w;
    while (w--) {
        int l, r;
        cin >> l >> r;
        int maxi=0;
        for (int i=0; i<20; i++) {
            maxi=max(maxi, db[r][i]-db[l-1][i]);
        }
        cout << r-l+1-maxi << "\n";
    }
    return 0;
}
#include <bits/stdc++.h>

using namespace std;
const int c=505, lkkt=720720;
// 720720=16*9*5*7*11*13;
int n, m, a[c][c], valasz[c][c];
int main()
{
    cin >> n >> m;
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=m; j++) {
            cin >> a[i][j];
            if ((i+j)%2) {
                valasz[i][j]=lkkt;
            } else {
                valasz[i][j]=lkkt+pow(a[i][j], 4);
            }
        }
    }
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=m; j++) {
            cout << valasz[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}
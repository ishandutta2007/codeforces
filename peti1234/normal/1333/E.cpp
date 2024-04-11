#include <bits/stdc++.h>

using namespace std;
int n, kov=1;
int t[502][502];
void ert(int a, int b) {
    t[a][b]=kov, kov++;
}
int main()
{
    cin >> n;
    if (n<=2) {
        cout << -1 << "\n";
        return 0;
    }
    if (n==3) {
        cout << 1 << " " << 3 << " " << 2 << "\n";
        cout << 5 << " " << 4 << " " << 8 << "\n";
        cout << 9 << " " << 6 << " " << 7 << "\n";
        return 0;
    }
    for (int i=n-3; i>=1; i--) ert(i, n);
    for (int i=1; i<=n-1; i++) {
        for (int j=1; j<=n-1; j++) {
            if (i%2==n%2) ert(i, n-j);
            else ert(i, j);
        }
    }
    t[n-2][n]=n*n, t[n][n]=n*n-1;
    ert(n, n-2), ert(n, n-1), ert(n-1, n);
    for (int i=1; i<=n-3; i++) ert(n, i);
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=n; j++) cout << t[i][j] << " ";
        cout << "\n";
    }
    return 0;
}
// Szp feladat, konkrt szmok kirsnl lehet szvegknt is rni.
#include <bits/stdc++.h>

using namespace std;
int sor[101];
int oszlop[101];
int mezo[101][101];
int n, m, h;
int main()
{
    cin >> n >> m >> h;
    for (int i=1; i<=m; i++) {
        cin >> sor[i];
    }
    for (int i=1; i<=n; i++) {
        cin >> oszlop[i];
    }
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=m; j++) {
            cin >> mezo[i][j];
        }
    }
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=m; j++) {
            if (mezo[i][j]==1) {
                mezo[i][j]=min(oszlop[i], sor[j]);
            }
            cout << mezo[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}
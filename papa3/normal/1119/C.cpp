#include <bits/stdc++.h>

using namespace std;

#define int long long
#define double long double
#define mod 1000000007ll
#define INF 1000000000000000000ll

int n, m;
int tab[2][700][700];

void zamien(int x, int y) {
    tab[0][x][y] ^= 1;
    tab[0][x+1][y] ^= 1;
    tab[0][x][y+1] ^= 1;
    tab[0][x+1][y+1] ^= 1;
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for (int k=0; k<2; k++) {
        for (int i=1; i<=n; i++) {
            for (int j=1; j<=m; j++) {
                cin >> tab[k][i][j];
            }
        }
    }

    for (int i=1; i<n; i++) {
        for (int j=1; j<m; j++) {
            if (tab[0][i][j] != tab[1][i][j]) {
                zamien(i, j);
            }
        }
    }

    for (int i=1; i<=n; i++) {
        for (int j=1; j<=m; j++) {
            if (tab[0][i][j] != tab[1][i][j]) {
                cout << "No";
                return 0;
            }
        }
    }
    cout << "Yes";

    return 0;
}/*

*/
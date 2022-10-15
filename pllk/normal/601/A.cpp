#include <iostream>

using namespace std;

int n, m;

int d1[444][444];
int d2[444][444];

#define A 999999999

int main() {
    ios_base::sync_with_stdio(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++) {
        d1[i][j] = A;
        d2[i][j] = A;
    }
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        d1[a][b] = 1;
        d1[b][a] = 1;
    }
    for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++) {
        if (d1[i][j] == 1) continue;
        d2[i][j] = 1;
    }
    for (int k = 1; k <= n; k++)
    for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++) {
        d1[i][j] = min(d1[i][j],d1[i][k]+d1[k][j]);
        d2[i][j] = min(d2[i][j],d2[i][k]+d2[k][j]);
    }
    if (d1[1][n] == A || d2[1][n] == A) {
        cout << "-1\n";
    } else {
        cout << max(d1[1][n],d2[1][n]) << "\n";
    }
}
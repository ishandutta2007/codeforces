#include <iostream>

using namespace std;

int h, w;
string g[555];
int c1[555][555];
int c2[555][555];
int s1[555][555];
int s2[555][555];
int q;

int main() {
    ios_base::sync_with_stdio(0);
    cin >> h >> w;
    for (int i = 1; i <= h; i++) cin >> g[i];
    for (int i = 1; i <= h; i++) {
        g[i] = "#"+g[i];
        for (int j = 1; j <= w; j++) {
            if (g[i][j] == '.' && g[i][j-1] == '.') c1[i][j] = 1;
            if (g[i][j] == '.' && g[i-1][j] == '.') c2[i][j] = 1;
        }
    }
    for (int i = 1; i <= h; i++) {
        for (int j = 1; j <= w; j++) {
            s1[i][j] = c1[i][j];
            s1[i][j] += s1[i-1][j]+s1[i][j-1]-s1[i-1][j-1];
            s2[i][j] = c2[i][j];
            s2[i][j] += s2[i-1][j]+s2[i][j-1]-s2[i-1][j-1];
        }
    }
    cin >> q;
    for (int i = 1; i <= q; i++) {
        int r1, c1, r2, c2;
        cin >> r1 >> c1 >> r2 >> c2;
        int u = 0;
        u += s1[r2][c2]-s1[r1-1][c2]-s1[r2][c1]+s1[r1-1][c1];
        u += s2[r2][c2]-s2[r1][c2]-s2[r2][c1-1]+s2[r1][c1-1];
        cout << u << "\n";
    }
}
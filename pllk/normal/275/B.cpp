#include <iostream>

using namespace std;

int n, m;
string g[50];

bool este(int y1, int x1, int y2, int x2) {
    int ys = (y1 > y2) ? -1 : 1;
    int xs = (x1 > x2) ? -1 : 1;
    if (y1 == y2) {
        while (x1 != x2) {
            x1 += xs;
            if (g[y1][x1] == 'W') return true;
        }
        return false;
    }
    if (x1 == x2) {
        while (y1 != y2) {
            y1 += ys;
            if (g[y1][x1] == 'W') return true;
        }
        return false;
    }
    int yv = y1;
    int xv = x1;
    bool v = false;
    while (x1 != x2) {
        x1 += xs;
        if (g[y1][x1] == 'W') v = true;
    }
    while (y1 != y2) {
        y1 += ys;
        if (g[y1][x1] == 'W') v = true;
    }
    if (!v) return false;
    y1 = yv;
    x1 = xv;
    v = false;
    while (y1 != y2) {
        y1 += ys;
        if (g[y1][x1] == 'W') v = true;
    }
    while (x1 != x2) {
        x1 += xs;
        if (g[y1][x1] == 'W') v = true;
    }
    return v;
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> g[i];
    }
    bool v = false;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            for (int a = 0; a < n; a++) {
                for (int b = 0; b < m; b++) {
                    if (g[i][j] == 'W') continue;
                    if (g[a][b] == 'W') continue;
                    if (este(i, j, a, b)) v = true;
                }
            }
        }
    }
    if (v) cout << "NO" << endl;
    else cout << "YES" << endl;
}
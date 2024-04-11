#include <bits/stdc++.h>

using namespace std;

const int N = 200;

int n, m;
char a[N][N];

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%s", a[i] + 1);
    }
    int x = -1, y = -1;
    for (int i = 1; i <= n && x == -1; i++) {
        for (int j = 1; j <= m && y == -1; j++) {
            if (a[i][j] == 'B') {
                x = i;
                y = j;
                break;
            }
        }
    }
    int xx = -1, yy = - 1;
    for (int i = n; i > 0 && xx == -1 ; i--) {
        for (int j = m; j > 0 && yy == -1; j--) {
            if (a[i][j] == 'B') {
                xx = i;
                yy = j;
                break;
            }
        }
    }
    cout << (x + xx) / 2 << " " << (y + yy) / 2 << endl;
    return 0;
}
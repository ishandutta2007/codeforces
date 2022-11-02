#include <iostream>

using namespace std;
const int N = 100 + 10;

int mas[N];
char pr[N][N];

int main() {
    ios_base::sync_with_stdio(false);
    int a, b, c, d, n;
    cin >> a >> b >> c >> d >> n;
    for (int i = 1; i <= n; i++) {
        cin >> mas[i];
    }
    int nn = max(b, d);
    int mm = a + c;
    for (int i = 1; i <= nn; i++) {
        for (int j = 1; j <= mm; j++) {
            pr[i][j] = '.';
        }
    }
    for (int i = 1; i <= b; i++) {
        for (int j = 1; j <= a; j++) {
            pr[i][j] = '?';
        }
    }
    for (int i = 1; i <= d; i++) {
        for (int j = 1; j <= c; j++) {
            pr[i][j + a] = '?';
        }
    }
    int sx, sy, dy;
    if ((b > d && d % 2 == 0) || (b < d && b % 2 == 1)) {
        sx = 1, sy = 1, dy = 1;
    } else {
        sx = 1, sy = a + c, dy = -1;
    }
    int it = 1;
    while (sx <= nn) {
        pr[sx][sy] = 'a' + it - 1;
        mas[it]--;
        if (mas[it] == 0) {
            it++;
        }
        sy += dy;
        if (pr[sx][sy] != '?') {
            sx++;
            dy *= -1;
            sy += dy;
        }
    }
    cout << "YES\n";
    for (int i = 1; i <= nn; i++) {
        for (int j = 1; j <= mm; j++) {
            cout << pr[i][j];
        }
        cout << "\n";
    }
    return 0;
}
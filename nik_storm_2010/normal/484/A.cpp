#include <iostream>
#include <memory.h>

using namespace std;
typedef long long ll;
const int BITS = 64;

int f[BITS][2][2], bx[BITS], by[BITS];
ll v[BITS][2][2];

int main() {
    ios_base::sync_with_stdio(false);
    int tests;
    cin >> tests;
    for (int t = 1; t <= tests; t++) {
        for (int i = 0; i < BITS; i++) for (int sx = 0; sx < 2; sx++) for (int sy = 0; sy < 2; sy++) f[i][sx][sy] = -1, v[i][sx][sy] = 0;
        ll x, y;
        cin >> x >> y;
        for (int i = 0; i < BITS; i++, x /= 2) bx[i] = x % 2;
        for (int i = 0; i < BITS; i++, y /= 2) by[i] = y % 2;
        f[BITS - 1][0][0] = 0;
        for (int i = BITS - 1; i > 0; i--) for (int sx = 0; sx < 2; sx++) for (int sy = 0; sy < 2; sy++) for (int bit = 0; bit < 2; bit++) {
            if (f[i][sx][sy] == -1) continue;
            int nx = sx, ny = sy;
            if (sx == 0 && bit == 0 && bx[i - 1] == 1) continue;
            if (sx == 0 && bit == 1 && bx[i - 1] == 0) nx = 1;
            if (sy == 0 && bit == 1 && by[i - 1] == 0) continue;
            if (sy == 0 && bit == 0 && by[i - 1] == 1) ny = 1;
            if ((f[i - 1][nx][ny] < f[i][sx][sy] + bit) || (f[i - 1][nx][ny] == f[i][sx][sy] + bit && v[i - 1][nx][ny] > v[i][sx][sy] + (1LL << (i - 1)) * bit))  {
                f[i - 1][nx][ny] = f[i][sx][sy] + bit;
                v[i - 1][nx][ny] = v[i][sx][sy] + (1LL << (i - 1)) * bit;
            }
        }
        int ans = 0;
        ll print;
        for (int sx = 0; sx < 2; sx++) for (int sy = 0; sy < 2; sy++) if (f[0][sx][sy] > ans || (f[0][sx][sy] == ans && print > v[0][sx][sy])) {
            ans = f[0][sx][sy];
            print = v[0][sx][sy];
        }
        cout << print << "\n";
    }
    return 0;
}
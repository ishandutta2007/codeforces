#include <iostream>

using namespace std;

typedef long long ll;


int main() {
    int t;
    cin >> t;
    while (t--) {
        ll n, m, i, j;
        cin >> n >> m >> i >> j;
        ll z = -1;
        ll r1, r2, r3, r4;
        for (int y1 = 0; y1 <= 1; y1++)
        for (int x1 = 0; x1 <= 1; x1++)
        for (int y2 = 0; y2 <= 1; y2++)
        for (int x2 = 0; x2 <= 1; x2++) {
            ll ya = y1 == 0 ? 1 : n;
            ll xa = x1 == 0 ? 1 : m;
            ll yb = y2 == 0 ? 1 : n;
            ll xb = x2 == 0 ? 1 : m;
            ll d = 0;
            d += abs(i-ya)+abs(j-xa);
            d += abs(ya-yb)+abs(xa-xb);
            d += abs(yb-i)+abs(xb-j);
            if (z == -1 || d > z) {
                z = d;
                r1 = ya; r2 = xa; r3 = yb; r4 = xb;
            }
        }
        cout << r1 << " " << r2 << " " << r3 << " " << r4 << "\n";
    }
}
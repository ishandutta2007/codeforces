#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;

#define int long long

int dx[] = {1, 0, -1, 0, 1, -1, -1, 1};
int dy[] = {0, 1, 0, -1, 1, 1, -1, -1};

int p, y;

signed main() {
    cin >> p >> y;
    while (true) {
        for (int i = 2; i <= p && i <= sqrt(y); i++) {
            if (y % i == 0) {
                goto check;
            }
        }
        if (y <= p) {
            cout << -1 << endl;
            return 0;
        }
        break;
    check:
        y--;
    }
    cout << y << endl;
    return 0;
}
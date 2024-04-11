#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5;
int used[2][MAXN];

main() {
    int n, q;
    cin >> n >> q;
    int cnt = 0;
    for (int i = 0; i < q; ++i) {
        int x, y;
        cin >> x >> y;
        x--;
        int m = 1;
        if (used[x][y]) {
            m = -1;
        }
        int c = 0;
        for (int j = y - 1; j <= y + 1; ++j) {
            if (used[x ^ 1][j]) {
                c++;
                cnt += m;
            }
        }
        used[x][y] ^= 1;
        cnt += c * m;
        if (cnt) {
            cout << "No" << endl;
        } else {
            cout << "Yes" << endl;
        }
    }
    return 0;
}
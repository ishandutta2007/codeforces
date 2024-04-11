#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n, m, rb, cb, rd, cd;
        cin >> n >> m >> rb >> cb >> rd >> cd;

        int dr = 1, dc = 1;
        for (int ans = 0;; ans++) {
            if (rb == rd || cb == cd) {
                cout << ans << '\n';
                break;
            }
            if (!(1 <= rb + dr && rb + dr <= n)) {
                dr = -dr;
            }
            if (!(1 <= cb + dc && cb + dc <= m)) {
                dc = -dc;
            }
            rb += dr;
            cb += dc;
        }
    }
    return 0;
}
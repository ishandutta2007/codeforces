#include <bits/stdc++.h>
using namespace std;
using lint = long long;
// #define TESTCASE
int solve();
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    #ifdef TESTCASE
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    #else
    solve();
    #endif
    return 0;
}

int solve() {

    lint y, b, r;
    cin >> y >> b >> r;
    lint ans = 0;
    for (int i = 0; i <= y; i++) {
        for (int j = 0; j <= b; j++) {
            for (int k = 0; k <= r; k++) {
                if (j == i + 1 && k == j + 1) {
                    ans = max(ans, (lint)i + j + k);
                }
            }
        }
    }
    cout << ans << "\n";

}
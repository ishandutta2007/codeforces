#include <bits/stdc++.h>
using namespace std;
using lint = long long;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int t;
    cin >> t;
    while (t--) {
        lint n, d;
        cin >> n >> d;
        // x + d/(x + 1) <= n
        // x * (x + 1) + d <= n * (x + 1)
        // x^2 + (1 - n)x + d - n <= 0

        lint l = 0, r = 1e18;
        while (r - l > 1000) {
            lint m1 = (l + l + r) / 3;
            lint m2 = (l + r + r) / 3;
            if (m1 + ceil(1.00 * d / (m1 + 1)) < m2 + ceil(1.00 * d / (m2 + 1))) {
                r = m2;
            } else {
                l = m1;
            }
        }
        lint ans = 1e18;
        for (lint i = l; i <= r; i++) {
            ans = min(ans, i + (lint)ceil(1.00 * d / (i + 1)));
        }
        if (ans <= n) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }


}
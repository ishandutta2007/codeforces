#include <bits/stdc++.h>
// #define TESTCASE
using namespace std;
using lint = long long;
int solve();
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int T;
    #ifdef TESTCASE
    cin >> T;
    #else
    T = 1;
    #endif
    while (T--) {
        solve();
    }
    return 0;
}


int solve() {
    lint N, K;
    cin >> N >> K;
    lint ans = 0;

    auto check = [&](lint n) {
        lint res = 0;
        lint cntr = 1;
        if (n % 2 == 0) {
            if (n + 1 <= N) cntr++, n++;
        }
        while (n <= N) {
            res += cntr;
            cntr = 2 * cntr;
            n = n * 2 + 1;
        }
        res += max(0ll, cntr - (n - N));
        return res;
    };

    for (lint j = 60; j >= 0; j--) {
        if (check(ans ^ (1ll << j)) >= K) {
            ans ^= (1ll << j);
        }
    }

    cout << ans << "\n";

}
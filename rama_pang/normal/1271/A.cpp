#include <bits/stdc++.h>
// #define TESTCASE
using namespace std;
using lint = long long;
#define int lint
int solve();
int32_t main() {
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
    lint a, b, c, d, e, f;
    cin >> a >> b >> c >> d >> e >> f;
    lint t[2];
    t[0] = a;
    t[1] = min(b, c);
    
    d = min(d, t[0] + t[1]);

    lint ans = 0;
    for (int i = 0; i <= a; i++) {
        int o = min(max(d - i, 0ll), min(b, c));
        ans = max(ans, min(d - o, i) * e + min(d - i, min(b, c)) * f);
    }
    cout << ans << "\n";

}
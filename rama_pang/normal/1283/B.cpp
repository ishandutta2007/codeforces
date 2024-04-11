#include <bits/stdc++.h>
using namespace std;
using lint = long long;
int solve();
#define TESTCASE
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
    
    lint n, k;
    cin >> n >> k;

    lint ans = (n / k) * k;

    lint m = n % k;
    if (m > 0) {
        ans += min(m, k / 2);
    }
    cout << ans << "\n";

}
#include <bits/stdc++.h>
#define TESTCASE
using namespace std;
using lint = long long;

void solve() {

    lint N, K; cin >> N >> K;
    lint ans = 0;
    while (N > 0) {
        ans += N % K;
        N /= K;
        if (N > 0) ans++;
    }
    cout << ans << "\n";

}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int tc = 1;
    #ifdef TESTCASE
    cin >> tc;
    #endif

    while (tc--) solve();
}
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

    int h, m;
    cin >> h >> m;
    int t = h * 60 + m;
    t = 1440 - t;
    cout << t << "\n";

}
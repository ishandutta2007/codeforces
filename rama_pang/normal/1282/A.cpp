#include <bits/stdc++.h>
using namespace std;
using lint = long long;
#define TESTCASE



int solve() {

    lint a, b, c, r;
    cin >> a >> b >> c >> r;
    if (a > b) {
        swap(a, b);
    }
    lint p1 = c - r, p2 = c + r;
    lint ans = 0;
    if (b <= p1) {
        ans += b - a;
    } else if (a >= p2) {
        ans += b - a;
    } else {
    if (a <= p1) {
        ans += p1 - a;
    }
    if (p2 <= b) {
        ans += b - p2;
    }
    }
        
    cout << ans << "\n";



}

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
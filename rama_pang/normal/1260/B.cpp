#include <bits/stdc++.h>
#define TESTCASE
using namespace std;
using lint = long long;

void solve() {
    lint a, b; cin >> a >> b;
    lint x;
    while (a > 0 && b > 0) {
        if (a > b) {
            x = a - b;
            a -= 2 * x;
            b -= x;
        } else if (a < b) {
            x = b - a;
            a -= x;
            b -= 2 * x;
        } else if (a == b) {
            if (a % 3 == 0) {
                cout << "YES\n";
            } else {
                cout << "NO\n";
            }
            return;
        }
    }

    if (a == b && a == 0) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }


}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int tc = 1;

    #ifdef TESTCASE
    cin >> tc;
    #endif
    
    while (tc--) {
        solve();
    }
}
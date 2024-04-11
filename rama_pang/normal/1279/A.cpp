#include <bits/stdc++.h>
#define TESTCASE
using namespace std;
using lint = long long;
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

    lint a[3];
    cin >> a[0] >> a[1] >> a[2];
    sort(a, a + 3);

    if (a[2] > a[0] + a[1] + 1) {
        cout << "No\n";
    } else {
        cout << "Yes\n";
    }




}
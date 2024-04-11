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

    lint n, s;
    cin >> n >> s;
    vector<lint> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    lint ans = 0;
    lint opt = 0;
    lint sum = 0;
    lint mx = -1;
    int j = -1;

    for (int i = 0; i < a.size(); i++) {
        bool br = false;
        sum += a[i];
        if (sum > s) {
            j = i;
            br = true;
        }
        if (mx < a[i]) {
            opt = i;
            mx = a[i];
        }
        if (br) break;
    }

    if (sum <= s) {
        cout << 0 << "\n";
        return 0;
    }

    cout << opt + 1 << "\n";
    return 0;
    
}
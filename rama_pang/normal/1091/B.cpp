#include <bits/stdc++.h>
using namespace std;
using lint = long long;
// #define TESTCASE
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

    int n;
    cin >> n;
    vector<int> x(n), y(n), a(n), b(n);
    for (int i = 0; i < n; i++) {
        cin >> x[i] >> y[i];
    }
    map<pair<int, int>, int> used, sv;
    for (int i = 0; i < n; i++) {
        cin >> a[i] >> b[i];
        used[{a[i], b[i]}]++;
    }
    sv = used;

    for (int t = 0; t < n; t++) {
        int xx = x[0] + a[t];
        int yy = y[0] + b[t];
        used[{a[t], b[t]}]--;
        bool can = true;
        for (int i = 1; i < n; i++) {
            if ((used[{- x[i] + xx, - y[i] + yy}]) == 0) {
                can = false;
                break;
            }
            used[{- x[i] + xx, - y[i] + yy}]--;
        }
        if (can) {
            cout << xx << " " << yy << "\n";
            return 0;
        }
        used = sv;
    }

}
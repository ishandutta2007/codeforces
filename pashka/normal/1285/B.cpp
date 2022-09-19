#include <bits/stdc++.h>
#define long long long int
using namespace std;

// @author: pashka

void solve_test() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    long ll = 0;
    long rr = 0;
    long res = LONG_MIN;
    for (int i = 0; i < n; i++) {
        rr += a[i];
        if (i < n - 1) res = max(res, rr);
        res = max(res, rr - ll);
        if (i == 0) {
            ll = rr;
        } else {
            ll = min(ll, rr);
        }
    }
//    cerr << res << " " << rr << "\n";
    if (res < rr) {
        cout << "YES";
    } else {
        cout << "NO";
    }
    cout << "\n";
}

int main() {
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        solve_test();
    }

    return 0;
}
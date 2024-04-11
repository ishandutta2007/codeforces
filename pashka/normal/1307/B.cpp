#include <bits/stdc++.h>
#define long long long int
using namespace std;

// @author: pashka

void solve_test() {
    int n, x; cin >> n >> x;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    int mx = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] == x) {
            cout << 1 << "\n";
            return;
        }
        mx = max(mx, a[i]);
    }
    cout << max((x + mx - 1) / mx, 2) << "\n";
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
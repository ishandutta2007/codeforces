#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cout << fixed << setprecision(10);

    int T;
    cin >> T;

    while (T--) {
        int n;
        cin >> n;

        vector<int> x(n), t(n);
        for (int i = 0; i < n; i++) cin >> x[i];
        for (int i = 0; i < n; i++) cin >> t[i];

        int mn = 2e8, mx = -2e8;
        for (int i = 0; i < n; i++) {
            mn = min(mn, x[i] - t[i]);
            mx = max(mx, x[i] + t[i]);
        }

        cout << (mx + mn) / 2.0 << '\n';
    }
    return 0;
}
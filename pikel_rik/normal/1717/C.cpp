#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> a(n);
        for (auto &x : a) cin >> x;

        vector<int> b(n);
        for (auto &x : b) cin >> x;

        bool ok = true;
        for (int i = 0; i < n; i++) {
            ok &= a[i] <= b[i];
        }

        if (!ok) {
            cout << "NO\n";
            continue;
        }

        int mn = min_element(b.begin(), b.end()) - b.begin();
        for (auto &x : a) {
            x = max(x, b[mn]);
        }

        for (int i = mn - 1; i >= 0; i--) {
            a[i] = max(a[i], a[i + 1] + 1);
            a[i] = min(a[i], b[i]);
        }

        for (int i = n - 1; i > mn; i--) {
            a[i] = max(a[i], a[(i + 1) % n] + 1);
            a[i] = min(a[i], b[i]);
        }

        for (int i = 0; i < n; i++) {
            ok &= a[i] == b[i];
        }

        cout << (ok ? "YES" : "NO") << '\n';
    }
    return 0;
}
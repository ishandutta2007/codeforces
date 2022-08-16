#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<long long> a(n);
        for (auto &x : a) cin >> x;

        long long g0 = 0, g1 = 0;
        for (int i = 0; i < n; i++) {
            if (i % 2 == 0) {
                g0 = gcd(g0, a[i]);
            } else {
                g1 = gcd(g1, a[i]);
            }
        }

        bool ok0 = true, ok1 = true;
        for (int i = 0; i < n; i++) {
            if (i % 2 == 0) {
                ok1 &= a[i] % g1 != 0;
            } else {
                ok0 &= a[i] % g0 != 0;
            }
        }

        if (ok0) {
            cout << g0 << '\n';
        } else if (ok1) {
            cout << g1 << '\n';
        } else {
            cout << 0 << '\n';
        }
    }
    return 0;
}
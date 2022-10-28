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

        vector<int> a(n);
        for (auto &x : a) cin >> x;

        vector<int> b(n + 1);
        b.front() = a.front(), b.back() = a.back();

        for (int i = 1; i < n; i++) {
            b[i] = lcm(a[i - 1], a[i]);
        }

        bool possible = true;
        for (int i = 0; i < n; i++) {
            possible &= a[i] == gcd(b[i], b[i + 1]);
        }

        cout << (possible ? "YES" : "NO") << '\n';
    }
    return 0;
}
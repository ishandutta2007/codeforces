#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;
using ll = long long;
using ld = long double;

const int mod = 1e9 + 7;
const double pi = acos(-1.0);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> a(n), b(n), c(n);
        for (int i = 0; i < n; ++i) cin >> a[i];
        for (int i = 0; i < n; ++i) cin >> b[i];
        for (int i = 0; i < n; ++i) cin >> c[i];

        vector<int> p(n);
        p[0] = a[0];

        for (int i = 1; i < n; i++) {
            if (a[i] != p[i - 1]) {
                p[i] = a[i];
            } else if (b[i] != p[i - 1]) {
                p[i] = b[i];
            } else {
                p[i] = c[i];
            }
        }

        if (p[n - 1] == p[0]) {
            if (a[n - 1] != p[n - 2] and a[n - 1] != p[0]) {
                p[n - 1] = a[n - 1];
            } else if (b[n - 1] != p[n - 2] and b[n - 1] != p[0]) {
                p[n - 1] = b[n - 1];
            } else {
                p[n - 1] = c[n - 1];
            }
        }

        for (int i = 0; i < n; i++) {
            cout << p[i] << " \n"[i + 1 == n];
        }
    }
    return 0;
}
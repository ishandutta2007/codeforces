#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;
using ll = long long;
using ld = long double;

const int mod = 1e9 + 7;
const int inf = INT_MAX;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        string a, b, c;
        cin >> a >> b >> c;

        int n = a.length();

        bool ans = true;
        for (int i = 0; i < n; i++) {
            if ((a[i] == b[i] and a[i] != c[i]) or (a[i] != c[i] and b[i] != c[i])) {
                ans = false;
            }
        }

        cout << (ans ? "YES" : "NO") << '\n';
    }
    return 0;
}
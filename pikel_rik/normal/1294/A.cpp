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
        int a, b, c, n;
        cin >> a >> b >> c >> n;

        n -= 3 * max({a, b, c}) - a - b - c;
        if (n >= 0 and n % 3 == 0)
            cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}
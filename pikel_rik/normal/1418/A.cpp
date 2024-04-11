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
        ll x, y, k;
        cin >> x >> y >> k; --x;

        ll target = y * k + k - 1;
        cout << k + (target + x - 1) / x << '\n';
    }
    return 0;
}
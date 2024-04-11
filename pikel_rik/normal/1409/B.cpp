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
        int a, b, x, y, n;
        cin >> a >> b >> x >> y >> n;

        ll ans = a * (ll)b;

        if (a - n < x) {
            int aa = x;
            int bb = max(b - (n - (a - x)), y);
            ans = min(ans, aa * (ll)bb);
        } else {
            ans = min(ans, (a - n) * (ll)b);
        }

        swap(a, b);
        swap(x, y);

        if (a - n < x) {
            int aa = x;
            int bb = max(b - (n - (a - x)), y);
            ans = min(ans, aa * (ll)bb);
        } else {
            ans = min(ans, (a - n) * (ll)b);
        }

        cout << ans << '\n';
    }
    return 0;
}
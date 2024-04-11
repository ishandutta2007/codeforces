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
        int x1, y1, z1, x2, y2, z2;
        cin >> x1 >> y1 >> z1 >> x2 >> y2 >> z2;

        int ans = min(z1, y2);
        z1 -= ans;
        y2 -= ans;
        ans *= 2;

        int temp = min(x1, z2);
        x1 -= temp;
        z2 -= temp;

        temp = min(y1, x2);
        y1 -= temp;
        x2 -= temp;

        temp = min(y1, y2);
        y1 -= temp;
        y2 -= temp;

        temp = min(z1, z2);
        z1 -= temp;
        z2 -= temp;

        ans -= 2 * min(y1, z2);
        cout << ans << "\n";
    }
    return 0;
}
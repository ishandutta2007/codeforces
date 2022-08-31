#include <bits/stdc++.h>
using namespace std;

#define all(x) (x).begin(), (x).end()

typedef unsigned long long ull;
typedef long long ll;

const int mod = 1e9 + 7;
const int inf = 2e9 + 5;
const int N = 101;

ll x, y, m;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> x >> y >> m;

    if (m <= x or m <= y) {
        cout << "0\n";
        return 0;
    }

    if (x <= 0 and y <= 0) {
        if (m > x and m > y) {
            cout << "-1\n";
            return 0;
        }
    }

    ll ans = 0;

    if (x < 0) {
        ll lo = (-x + y - 1) / y;

        ans += lo;
        x = x + y * lo;
    }
    else if (y < 0) {
        ll lo = (-y + x - 1) / x;

        ans += lo;
        y = y + x * lo;
    }

    while (x < m and y < m) {
        if (x < y)
            x = x + y;
        else y = x + y;
        ans += 1;
    }

    cout << ans << "\n";
    return 0;
}
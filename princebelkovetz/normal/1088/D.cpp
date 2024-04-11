#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <iomanip>
#include <cassert>

using namespace std;
#define int long long
#define ld long double
#define debug(x) cout << #x << " actually equals " << x << '\n';
const int mod = 998244353;
constexpr int bits = 30;
int query(int a, int b) {
    cout << "? " << a << ' ' << b << endl;
    int x; cin >> x;
    return x;
}
signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    cout << fixed << setprecision(6);
    int a = 0, b = 0, x, pre = 0;
    int add = 0;
    for (int i = bits - 1; i >= 0; --i) {
        int cur = (1 << i) + add;
        int y;
        if (pre) y = pre;
        else {
            y = query(a, b);
        }
        if (y == 0) {
            // 0 0 or 1 1
            x = query(a + (1 << i), b);
            if (x == 1) {
                // bruh
            }
            else {
                a += (1 << i), b += (1 << i);
            }
            pre = y;
        }
        else {
            x = query(a + (1 << i), b + (1 << i));
            if (x * y == -1) {
                if (y == 1) a += (1 << i);
                else b += (1 << i);
                pre = 0;
            }
            else {
                // 0 0 or 1 1
                x = query(a + (1 << i), b);
                if (x == 1) {
                    // bruh
                }
                else {
                    a += (1 << i), b += (1 << i);
                }
                pre = y;
            }
        }
    }
    cout << "! " << a << ' ' << b << endl;
    return 0;
}
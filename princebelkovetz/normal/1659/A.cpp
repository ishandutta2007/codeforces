#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <cmath>
#include <set>
#include <stack>
#include <map>
#include <cassert>
#include <numeric>

#define int long long
#define ld long double
#define debug(x) cout << #x << " is " << x << '\n';

using namespace std;
const int root = 212, mod = 1e18 + 7, N = 5e5 + 2, L = 30;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(6);

    int tt; cin >> tt;
    while (tt--) {
        int n, r, b; cin >> n >> r >> b;
        int sz = r / (b + 1);
        int cnt = r % (b + 1);
        string ans = "";
        for (;;) {
            if (sz <= r) {
                r -= sz + bool(cnt);
                ans += string(sz + bool(cnt), 'R');
                cnt = max(0ll, cnt - 1);
                if (b) ans += 'B', --b;
            }
            else {
                ans += string(r, 'R');
                break;
            }
        }
        cout << ans << '\n';
    }


    return 0;
}
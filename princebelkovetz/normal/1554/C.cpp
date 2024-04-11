#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <iomanip>
#include <queue>
#include <cassert>
#include <bitset>

using namespace std;

#define debug(x) cout << #x << " is " << x << '\n';
#define ld long double
#define int long long

const int N = 300 + 2, mod = 1e9 + 7;

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout << fixed << setprecision(6);
    int tt; cin >> tt;
    while (tt --> 0) {
        int n, m; cin >> n >> m;
        if (n > m) cout << "0\n";
        else if ((n & m) != n) {
            int ans = 0;
            for (int i = 31; i >= 0; --i) {
                int b1 = (n >> i) & 1, b2 = (m >> i) & 1;
                if (b1 and !b2) break;
                if (b2 and !b1) ans += (1 << i);
            }
            cout << ans << '\n';
        }
        else {
            int ans = n ^ m;
            for (int i = 0; i < 32; ++i) {
                if (((m >> i) & 1) and ((n >> i) & 1 ^ 1)) ans -= (1 << i);
                else if (((m >> i) & 1) and ((n >> i) & 1)) continue;
                else {
                    ans += (1 << i);
                    break;
                }
            }
            cout << ans << '\n';
        }
        
    }
    cout << '\n';
    return 0;
}
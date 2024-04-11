#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cassert>
#include <set>
#include <map>
#include <queue>
// made by @princebelkovetz //
using namespace std;
#define int long long
#define ld long double
#define debug(x) cout << #x << " equals " << x << '\n'; 
const int mod = 1e9 + 7;
signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout << fixed << setprecision(5);
    int tt; cin >> tt;
    while (tt--) {
        int n, sum = 0, mx = 0; cin >> n;
        vector <int> a(n);
        for (auto& x : a)
            cin >> x, sum += x, mx = max(mx, x);
        set <int> dels;
        for (int i = 1; i * i <= sum; ++i) {
            if (sum % i == 0)
                dels.insert(i), dels.insert(sum / i);
        }
        int ans = mod;
        for (auto x : dels) {
            if (x < mx) continue;
            int cur = 0, ind = 0, have = 0;
            while (ind < n) {
                while (have != x and ind < n) {
                    have += a[ind++];
                    cur++;
                }
                if (have != x) {
                    cur = mod, ind = n;
                    break;
                }
                else {
                    cur--;
                    have = 0;
                }
            }
            ans = min(ans, cur);
        }
        cout << ans << '\n';
    }
}
#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <cmath>
#include <set>
#include <stack>
#include <map>
#include <queue>
#include <cassert>
#include <numeric>
#include <climits>

#define int long long
#define ld long double
#define debug(x) cout << #x << " is " << x << '\n';

using namespace std;
const int root = 212, mod = 1e9 + 7, B = 60, N = 1e3 + 15;


signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(6);

    int tt; cin >> tt;
    while (tt--) {
        int n, k, ans = 0; cin >> n >> k;
        vector <int> a(n), d;
        for (auto& x : a) cin >> x, ans += x;
        for (int i = 0; i < n; ++i) {
            d.push_back(-a[i] + (n - i - 1));
        }
        ans -= k * (k - 1) / 2;
        sort(d.begin(), d.end());
        for (int i = 0; i < k; ++i) ans += d[i];
        cout << ans << '\n';
    }

    return 0;
}
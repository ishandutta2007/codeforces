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
#include <climits>

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
        int n, a, b; cin >> n >> a >> b;
        vector <int> xs(n + 1), p(n + 2);
        for (int i = 1; i <= n; ++i) cin >> xs[i];
        for (int i = 0; i <= n; ++i) p[i + 1] = p[i] + xs[i];
        int ans = LLONG_MAX;
        for (int i = 0; i <= n; ++i) {
            ans = min(ans, a * xs[i] + b * xs[i] + b * (p[n + 1] - p[i + 1] - xs[i] * (n - i)));
        }
        cout << ans << '\n';
    }


    return 0;
}
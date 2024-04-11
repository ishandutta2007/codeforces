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

#define ld long double
#define debug(x) cout << #x << " is " << x << '\n';

using namespace std;
const int root = 212, mod = 998244353, N = 2e5 + 12;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(6);

    int n, k; cin >> n >> k;
    int m = 2 * sqrt(n) + 3;
    vector <int> dp(n + 1), ans(n + 1);
    dp[0] = 1;
    for (int i = 1; i < m; i++) {
        vector <int> ndp(n + 1); 
        int cur = k + i - 1;
        for (int x = cur; x <= n; ++x) {
            ndp[x] = (ndp[x - cur] + dp[x - cur]) % mod;
        }
        for (int i = 1; i <= n; ++i) 
            ans[i] += ndp[i], ans[i] %= mod;
        ndp.swap(dp);
    }
    for (int i = 1; i <= n; i++) 
        cout << ans[i] << ' ';
    cout << '\n';

    return 0;
}
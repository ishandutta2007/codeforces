#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <string>
#include <cmath>
#include <set>
#include <stack>
#include <map>
#include <unordered_map>
#include <queue>
#include <iterator>
#include <sstream>
#include <cassert>
#include <locale>
#include <numeric>
#include <random>
#include <bitset>

#define int long long
#define ld long double
#define debug(x) cout << #x << " is " << x << '\n';

using namespace std;
const int root = 212, mod = 1e9 + 7;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(8);

    int n; cin >> n;
    vector <int> a(n);
    for (auto& x : a) cin >> x;


    vector <vector <int>> dp(n, vector <int>(n));

    for (int r = 0; r < n; ++r) {
        vector <int> dp2(n);
        dp[r][r] = 1;
        for (int l = r; l >= 1; --l) {
            dp2[l] = dp[l][r];
            for (int k = l + 1; k <= r; ++k) {
                if (a[l] < a[k]) 
                    dp2[l] += dp[l][k - 1] * dp2[k] % mod, dp2[l] %= mod;
            }
            dp[l - 1][r] = dp2[l];
        }
    }
    cout << dp[0][n - 1] << '\n';

    return 0;
}
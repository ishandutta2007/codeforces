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
#include <functional>

#define int long long
#define ld long double
#define debug(x) cout << #x << " is " << x << '\n';

using namespace std;
const int mod = 998244353, p = 239, N = 1e3 + 1e2;

int fct[N], rfct[N];
int binpow(int a, int b) {
    if (!b) return 1ll;
    if (b & 1) return a * binpow(a, b - 1) % mod;
    int t = binpow(a, b / 2);
    return t * t % mod;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(8);

    fct[0] = rfct[0] = 1;
    for (int i = 1; i < N; ++i) {
        fct[i] = fct[i - 1] * i % mod;
        rfct[i] = binpow(fct[i], mod - 2);
    }

    int n, k; cin >> n >> k;
    vector <vector <int>> dp(n, vector <int>(k + 1, 0));
    dp[0][0] = 1;
    for (int i = 1; i < n; ++i) {
        for (int s = 1; s <= i; ++s) {
            int cur = 0;
            int am = s * (i - s) + s * (s - 1) / 2;
            for (int j = 1; j <= k; ++j) {
                cur = (cur + dp[i - s][j - 1]) % mod;
                dp[i][j] += cur * rfct[s] % mod * binpow(k - j + 1, am) % mod;
                dp[i][j] %= mod;
            }
        }
    }
    int ans = 0;
    for (auto& x : dp[n - 1])
        ans = (ans + x) % mod;

    cout << ans * fct[n - 1] % mod << '\n';

    return 0;
}
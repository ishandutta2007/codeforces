
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
#include <random>

using namespace std;
mt19937 rnd(239);

#define debug(x) cout << #x << " is " << x << '\n';
#define ld long double
#define int long long
const int mod = 1e9 + 7, p = 239, N = 2e5 + 5;

int binpow(int a, int b) {
    if (!b) return 1;
    if (b & 1) return a * binpow(a, b - 1) % mod;
    int t = binpow(a, b / 2);
    return t * t % mod;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout << fixed << setprecision(6);

    int tt; cin >> tt;
    while (tt--) {
        int n, k; cin >> n >> k;
        vector <int> dp(k + 1), pws(max(n, k) + 5, 1);
        for (int i = 1; i < max(n, k) + 5; ++i)
            pws[i] = (pws[i - 1] * 2) % mod;
        dp[0] = 1;
        for (int i = 1; i <= k; ++i) {
            dp[i] = (dp[i - 1] * (pws[n - 1] - (n & 1 ^ 1))) % mod;
            if (n & 1 ^ 1) {
                dp[i] += binpow(pws[i - 1], n);
                dp[i] %= mod;
            }
            else dp[i] = (dp[i] + dp[i - 1]) % mod;
        }
        cout << dp[k] << '\n';
    }

    return 0;
}
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

const int mod = 998244353, N = 200;

int solve(int n, int m, vector <pair <int, int>> a) {
    vector <vector <int>> dp(n + 1, vector <int>(m + 1));
    dp[0][0] = 1;
    for (int i = 1; i <= n; ++i) {
        vector <int> pref(m + 1);
        pref[0] = dp[i - 1][0];
        for (int j = 1; j <= m; ++j)
            pref[j] = (dp[i - 1][j] + pref[j - 1]) % mod;
        for (int j = 0; j <= m; ++j) {
            int l = j - a[i - 1].second, r = j - a[i - 1].first;
            if (r < 0) continue;
            dp[i][j] = (pref[r] - (l >= 1 ? pref[l - 1] : 0) + mod) % mod;
        }
    }
    int ans = 0;
    for (auto& x : dp.back())
        ans = (ans + x) % mod;
    return ans;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout << fixed << setprecision(6);

    int n, m; cin >> n >> m;
    vector <pair <int, int>> a(n);
    for (auto& x : a) {
        cin >> x.first >> x.second;
    }

    int ans = solve(n, m, a);
    
    vector <int> dp(m + 1), cnt(m + 1);

    for (int i = m; i >= 1; --i) {
        vector <pair <int, int>> b = a;
        for (auto& x : b) {
            x.first = (x.first + i - 1) / i, x.second /= i;
        }
        dp[i] = (dp[i] + solve(n, m / i, b)) % mod;
        set <int> de;
        for (int j = 1; j * j <= i; ++j) {
            if (i % j == 0)
                de.insert(j), de.insert(i / j);
        }
        de.erase(i);
        for (auto& x : de)
            dp[x] = (dp[x] - dp[i] + mod) % mod;
    }
    cout << dp[1] << '\n';
    return 0;
}
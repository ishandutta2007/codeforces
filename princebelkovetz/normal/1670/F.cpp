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

#define ll long long
#define ld long double
#define debug(x) cout << #x << " is " << x << '\n';
#pragma GCC optimize("O3")
using namespace std;
const int root = 212, mod = 1e9 + 7, B = 60, N = 1e3 + 15;

int C[N][N];
int calc(ll X, ll Z, int n) {
    vector <vector <vector <int>>> dp(B + 1,
        vector <vector <int>>(N,
            vector <int>(2)));
    dp[0][0][0] = 1;
    for (int i = 0; i < B; ++i) {
        for (int j = 0; j < N; ++j) {
            for (int add = ((Z >> i) & 1); (j + add) / 2 < N and add <= n; add += 2) {
                int have = j + add;
                for (int k = 0; k < 2; ++k) {
                    int ok = k;
                    if ((have & 1) and ((X >> i) & 1 ^ 1)) ok = 1;
                    if ((have & 1 ^ 1) and ((X >> i) & 1)) ok = 0;
                    dp[i + 1][have / 2][ok] += (ll)dp[i][j][k] * C[n][add] % mod;
                    dp[i + 1][have / 2][ok] %= mod;
                }
            }
        }
    }
    return dp[B][0][0];
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(6);

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (!j) C[i][j] = 1;
            else if (i) C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % mod;
        }
    }

    ll n, L, R, Z; cin >> n >> L >> R >> Z;
    int ans = calc(R, Z, n) - calc(L - 1, Z, n);
    cout << (ans + mod) % mod << '\n';

    return 0;
}
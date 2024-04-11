//#pragma GCC optimize("O3", "no-stack-protector")
//#pragma GCC target("sse4", "avx", "popcnt", "lzcnt", "sse3", "sse4.1", "sse4.2", "sse2", "tune=native")
//#pragma GCC optimize ("unroll-loops")

#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using old = long double;

const old PI = acos(-1.0);

const int N = 200100;
const int mod = 1e9 + 7;

ll dp[N][3];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << fixed << setprecision(20);
    int n;
    ll l, r;
    cin >> n >> l >> r;
    ll cnt[3];
    cnt[0] = r / 3 - (l - 1) / 3;
    cnt[1] = (r + 2) / 3 - (l + 1) / 3;
    cnt[2] = (r + 1) / 3 - l / 3;
    dp[0][0] = 1;
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j < 3; ++j) {
            for (int k = 0; k < 3; ++k) {
                (dp[i][(j + k) % 3] += dp[i - 1][j] * cnt[k]) %= mod;
            }
        }
    }
    cout << dp[n][0];
    return 0;
}
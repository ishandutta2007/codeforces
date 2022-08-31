#pragma optimization_level 3
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math,O3")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx")

#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;
using ll = long long;
using ld = long double;

const int mod = 1e9 + 7;
const double pi = acos(-1.0);

ll m;
int dp[61][8];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        cin >> m;
        dp[60][0] = 1;
        for (int bit = 59; bit >= 0; bit--) {
            for (int mask = 0; mask < 8; mask++) {
                dp[bit][mask] = 0;
                if ((m >> bit) & 1) {
                	int nm = (mask) >> 1;
                    int d1 = dp[bit + 1][nm] + dp[bit + 1][1 + nm];
                    int d2 = dp[bit + 1][2 + nm] + dp[bit + 1][3 + nm];
                    if (d1 >= mod) d1 -= mod;
                    if (d2 >= mod) d2 -= mod;
                    dp[bit][mask] = d1 + d2;
                    if (dp[bit][mask] >= mod) dp[bit][mask] -= mod;
                } else {
                    if (mask & 1) {
                        int nm = (1 + mask) >> 1;
	                    int d1 = dp[bit + 1][nm] + dp[bit + 1][1 + nm];
	                    int d2 = dp[bit + 1][2 + nm] + dp[bit + 1][3 + nm];
	                    if (d1 >= mod) d1 -= mod;
	                    if (d2 >= mod) d2 -= mod;
	                    dp[bit][mask] = d1 + d2;
	                    if (dp[bit][mask] >= mod) dp[bit][mask] -= mod;
                    } else {
	                    int nm = (mask) >> 1;
	                    int d1 = dp[bit + 1][nm] + dp[bit + 1][1 + nm];
	                    int d2 = dp[bit + 1][2 + nm] + dp[bit + 1][3 + nm];
	                    if (d1 >= mod) d1 -= mod;
	                    if (d2 >= mod) d2 -= mod;
	                    dp[bit][mask] = d1 + d2;
	                    if (dp[bit][mask] >= mod) dp[bit][mask] -= mod;
                    }
                }
            }
        }
        cout << dp[0][0] << '\n';
    }
    return 0;
}
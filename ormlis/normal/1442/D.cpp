#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")

#include <iostream>

typedef long long ll;

using namespace std;
const int maxN = 3000 + 5;

ll dp[maxN][maxN];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; ++i) {
        int t;
        cin >> t;
        ll s = 0;
        for (int j = 0; j <= t; ++j) {
            for (int e = k - j; e >= 0; --e) {
                dp[i][e + j] = max(dp[i][e + j], dp[i - 1][e] + s);
            }
            if (j != t) {
                int x;
                cin >> x;
                s += x;
            }
        }
    }
    cout << dp[n][k];
    return 0;
}
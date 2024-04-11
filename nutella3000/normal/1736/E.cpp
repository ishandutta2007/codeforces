#include<bits/stdc++.h>
using namespace std;
 
#define all(a) a.begin(), a.end()
using ll = long long;
using ull = unsigned long long;
using ld = long double;
 
template <typename T> bool chmin(T& a, T b) { if (a <= b) return false; a = b; return true; }
template <typename T> bool chmax(T& a, T b) { if (a >= b) return false; a = b; return true; }

const int inf = 1e9;
const ll mod = 998244353;

void run() {
    int n; cin >> n;
    vector<int> a(n);
    for (auto& i : a)
        cin >> i;

    vector dp(n+1, vector(n+1, vector<int>(2, -inf)));
    dp[0][0][0] = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j <= i+1; ++j) {
            auto& d = dp[i+1][j][0];
            auto& d2 = dp[i+1][j][1];

            for (int k = i; k >= 0; --k) {
                int sum = a[i] * (i - k + 1);
                int tmp = j - 2*(i-k);
                if (tmp >= 0) {
                    chmax(d, dp[k][tmp][0] + sum);
                    if (k < i) chmax(d2, dp[k][tmp][0] + sum);
                }
                if (k < i && tmp + 1 >= 0) {
                    chmax(d, dp[k+1][tmp + 1][1] - a[k] + sum);
                    chmax(d2, dp[k+1][tmp + 1][1] - a[k] + sum);
                }
                /*if (i == 4 && j == 5) {
                    cout << k << ' ' << d2 << '\n';
                }*/
            }


            for (int k = i-1; k >= 0; --k) {
                int tmp = j - (i-k);
                if (tmp < 0) break;
                chmax(d, dp[k+1][tmp][0] + (i-k) * a[k]);
            }
        }
    }
    // cout << dp[3][2][1] << '\n';
    int res = 0;
    for (int i = 0; i <= n; ++i) {
        chmax(res, dp[n][i][0]);
    }
    cout << res << '\n';
}

signed main() {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
    int t = 1;
    // cin >> t;
    while (t--) {
        run();
    }
}
#include <iostream>

using namespace std;

const int N = 1010;
const int mod = 1e9 + 7;

int dp[N][N], dp2[N][N];
string str;
int k;

int reduce(int x) {
    if (x == 1) return 0;
    return reduce(__builtin_popcount(x)) + 1;
}
int main() {

    cin >> str >> k;

    if (k == 0) {
        cout << 1 << endl;
        return 0;
    }

    const int n = str.length();
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j <= n; ++j) {
            int val = str[i] - '0';
            if (i == 0) {
                dp[i][j] = (j < val);
                dp2[i][j] = (j <= val);
            } else if (val == 0) {
                dp[i][j] = (dp[i-1][j] + (j > 0 ? dp[i-1][j-1] : 0)) % mod;
                dp2[i][j] = (dp2[i-1][j] + (j > 0 ? dp[i-1][j-1] : 0)) % mod;
            } else {
                dp[i][j] = (dp2[i-1][j] + (j > 0 ? dp[i-1][j-1] : 0)) % mod;
                dp2[i][j] = (dp2[i-1][j] + (j > 0 ? dp2[i-1][j-1] : 0)) % mod;
            }
        }
    }

    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        if (reduce(i) == k-1) {
            ans = (ans + dp2[n-1][i]) % mod;
        }
    }
    if (k == 1) ans -= 1;

    cout << ans << endl;

    return 0;
}
#include <iostream>
#include <map>
#include <vector>

using namespace std;

const long long mod = 998244353;
const int N = 2010;

long long dp[N][N];
int n, m, k;

int main() {

    cin >> n >> m >> k;

    dp[1][0] = m;
    for (int i = 2; i <= n; ++i) {
        for (int j = 0; j <= k; ++j) {
            dp[i][j] = dp[i-1][j];
            if (j) dp[i][j] = (dp[i][j] + dp[i-1][j-1] * (m-1)) % mod;
        }
    }

    cout << dp[n][k] << endl;

    return 0;
}
#include <algorithm>
#include <cassert>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

const long long LL_INF = (long long) 2e18 + 5;

int N;
long long A, B;
string road;

void solve_case() {
    cin >> N >> A >> B >> road;
    vector<vector<long long>> dp(N + 1, vector<long long>(2, LL_INF));
    dp[0][0] = B;

    for (int i = 0; i < N; i++)
        if (road[i] == '0') {
            dp[i + 1][0] = min(dp[i][0] + A, dp[i][1] + 2 * A) + B;
            dp[i + 1][1] = min(dp[i][0] + 2 * A, dp[i][1] + A) + 2 * B;
        } else {
            dp[i + 1][1] = dp[i][1] + A + 2 * B;
        }

    cout << dp[N][0] << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T-- > 0)
        solve_case();
}
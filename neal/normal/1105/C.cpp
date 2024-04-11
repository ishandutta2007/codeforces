#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

const int MOD = 1e9 + 7;

int N, L, R;

int count_mod3(int x) {
    if (x == 0)
        x = 3;

    return (R + 3 - x) / 3 - ((L - 1) + 3 - x) / 3;
}

int main() {
    cin >> N >> L >> R;
    vector<int> dp(3, 0);
    dp[0] = 1;

    for (int i = 0; i < N; i++) {
        vector<int> next_dp(3, 0);

        for (int a = 0; a < 3; a++)
            for (int b = 0; b < 3; b++) {
                int sum = (a + b) % 3;
                next_dp[sum] = (next_dp[sum] + (long long) dp[a] * count_mod3(b)) % MOD;
            }

        dp = next_dp;
    }

    cout << dp[0] << '\n';
}
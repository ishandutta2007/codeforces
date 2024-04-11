#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

const int MOD = 1e9 + 7;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string S;
    cin >> S;

    for (char c : S)
        if (c == 'w' || c == 'm') {
            cout << 0 << '\n';
            return 0;
        }

    int N = S.size();
    vector<int> dp(N + 1, 0);
    dp[0] = dp[1] = 1;

    for (int len = 2; len <= N; len++)
        if (S[len - 2] == S[len - 1] && (S[len - 1] == 'u' || S[len - 1] == 'n'))
            dp[len] = (dp[len - 1] + dp[len - 2]) % MOD;
        else
            dp[len] = dp[len - 1];

    cout << dp[N] << '\n';
}
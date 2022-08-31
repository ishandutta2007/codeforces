#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

const int INF = 1e9 + 5;

int N;
string A, B;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> A >> B;
    vector<int> dp(N + 1, INF);
    dp[0] = 0;

    for (int i = 0; i < N; i++) {
        dp[i + 1] = dp[i] + (A[i] != B[i] ? 1 : 0);

        if (i > 0 && A[i] != A[i - 1] && B[i] != B[i - 1] && A[i] != B[i])
            dp[i + 1] = min(dp[i + 1], dp[i - 1] + 1);
    }

    cout << dp[N] << '\n';
}
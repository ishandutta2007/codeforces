#include <algorithm>
#include <cassert>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

const long long LL_INF = (long long) 2e18 + 5;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, K;
    string routers;
    cin >> N >> K >> routers;
    vector<int> next_router(N + 1, N);

    for (int i = N - 1; i >= 0; i--)
        next_router[i] = routers[i] == '1' ? i : next_router[i + 1];

    vector<long long> dp(N + 1, LL_INF);
    dp[0] = 0;

    for (int i = 0; i < N; i++) {
        dp[i + 1] = dp[i] + (i + 1);
        int location = next_router[max(i - K, 0)];

        if (location < N)
            dp[i + 1] = min(dp[i + 1], dp[max(location - K, 0)] + (location + 1));
    }

    cout << dp[N] << '\n';
}
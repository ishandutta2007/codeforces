#include <bits/stdc++.h>
using namespace std;
using lint = long long;
lint MOD = 1e9 + 7;

lint memo[1005][1005][2];
lint dp(int open, int close, int can) {
    if (open == 0 && close == 0) {
        return 0;
    }
    if (open > close) {
        return 0;
    }
    if (open < 0 || close < 0) {
        return 0;
    }
    lint& res = memo[open][close][can];
    if (res != -1) {
        return res;
    }
    res = 0;
    if (can) {
        res = max(res, (open > 0) + dp(open - 1, close, 0) + dp(open, close - 1, 1));
        res = max(res, (close > 0 && open <= close - 1) + dp(open - 1, close, 1) + dp(open, close - 1, 0));
        res = max(res, dp(open - 1, close, 1) + dp(open, close - 1, 1));
    } else {
        res = max(res, dp(open - 1, close, 1) + dp(open, close - 1, 1));
    }
    res %= MOD;
    return res;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    memset(memo, -1, sizeof(memo));

    int N;
    cin >> N;
    cout << dp(N, N, 1) << "\n";
    return 0;
}
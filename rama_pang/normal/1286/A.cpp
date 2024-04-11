#include <bits/stdc++.h>
using namespace std;

int N;
int P[105];
int memo[105][105][105][2];

int dp(int n, int even, int odd, int lastIsOdd) {
    if (even < 0 || odd < 0) {
        return (int) 1e9;
    }
    if (n == N) {
        return 0;
    }
    int &res = memo[n][even][odd][lastIsOdd];
    if (res != -1) {
        return res;
    }
    res = 1e9;

    if (P[n] == 0 || P[n] % 2 != 1) res = min(res, (lastIsOdd? 1 : 0) + dp(n + 1, even - 1, odd, false));
    if (P[n] == 0 || P[n] % 2 != 0) res = min(res, (lastIsOdd? 0 : 1) + dp(n + 1, even, odd - 1, true));
    
    return res;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    memset(memo, -1, sizeof(memo));

    cin >> N;
    int even = N / 2;
    int odd = N - even;

    for (int i = 0; i < N; i++) {
        cin >> P[i];
    }

    cout << min(dp(0, even, odd, 0), dp(0, even, odd, 1)) << "\n";
    return 0;
}
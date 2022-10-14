#include <bits/stdc++.h>
using namespace std;
const int MOD = 998244353;

int binpow(int n, int x) {
    if (x == 0) return 1;
    int res = binpow(n, x / 2);
    res = (1ll * res * res) % MOD;
    if (x & 1) res = (1ll * res * n) % MOD;
    return res;
}

int DIV(int a, int b) {
    return (1ll * a * binpow(b, MOD - 2)) % MOD;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int N;
    cin >> N;
    vector<int> P(N + 1);
    for (int i = 1; i <= N; i++) {
        cin >> P[i];
    }

    vector<int> DP(N + 1, 0); // expected number of days to pass i-th mirror's test
    DP[0] = 0;
    for (int i = 1; i <= N; i++) {
        DP[i] = (1ll * (DP[i - 1] + 1) * DIV(100, P[i])) % MOD; // For each P, we need P[i] / 100 times meeting it to progress.
        if (DP[i] < 0) DP[i] += MOD;
    }

    cout << DP[N] << "\n";
    return 0;
}
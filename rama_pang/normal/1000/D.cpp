#include <bits/stdc++.h>
using namespace std;
using lint = long long;
const lint MOD = 998244353;

int N;
vector<lint> A;
lint cc[1005][1005] = {};
lint memo[1005] = {};
lint C(lint n, lint r) {
    if (r == n || r == 0) {
        return 1;
    } else if (n < 0) {
        return 0;
    } else if (cc[n][r] != -1) {
        return cc[n][r];
    } else {
        return cc[n][r] = (C(n - 1, r - 1) + C(n - 1, r)) % MOD;
    }
}

lint dp(int n) {
    if (n == A.size()) {
        return 1;
    }
    if (memo[n] != -1) return memo[n];
    lint res = 0;
    if (A[n] > 0) for (int j = n + A[n] + 1; j <= N; j++) {
        res += (C(j - n - 1, A[n]) * dp(j)) % MOD;
        res %= MOD;
    }
    res %= MOD;
    return memo[n] = res;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    
    memset(cc, -1, sizeof(cc));
    memset(memo, -1, sizeof(memo));
    cin >> N;
    for (int i = 0; i < N; i++) {
        int a; cin >> a;
        A.emplace_back(a);
    }
    lint ans = 0;
    for (int i = 0; i < N; i++) {
        ans += dp(i);
        ans %= MOD;
    }

    cout << ans << "\n";
}
#include <bits/stdc++.h>
// #define LOCAL
using namespace std;
const int MOD = 1e9 + 7;

int N;
vector<int> A;
int fact[400005];
int inv[400005];
int cnt[300005];

int pw(int n, int x) {
    if (x == 0) {
        return 1;
    }
    if (x & 1) {
        return (1ll * n * pw(n, x - 1)) % MOD;
    }
    int res = pw(n, x / 2);
    return (1ll * res * res) % MOD;
}

int C(int n, int r) {
    if (n - r < 0) return 0;
    return (((1ll * fact[n] * inv[r]) % MOD) * inv[n - r]) % MOD;
}

int memo[400005];
int vis[400005];

int dp(int n, int g) {
    if (g > 300000) {
        return 0;
    }
    if (vis[g] == 1) {
        return memo[g];
    }
    vis[g] = 1;
    int res = 0;
    int div = cnt[g];
    res = C(div, n);
    for (int i = g + g; i <= 300000; i += g) {
        res -= dp(n, i);
        res %= MOD;
    }
    return memo[g] = (res + MOD) % MOD;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    clock_t z = clock();
    fact[0] = 1;
    for (int i = 1; i <= 400000; i++) {
        fact[i] = (1ll * fact[i - 1] * i) % MOD;
    }
    inv[400000] = pw(fact[400000], MOD - 2);
    for (int i = 400000 - 1; i >= 0; i--) {
        inv[i] = (1ll * inv[i + 1] * (i + 1)) % MOD;
    }

    cin >> N;
    A.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        for (int j = 1; j * j <= A[i]; j++) {
            if (A[i] % j == 0) {
                cnt[j]++;
                if (j * j != A[i]) {
                    cnt[A[i] / j]++;
                }
            }
        }

    }

    int ans = -1;
    for (int i = 1; i <= 7; i++) {
        memset(memo, 0, sizeof(memo));
        memset(vis, 0, sizeof(vis));
        if (dp(i, 1) != 0) {
            ans = i;
            break;
        }
    }
    cout << ans << "\n";

    #ifdef LOCAL
    cout << fixed << setprecision(5) << (((double)clock() - z) / CLOCKS_PER_SEC) << "\n";
    #endif

    return 0;
}
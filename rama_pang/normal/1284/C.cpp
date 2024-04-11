#include <bits/stdc++.h>
using namespace std;
using lint = long long;

template<typename T, typename U>
T power(T n, U x) {
    assert(x >= 0);
    T res = 1;
    for (; x; x /= 2, n *= n) if (x & 1) res *= n;
    return res;
}

lint MOD;
lint fact[250001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    lint N;
    cin >> N >> MOD;
    fact[0] = 1;
    for (int i = 1; i <= 250000; i++) {
        fact[i] = (1ll * i * fact[i - 1]) % MOD;
    }

    lint ans = 0;
    for (int i = 1; i <= N; i++) {
        ans += fact[i] * (N - i + 1) % MOD * i % MOD * fact[N - i] % MOD;
        ans %= MOD;
        // cout << i << " " << fact[i] * (N - i + 1) % MOD * i % MOD << "\n";
    }
    cout << ans << "\n";
}
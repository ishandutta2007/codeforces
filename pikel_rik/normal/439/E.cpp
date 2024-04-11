#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;
using ll = long long;
using ld = long double;

const int mod = 1e9 + 7;
const int inf = INT_MAX;
const int N = 1e5;

ll modexp(ll x, ll n) {
    ll ans = 1;
    while (n) {
        if (n & 1) ans = ans * x % mod;
        x = x * x % mod;
        n /= 2;
    }
    return ans;
}

ll modinv(ll x) {
    return modexp(x, mod - 2);
}

ll fact[N + 1], inv[N + 1];
ll choose(int n, int k) {
    return fact[n] * inv[n - k] % mod * inv[k] % mod;
}

vector<int> factors[N + 1];
void comp() {
    fact[0] = inv[0] = 1;
    for (int i = 1; i <= N; i++) {
        fact[i] = i * fact[i - 1] % mod;
        inv[i] = modinv(i) * inv[i - 1] % mod;
    }
    for (int i = 2; i <= N; i++) {
        if (factors[i].empty()) {
            for (int j = i; j <= N; j += i) {
                factors[j].push_back(i);
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    comp();

    int q;
    cin >> q;

    while (q--) {
        int n, f;
        cin >> n >> f;

        int ans = 0;
        for (int mask = 0; mask < (1 << factors[n].size()); mask++) {
            int prod = 1;
            for (int i = 0; i < factors[n].size(); i++) {
                if (mask & (1 << i)) {
                    prod *= factors[n][i];
                }
            }

            if ((ll)f * prod <= n) {
                int dist = n / prod - f;
                if (__builtin_popcount(mask) & 1) {
                    ans = (ans + mod - choose(f + dist - 1, f - 1)) % mod;
                } else ans = (ans + choose(f + dist - 1, f - 1)) % mod;
            }
        }
        cout << ans << '\n';
    }
    return 0;
}
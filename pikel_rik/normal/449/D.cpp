#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;
using ll = long long;
using ld = long double;

const int mod = 1e9 + 7;
const int inf = INT_MAX;
const int N = (1 << 20);

int n, a[N], power[N], f[N], f1[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    power[0] = 1;
    for (int i = 1; i < N; i++) {
        power[i] = 2ll * power[i - 1] % mod;
    }

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        f[a[i]]++;
    }

    for (int k = 1; k <= 20; k++) {
        for (int x = 0; x < N; x++) {
            f1[x] = f[x];
            if (!(x & (1 << (k - 1)))) {
                f1[x] += f[x | (1 << (k - 1))];
            }
        }
        memcpy(f, f1, sizeof(f));
    }

    int ans = 0;
    for (int x = 0; x < N; x++) {
        int g = __builtin_popcount(x);
        if (g & 1) {
            ans = (ans + mod - power[f[x]]) % mod;
        } else ans = (ans + power[f[x]]) % mod;
    }
    cout << ans << '\n';
    return 0;
}
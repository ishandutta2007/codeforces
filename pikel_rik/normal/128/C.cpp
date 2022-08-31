#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define all(x) (x).begin(), (x).end()

using namespace __gnu_pbds;
using namespace std;

using ull = unsigned long long;
using ll = long long;
using ld = long double;
template <typename T> using ordered_set = tree<T, null_type, less<>, rb_tree_tag, tree_order_statistics_node_update>;

const int mod = 1e9 + 7;
const int inf = INT_MAX;
const int N = 1000 + 5;

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

ll fact[4*N];

ll choose(ll n, ll k) {
    ll num = fact[n];
    ll dem = fact[n - k] * fact[k] % mod;
    return num * modinv(dem) % mod;
}

int n, m, k;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    fact[0] = 1;
    for (int i = 1; i < 4*N; i++) fact[i] = i * fact[i - 1] % mod;

    cin >> n >> m >> k;

    ll ans = 0;
    for (int i = 1; i <= n - 2*k; i++) {
        for (int j = 1; j <= m - 2*k; j++) {
            int extra1 = n - 2*k - i, extra2 = m - 2*k - j;
            ans = (ans + choose(2*k + extra1 - 1, 2*k - 1) * choose(2*k + extra2 - 1, 2*k - 1) % mod) % mod;
        }
    }

    cout << ans << "\n";
    return 0;
}
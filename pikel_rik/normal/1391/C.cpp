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
const int N = 1e6 + 5;

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

ll fact[N];

ll choose(ll n, ll k) {
    ll num = fact[n];
    ll dem = fact[k] * fact[n - k] % mod;
    return num * modinv(dem) % mod;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    fact[0] = 1;
    for (int i = 1; i < N; i++) fact[i] = i * fact[i - 1] % mod;

    int n;
    cin >> n;

    ll ans = fact[n];
    for (int i = 1; i <= n; i++) {
        ans = ((ans - choose(n - 1, i - 1)) % mod + mod) % mod;
    }

    cout << ans << "\n";
    return 0;
}
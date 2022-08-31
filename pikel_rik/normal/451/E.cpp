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

ll choose(ll n, ll k) {
    if (k > n - k)
        k = n - k;

    n %= mod;

    ll num = 1, dem = 1;
    for (int i = n; i > n - k; i--) {
        num = num * i % mod;
    }
    for (int i = 1; i <= k; i++) {
        dem = dem * i % mod;
    }

    return num * modinv(dem) % mod;
}

int n;
ll s, f[25];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> n >> s;
    for (int i = 0; i < n; i++) cin >> f[i];

    ll ans = choose(n + s - 1, n - 1);

    for (int mask = 1; mask < (1 << n); mask++) {
        ll sum = 0;
        int c = 0;

        for (int i = 0; i < n; i++) {
            if (mask & (1 << i)) {
                sum += f[i] + 1;
                c++;
            }
        }
        if (sum <= s) {
            if (c & 1)
                ans -= choose(n + s - 1 - sum, n - 1);
            else ans += choose(n + s - 1 - sum, n - 1);
            ans = (ans % mod + mod) % mod;
        }
    }

    cout << ans << "\n";
    return 0;
}
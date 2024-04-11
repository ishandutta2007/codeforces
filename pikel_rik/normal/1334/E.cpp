#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define all(x) (x).begin(), (x).end()

using namespace __gnu_pbds;
using namespace std;

using ull = unsigned long long;
using ll = long long;
using ld = long double;
template <typename T> using ordered_set = tree<T, null_type, less<>, rb_tree_tag, tree_order_statistics_node_update>;

const int mod = 998244353;
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

ll D, fact[30000], inv[30000];
vector<ll> pri;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    fact[0] = 1; inv[0] = 1;
    for (int i = 1; i < 30000; i++) {
        fact[i] = i * fact[i - 1] % mod;
        inv[i] = modinv(fact[i]);
    }

    cin >> D; //13

    ll temp = D;
    if (temp % 2 == 0) {
        pri.push_back(2);
        while (temp % 2 == 0) {
            temp /= 2;
        }
    }

    for (ll i = 3; i * i <= temp; i += 2) {
        if (temp % i == 0) {
            pri.push_back(i);
            while (temp % i == 0) {
                temp /= i;
            }
        }
    }
    if (temp > 1)
        pri.push_back(temp);

    int q;
    cin >> q;

    while (q--) {
        ll u, v;
        cin >> u >> v;

        if (u > v)
            swap(u, v);

        ll g = __gcd(u, v);

        u /= g;
        v /= g;

        ll ans = 1;
        int c = 0;

        for (ll i : pri) {
            int cn = 0;
            while (u % i == 0) {
                u /= i;
                cn++;
                c++;
            }
            ans = ans * inv[cn] % mod;
        }

        ans = fact[c] * ans % mod;

        c = 0;
        for (ll i : pri) {
            int cn = 0;
            while (v % i == 0) {
                v /= i;
                cn++;
                c++;
            }
            ans = ans * inv[cn] % mod;
        }

        ans = fact[c] * ans % mod;
        cout << ans << "\n";
    }
    return 0;
}
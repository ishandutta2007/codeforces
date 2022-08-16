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

ll tri(ll n) {
    return max(0ll, (n * n + n) / 2);
}

int m, d, w;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        cin >> m >> d >> w;
        w /= __gcd(w, d - 1);

        //(x * d + y) mod w = (y * d + x) mod w => ((x - y) * (d - 1)) mod w = 0
        //(d - 1) / w + (d - 2) / w + ... + (d - d) / w;
        d = min(d, m) - 1;
        cout << (d % w + 1) * tri(d / w) + (w - 1 - d % w) * tri(d / w - 1) << "\n";
    }
    return 0;
}
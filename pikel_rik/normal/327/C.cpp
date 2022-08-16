#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define all(x) (x).begin(), (x).end()

using namespace __gnu_pbds;
using namespace std;

using ull = unsigned long long;
using ll = long long;
template <typename T> using ordered_set = tree<T, null_type, less<>, rb_tree_tag, tree_order_statistics_node_update>;

const int mod = 1e9 + 7;
const int inf = 2e9 + 5;

ll modexp(ll x, ll n) {
    if (n == 0)
        return 1;
    ll ans = modexp(x * x % mod, n / 2);
    if (n % 2) return x * ans % mod;
    return ans;
}

ll modinv(ll x) {
    return modexp(x, mod - 2);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    string s;
    cin >> s;

    int n = s.length();

    int k;
    cin >> k;

    ll ans = 0, temp = modinv(modexp(2, n) - 1) * (modexp(2, n * (ll)k) - 1 + mod) % mod;

    for (int i = 0; i < n; i++) {
        if (s[i] == '0' or s[i] == '5')
            ans = (ans + modexp(2, i) * temp % mod) % mod;
    }

    cout << ans << "\n";
    return 0;
}
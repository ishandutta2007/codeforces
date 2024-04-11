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
const int N = 1e3 + 5;

int n, m, a[N], power[N], fact[N];

ll modexp(ll x, ll n) {
    ll ans = 1;
    while (n > 0) {
        if (n % 2 != 0) ans = ans * x % mod;
        x = x * x % mod;
        n /= 2;
    }
    return ans;
}

ll modinv(ll x) {
    return modexp(x, mod - 2);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    power[0] = 1;
    for (int i = 1; i <= 1000; i++)
        power[i] = 2 * power[i-1] % mod;

    fact[0] = 1;
    for (int i = 1; i <= 1000; i++)
        fact[i] = fact[i-1] * (ll)i % mod;

    cin >> n >> m;
    for (int i = 0; i < m; i++) cin >> a[i];

    sort(a, a + m);
    ll ans = 1;

    vector<int> num = {a[0] - 1, n - a[m-1]};

    for (int i = 1; i < m; i++) {
        if (a[i] != a[i-1] + 1) {
            ans = ans * power[a[i] - a[i - 1] - 2] % mod;
            num.push_back(a[i] - a[i - 1] - 1);
        }
    }

    ll total = fact[accumulate(all(num), 0)];
    for (int i : num) {
        total = total * modinv(fact[i]) % mod;
    }

    cout << ans * total % mod << "\n";
    return 0;
}
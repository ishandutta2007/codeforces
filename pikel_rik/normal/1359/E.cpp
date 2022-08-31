#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define all(x) (x).begin(), (x).end()

using namespace __gnu_pbds;
using namespace std;

using ull = unsigned long long;
using ll = long long;
template <typename T> using ordered_set = tree<T, null_type, less<>, rb_tree_tag, tree_order_statistics_node_update>;

const int mod = 998244353;
const int inf = 2e9 + 5;
const int N = 5e5 + 5;

int n, k;
ll fact[N];

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

ll choose(int n, int k) {
    if (n < k)
        return 0;

    ll num1 = fact[n];
    ll num2 = fact[n - k] * fact[k] % mod;
    num2 = modinv(num2);

    return num1 * num2 % mod;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    fact[0] = 1;

    for (int i = 1; i < N; i++)
        fact[i] = i * fact[i-1] % mod;

    cin >> n >> k;

    ll ans = choose(n - 1, k - 1);

    for (int i = 2; i <= n; i++)
        ans = (ans + choose(n / i - 1, k - 1)) % mod;

    cout << ans << "\n";
    return 0;
}
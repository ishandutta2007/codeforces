#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define all(x) (x).begin(), (x).end()

using namespace __gnu_pbds;
using namespace std;

using ull = unsigned long long;
using ll = long long;
template <typename T> using ordered_set = tree<T, null_type, less<>, rb_tree_tag, tree_order_statistics_node_update>;

const int mod = 1e9 + 9;
const int inf = 2e9 + 5;

ll modexp(ll x, ll n) {
    if (n == 0)
        return 1;
    ll ans = modexp(x * x % mod, n / 2);
    if (n % 2) return x * ans % mod;
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    ll n, m, k;
    cin >> n >> m >> k;

    ll gap = n - m;

    if (m - gap * (k - 1) <= 0) {
        cout << m << "\n";
        return 0;
    }

    m -= gap * (k - 1);

    ll score = (modexp(2, m / k) - 1 + mod) * 2 % mod * k % mod;
    m %= k;

    score = (score + m) % mod;
    score = (score + gap * (k - 1)) % mod;

    cout << score << "\n";
    return 0;
}
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
const int N = 2e5 + 5;

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

ll choose(int n, int k) {
    if (k > n)
        return 0;

    ll num1 = fact[n];
    ll num2 = fact[n - k] * fact[k] % mod;

    return num1 * modinv(num2) % mod;
}

int n, m, g;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    fact[0] = 1;
    for (int i = 1; i < N; i++)
        fact[i] = i * fact[i - 1] % mod;

    cin >> n >> m >> g;
    //01 = 10 = 11 = 0, 00 = 1

    string s;
    s += (g == 0 ? "0" : "1");

    ll ans = 0;
    for (int i = 1; i < n + m; i++) {
        if (s.back() == '0') {
            ans = (ans + choose(n + m - i, m - 1)) % mod; //1001, 1010, 1100,
            s += "1";
        }
        else {
            s.pop_back();
            s += "00";
        }
    }

    int c = count(all(s), '1');
    if (c == m)
        ans = (ans + 1) % mod;

    cout << ans << "\n";
    return 0;
}
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define all(x) (x).begin(), (x).end()

using namespace __gnu_pbds;
using namespace std;

using ull = unsigned long long;
using ll = long long;
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

ll fact[101];

ll choose(int n, int k) {
    ll num1 = fact[n];
    ll num2 = fact[k] * fact[n - k] % mod;
    num2 = modinv(num2);

    return num1 * num2 % mod;
}

int n;
int a[10];

ll dp[10][101];

ll recurse(int num, int sum) {
    if (dp[num][sum] != -1)
        return dp[num][sum];

    if (num == 9) {
        return dp[num][sum] = 1;
    }

    ll ans = 0;
    int pref = accumulate(a + num, a + 10, 0);

    for (int i = 0; i <= sum; i++) {
        ll val = choose(pref + sum, a[num] + i);
        if (num == 0 and a[num] + i)
            val = ((val - choose(pref + sum - 1, a[num] + i - 1)) % mod + mod) % mod;
        ll temp = val * recurse(num + 1, sum - i) % mod;
        ans = (ans + temp) % mod;
    }

    return dp[num][sum] = ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    fact[0] = 1;
    for (int i = 1; i <= 100; i++)
        fact[i] = fact[i - 1] * i % mod;

    cin >> n;
    for (int &i : a) cin >> i;

    int sum = accumulate(a, a + 10, 0);
    if (sum > n) {
        cout << "0\n";
        return 0;
    }

    memset(dp, -1, sizeof(dp));
    ll ans = 0;

    for (int i = 0; i <= n - sum; i++) {
        ans = (ans + recurse(0, i)) % mod;
    }

    cout << ans - (sum == 0) << "\n";
    return 0;
}
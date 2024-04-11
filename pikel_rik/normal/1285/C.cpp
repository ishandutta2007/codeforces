#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;
using ll = long long;
using ld = long double;

const int mod = 1e9 + 7;
const int inf = INT_MAX;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n;
    cin >> n;

    ll ans = n;
    for (int i = 1; (ll)i * i <= n; i++) {
        if (n % i == 0 and __gcd((ll)i, n / i) == 1) {
            ans = min(ans, max((ll)i, n / i));
        }
    }
    cout << ans << ' ' << n / ans << '\n';
    return 0;
}
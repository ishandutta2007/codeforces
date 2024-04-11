#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cout << setprecision(20) << fixed;
    ll n, k;
    cin >> n >> k;
    ll ans = LLONG_MAX;
    for (int i = 1; i <= n; ++i) {
        if (n % i) {
            continue;
        }
        ll x = i * k;
        x += n / i;
        if ((x / k) * (x % k) == n) {
            ans = min(ans, x);
        }
    }
    cout << ans;
}
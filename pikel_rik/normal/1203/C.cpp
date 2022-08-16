#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;
using ll = long long;
using ld = long double;

const int mod = 1e9 + 7;
const double pi = acos(-1.0);
const int N = 4e5 + 5;

int n;
ll a[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];

    ll g = 0;
    for (int i = 0; i < n; i++) {
        g = __gcd(g, a[i]);
    }

    int ans = 0;
    for (int i = 1; (ll)i * i <= g; i++) {
        if (g % i == 0) {
            ans++;
            if (i != g / i) {
                ans++;
            }
        }
    }
    cout << ans << '\n';
    return 0;
}
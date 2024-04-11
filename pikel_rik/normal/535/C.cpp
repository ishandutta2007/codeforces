#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()

using namespace std;
using ull = unsigned long long;
using ll = long long;

const int mod = 1e9 + 7;
const int inf = 2e9 + 5;
const int N = 1e5 + 1;

ll f(ll a, ll b, ll l, ll r) {
    return (r - l + 1) * (a - b) + ((r * (r + 1)) / 2 - (l * (l - 1)) / 2) * b;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    ll a, b, n;
    cin >> a >> b >> n;

    while (n--) {
        ll l, t, m;
        cin >> l >> t >> m;

        if (a + (l - 1) * b > t) {
            cout << "-1\n";
            continue;
        }

        ll lo = l, hi = 1e6;

        while (lo < hi) {
            ll mid = lo + (hi - lo + 1) / 2;

            if (f(a, b, l, mid) <= t * min(m, mid - l + 1) and a + (mid - 1) * b <= t)
                lo = mid;
            else hi = mid - 1;
        }

        cout << lo << "\n";
    }
    return 0;
}
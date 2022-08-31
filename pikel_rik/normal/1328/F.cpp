#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;
using ll = long long;
using ld = long double;

const int mod = 1e9 + 7;
const int inf = INT_MAX;
const int N = 2e5 + 5;

int n, k, a[N];
ll pref[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> k;
    for (int i = 1; i <= n; i++) cin >> a[i];

    sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; i++) pref[i] = pref[i - 1] + a[i];

    ll ans = LLONG_MAX;
    for (int i = 1; i <= n; i++) {
        if (a[i] == a[i - 1]) continue;

        int idx1 = lower_bound(a + 1, a + n + 1, a[i]) - a - 1, idx2 = upper_bound(a + 1, a + n + 1, a[i]) - a - 1;

        int c = idx2 - idx1;
        if (c >= k) {
            cout << "0\n";
            return 0;
        }

        ll cost1 = idx1 * (ll)(a[i] - 1) - pref[idx1], cost2 = pref[n] - pref[idx2] - (n - idx2) * (ll)(a[i] + 1);

        if (c + idx1 >= k)
            ans = min(ans, cost1 + k - c);
        if (c + n - idx2 >= k)
            ans = min(ans, cost2 + k - c);

        if (c + idx1 < k and c + n - idx2 < k) {
            ans = min(ans, cost1 + cost2 + k - c);
        }
    }

    cout << ans << "\n";
    return 0;
}
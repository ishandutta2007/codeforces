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

ll n, k, l1, r1, l2, r2, len, inlen, cost;
ll ans;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        cin >> n >> k >> l1 >> r1 >> l2 >> r2;

        cost = max(l1, l2) - min(r1, r2);
        len = max(r1, r2) - min(l1, l2);
        inlen = max(0ll, -cost);

        if (n * inlen >= k) {
            cout << "0\n";
            continue;
        }

        ans = LLONG_MAX;
        for (int i = 1; i <= n; i++) {
            if (i * len + (n - i) * inlen >= k) {
                ans = min(ans, i * (cost + len) - (i * len + (n - i) * inlen - k));
                break;
            }
            else {
                ans = min(ans, i * (cost + len) + 2 * (k - (i * len + (n - i) * inlen)));
            }
        }

        cout << ans << "\n";
    }
    return 0;
}
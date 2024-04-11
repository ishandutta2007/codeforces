#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define all(x) (x).begin(), (x).end()

using namespace __gnu_pbds;
using namespace std;

using ull = unsigned long long;
using ll = long long;
template <typename T> using ordered_set = tree<T, null_type, less<>, rb_tree_tag, tree_order_statistics_node_update>;

const int mod = 1e9 + 7;
const int inf = 2e9 + 5;
const int N = 1e6 + 5;

int n, l, r, x, a[N], pref[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> n >> l >> r >> x;
    for (int i = 0; i < n; i++) cin >> a[i];

    int ans = 0;
    for (int i = 1; i < (1 << n); i++) {
        int sum = 0, mn = INT_MAX, mx = INT_MIN;

        for (int j = 0; j < n; j++) {
            if (i & (1 << j)) {
                sum += a[j];
                mn = min(mn, a[j]);
                mx = max(mx, a[j]);
            }
        }

        if (sum >= l and sum <= r and mx - mn >= x)
            ans += 1;
    }

    cout << ans << "\n";
    return 0;
}
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
const int N = 1e5 + 5;

int n, h, m, k, a[N], b[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> h >> m >> k;
    for (int i = 0, hi; i < n; i++) {
        cin >> hi >> b[i];
        b[i] %= m / 2;
        a[i] = b[i];
    }

    sort(a, a + n);
    int best = -1, best_val = INT_MAX;

    for (int i = 0; i < n; i++) {
        int t = a[i], c = 0;

        if (t < k) {
            c = (lower_bound(a, a + n, t) - a) + n - (upper_bound(a, a + n, m / 2 - (k - t)) - a);
        }
        else {
            c = (lower_bound(a, a + n, t) - a) - (upper_bound(a, a + n, t - k) - a);
        }

        if (c < best_val) {
            best_val = c;
            best = t;
        }

        t = (t + k) % (m / 2);

        if (t < k) {
            c = (lower_bound(a, a + n, t) - a) + n - (upper_bound(a, a + n, m / 2 - (k - t)) - a);
        }
        else {
            c = (lower_bound(a, a + n, t) - a) - (upper_bound(a, a + n, t - k) - a);
        }

        if (c < best_val) {
            best_val = c;
            best = t;
        }
    }

    cout << best_val << " " << best << "\n";
    vector<int> ans;
    for (int i = 0; i < n; i++) {
        if (b[i] > best - k and b[i] < best)
            ans.push_back(i);
        else if (best < k and b[i] > m / 2 - (k - best))
            ans.push_back(i);
    }

    for (int i : ans) cout << i + 1 << " "; cout << "\n";
    return 0;
}
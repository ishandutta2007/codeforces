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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n, k;
        cin >> n >> k;

        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];

        map<int, int, greater<>> m;
        for (int i = 0; i < n; i++) {
            if (a[i] % k)
                m[a[i] % k]++;
        }

        int best = 0, best_val = 0;

        for (auto &p : m) {
            int num = p.first, c = p.second;
            if (best_val < c) {
                best_val = c;
                best = num;
            }
            else if (best_val == c) {
                best = num;
            }
        }

        ll ans = max(0ll, best_val * (ll)k - best + 1);
        if (m.empty())
            ans = 0;
        cout << ans << "\n";
    }
    return 0;
}
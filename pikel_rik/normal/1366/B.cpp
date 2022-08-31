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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n, x, m;
        cin >> n >> x >> m;

        int cur_l = x, cur_r = x;

        while (m--) {
            int l, r;
            cin >> l >> r;

            if (cur_l != -1 and (((cur_l <= l and l <= cur_r) or (cur_l <= r and r <= cur_r)) or (l <= cur_l and cur_l <= r) or (l <= cur_r and cur_r <= r))) {
                cur_l = min(cur_l, l);
                cur_r = max(cur_r, r);
            }
        }

        cout << cur_r - cur_l + 1 << "\n";
    }
    return 0;
}
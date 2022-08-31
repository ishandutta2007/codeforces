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
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        ll l, r, m;
        cin >> l >> r >> m;

        int a = -1, b = -1, c = -1;
        for (int i = l; i <= r; i++) {
            ll lo = 1, hi = (ll)1e10;

            while (lo < hi) {
                ll mid = lo + (hi - lo + 1) / 2;
                if (m - mid * i >= 0)
                    lo = mid;
                else hi = mid - 1;
            }

            ll val1 = m - lo * i, val2 = val1 - i;

            if (r - l >= abs(val1)) {
                a = i;
                b = l + abs(val1);
                c = l;
                if (val1 < 0)
                    swap(b, c);
            }
            else if (r - l >= abs(val2)) {
                a = i;
                b = l + abs(val2);
                c = l;
                if (val2 < 0)
                    swap(b, c);
            }
            if (a != -1)
                break;
        }

        cout << a << " " << b << " " << c << "\n";
    }
    return 0;
}
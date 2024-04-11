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
        int h, c, temp;
        cin >> h >> c >> temp;

        long double f3 = (h + c) / (long double)2;
        if (temp <= f3) {
            cout << 2 << "\n";
            continue;
        }

        ll lo = 1, hi = 1e12;

        while (lo < hi) {
            ll mid = lo + (hi - lo) / 2;
//            cout << mid << " " << (mid * h + (mid - 1) * c) / (double)(2 * mid - 1) << "\n";

            if (mid * h + (mid - 1) * c <= temp * (2 * mid - 1))
                hi = mid;
            else lo = mid + 1;
        }

        long double f1 = (lo * h + (lo - 1) * c) / (long double)(2 * lo - 1);
        lo -= 1;

        long double f2 = (lo * h + (lo - 1) * c) / (long double)(2 * lo - 1);

        f1 = abs(f1 - temp);
        f2 = abs(f2 - temp);
        f3 = abs(f3 - temp);

        vector<int> ans;
        long double m = min({f1, f2, f3});

        if (m == f1) ans.push_back(2 * (lo + 1) - 1);
        if (m == f2) ans.push_back(2 * lo - 1);
        if (m == f3) ans.push_back(2);

        cout << *min_element(all(ans)) << "\n";
    }
    return 0;
}
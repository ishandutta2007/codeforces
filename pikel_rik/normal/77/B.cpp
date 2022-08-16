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
        int a, b;
        cin >> a >> b;
        ld p;

        if (b == 0) {
            cout << "1.0\n";
            continue;
        }

        if (a == 0) {
            cout << "0.5\n";
            continue;
        }

        if (a <= 4 * b) {
            p = 2.0 * b * (ld)a;
            p = (b * (ld)a + a * (ld)a / 8.0) / p;
        }
        else {
            p = (a - 4 * b) * (ld)2 * b + 6 * (ld)b * b ;
            p /= 2.0 * a * (ld)b;
        }

        cout << fixed << setprecision(12);
        cout << p << "\n";
    }
    return 0;
}
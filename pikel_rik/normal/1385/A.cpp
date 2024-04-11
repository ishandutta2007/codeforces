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
        int x, y, z;
        cin >> x >> y >> z;

        if (x != y and y != z and x != z) {
            cout << "NO\n";
            continue;
        }

        if (x == y and y == z) {
            cout << "YES\n";
            cout << x << " " << x << " " << x << "\n";
            continue;
        }

        if ((x == y and x < z) or (x == z and x < y) or (y == z and y < x)) {
            cout << "NO\n";
            continue;
        }

        if (x == y) {
            cout << "YES\n";
            cout << x << " " << z << " " << z << "\n";
        }
        else if (y == z) {
            cout << "YES\n";
            cout << x << " " << x << " " << z << "\n";
        }
        else {
            cout << "YES\n";
            cout << y << " " << x << " " << y << "\n";
        }
    }
    return 0;
}
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
        int n;
        cin >> n;

        if (n < 31) {
            cout << "NO\n";
            continue;
        }

        int a = 6, b = 10, c = 14, d = n - 30;

        if (d == a or d == b or d == c) {
            d--;
            c++;
        }

        cout << "YES\n";
        cout << a << " " << b << " " << c << " " << d << "\n";
    }
    return 0;
}
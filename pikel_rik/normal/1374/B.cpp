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
        int n;
        cin >> n;

        int c1 = 0, c2 = 0;
        while (n % 3 == 0) {
            n /= 3;
            c1++;
        }

        while (n % 2 == 0) {
            n /= 2;
            c2++;
        }

        if (n > 1 or c1 < c2) {
            cout << "-1\n";
            continue;
        }

        cout << c1 - c2 + c1 << "\n";
    }
    return 0;
}
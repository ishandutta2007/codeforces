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
        int a, b;
        cin >> a >> b;

        if (a > b) swap(a, b);
        if (2 * a <= b) {
            cout << a << "\n";
            continue;
        }

        int diff = b - a;
        b -= 2 * diff;
        a -= diff;

        cout << diff + (a and b ? (a + b) / 3 : 0) << "\n";
    }
    return 0;
}
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

int k;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> k;

    if (k % 2 == 0) {
        cout << "NO\n";
        return 0;
    }

    int n = (2 * k - 2) * (k - 1) + 2;

    cout << "YES\n";
    cout << n << " " << n * k / 2 << "\n";
    cout << 1 << " " << n / 2 + 1 << "\n";
    for (int i = 1; i <= (k - 1) / 2; i++) {
        int ex = (i - 1) * (2 * k - 2);

        cout << 1 << " " << 2 + ex << "\n";
        cout << 1 + n / 2 << " " << 2 + ex + n / 2 << "\n";

        for (int u = 2; u <= k; u++) {
            cout << u + ex << " " << u + ex + 1 << "\n";
            cout << u + ex + n / 2 << " " << u + ex + n / 2 + 1 << "\n";
        }

        cout << k + ex + 1 << " " << 1 << "\n";
        cout << k + ex + 1 + n / 2 << " " << 1 + n / 2 << "\n";

        for (int u = k + 2; u <= 2 * k - 1; u++) {
            for (int v = 2; v <= k + 1; v++) {
                cout << u + ex << " " << v + ex << "\n";
                cout << u + ex + n / 2 << " " << v + ex + n / 2 << "\n";
            }
        }
    }
    return 0;
}
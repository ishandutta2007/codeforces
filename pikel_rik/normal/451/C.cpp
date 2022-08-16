#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define all(x) (x).begin(), (x).end()

using namespace __gnu_pbds;
using namespace std;

using ull = unsigned long long;
using ll = long long;
using ordered_set = tree<int, null_type, less<>, rb_tree_tag, tree_order_statistics_node_update>;

const int mod = 1e9 + 7;
const int inf = 2e9 + 5;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        ll n, k, d1, d2;
        cin >> n >> k >> d1 >> d2;

        ll a, b, c, target;
        if (k - 2 * d1 - d2 >= 0 and (k - 2 * d1 - d2) % 3 == 0) {
            a = (k - 2 * d1 - d2) / 3;
            b = a + d1;
            c = b + d2;

            target = n / 3;
            if (n % 3 == 0 and a <= target and b <= target and c <= target and target - a + target - b + target - c == n - k) {
                cout << "yes\n";
                continue;
            }
        }
        if (k + 2 * d1 - d2 >= 0 and (k + 2 * d1 - d2) % 3 == 0) {
            a = (k + 2 * d1 - d2) / 3;
            b = a - d1;
            c = b + d2;

            target = n / 3;
            if (n % 3 == 0 and b >= 0 and a <= target and b <= target and c <= target and target - a + target - b + target - c == n - k) {
                cout << "yes\n";
                continue;
            }
        }
        if (k - 2 * d1 + d2 >= 0 and (k - 2 * d1 + d2) % 3 == 0) {
            a = (k - 2 * d1 + d2) / 3;
            b = a + d1;
            c = b - d2;

            target = n / 3;
            if (n % 3 == 0 and c >= 0 and a <= target and b <= target and c <= target and target - a + target - b + target - c == n - k) {
                cout << "yes\n";
                continue;
            }
        }
        if (k + 2 * d1 + d2 >= 0 and (k + 2 * d1 + d2) % 3 == 0) {
            a = (k + 2 * d1 + d2) / 3;
            b = a - d1;
            c = b - d2;

            target = n / 3;
            if (n % 3 == 0 and b >= 0 and c >= 0 and a <= target and b <= target and c <= target and target - a + target - b + target - c == n - k) {
                cout << "yes\n";
                continue;
            }
        }
        cout << "no\n";
    }
    return 0;
}
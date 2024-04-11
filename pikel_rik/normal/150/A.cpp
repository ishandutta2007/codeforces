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

    ll q;
    cin >> q;

    ll ans1 = -1, ans2 = -1, temp = q;
    for (int i = 2; i * (ll)i <= q; i++) {
        while (temp % i == 0) {
            temp /= i;
            if (ans1 == -1) ans1 = i;
            else ans2 = i;
        }

        if (ans2 != -1)
            break;
    }

    if (ans1 == -1) {
        cout << "1\n0\n";
        return 0;
    }

    if (ans2 == -1) {
        cout << "2\n";
        return 0;
    }

    if (ans1 * ans2 == q) {
        cout << "2\n";
        return 0;
    }

    cout << 1 << "\n" << ans1 * ans2 << "\n";
    return 0;
}
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

    ll a, b;
    cin >> a >> b;

    ll ans = 0;
    if (a > b) {
        ans += a / b;
        a %= b;
    }

    while (a > 0 and b != 1) {
        if (b > a) {
            ans += b / a;
            b %= a;
            if (b == 0) {
                b += a;
                ans -= 1;
            }
        }
        if (a >= b) {
            ans += a / b;
            a %= b;
        }
    }

    ans += a;
    cout << ans << "\n";
    return 0;
}
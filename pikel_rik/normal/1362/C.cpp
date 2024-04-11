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

int f(int a, int b) {
    int c = 0;
    for (int i = 0; i < 30; i++) {
        if (((1 << i) & b) != ((1 << i) & a))
            c += 1;
    }
    return c;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        ll n;
        cin >> n;

        ll ans = 0;
        for (int i = 0; n / (1ll << i); i++) {
            ll div = n / (1ll << i);
            div = (div + 1) / 2;

            ans += (i + 1) * div;
        }

        cout << ans << "\n";
    }
    return 0;
}
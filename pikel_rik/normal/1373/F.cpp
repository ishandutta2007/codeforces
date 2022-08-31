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
const int N = 1e6 + 5;

int n, a[N], b[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        cin >> n;
        ll x = 0;

        for (int i = 0; i < n; i++) cin >> a[i], x += a[i];
        for (int i = 0; i < n; i++) cin >> b[i], x -= b[i];

        int y = 0;
        bool ok = true;

        for (int i = 1; i < 2*n; i++) {
            y = max(0, y) + a[i % n] - b[(i - 1) % n];
            if (y > b[i % n])
                ok = false;
        }

        if (ok and x <= 0) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}
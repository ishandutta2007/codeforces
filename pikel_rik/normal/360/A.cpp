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
const int N = 5e3 + 5;

int n, m;
ll a[N], add[N];
tuple<int, int, int, int> q[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    fill(a, a + n, (int)1e9);

    for (int i = 0; i < m; i++) {
        int t, l, r, d;
        cin >> t >> l >> r >> d; --l; --r;
        q[i] = {t, l, r, d};

        if (t == 1) {
            for (int j = l; j <= r; j++)
                add[j] += d;
        }
        else {
            bool ok = false;
            for (int j = l; j <= r; j++) {
                a[j] = min(a[j], d - add[j]);
                if (a[j] + add[j] == d)
                    ok = true;
            }

            if (!ok) {
                cout << "NO\n";
                return 0;
            }
        }
    }

    fill(add, add + n, 0);
    for (int i = 0; i < m; i++) {
        int t, l, r, d;
        tie(t, l, r, d) = q[i];

        if (t == 1) {
            for (int j = l; j <= r; j++)
                add[j] += d;
        }
        else {
            ll mx = LLONG_MIN;
            for (int j = l; j <= r; j++) {
                mx = max(mx, a[j] + add[j]);
            }
            if (mx != d) {
                cout << "NO\n";
                return 0;
            }
        }
    }

    cout << "YES\n";
    for (int i = 0; i < n; i++) cout << a[i] << " "; cout << "\n";
    return 0;
}
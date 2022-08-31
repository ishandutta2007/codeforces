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
const int N = 300 + 5;

struct point {
    int x, y;
    point(): x(), y() {}
};

int n;
point a[N];

int area(point p1, point p2, point p3) {
    return p1.x * (p2.y - p3.y) + p2.x * (p3.y - p1.y) + p3.x * (p1.y - p2.y);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i].x >> a[i].y;

    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int mx = 0, mn = 0;
            for (int k = 0; k < n; k++) {
                if (k == i or k == j) continue;
                mx = max(mx, area(a[k], a[i], a[j]));
                mn = min(mn, area(a[k], a[i], a[j]));
            }

            if (mx == 0 or mn == 0) continue;
            ans = max(ans, mx - mn);
        }
    }

    cout << fixed << setprecision(1) << ans / 2.0 << "\n";
    return 0;
}
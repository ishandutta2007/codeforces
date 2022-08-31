#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define all(x) (x).begin(), (x).end()

using namespace __gnu_pbds;
using namespace std;

using ull = unsigned long long;
using ll = long long;
template <typename T> using ordered_set = tree<T, null_type, less<>, rb_tree_tag, tree_order_statistics_node_update>;

const int mod = 1e9 + 7;
const int inf = INT_MAX;
const int N = 2e3 + 5;

struct point {
    int x, y;
    point(): x(), y() {}
    point(int _x, int _y): x(_x), y(_y) {}
};

int n;
point f1, f2, a[N];

ll dist(point a, point b) {
    return (a.x - b.x) * (ll)(a.x - b.x) + (a.y - b.y) * (ll)(a.y - b.y);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> n >> f1.x >> f1.y >> f2.x >> f2.y;
    for (int i = 0; i < n; i++) cin >> a[i].x >> a[i].y;

    ll best = LLONG_MAX;
    for (int i = 0; i < n; i++) {
        ll r1 = dist(a[i], f1), r2 = 0;
        for (int j = 0; j < n; j++) {
            if (dist(a[j], f1) > r1)
                r2 = max(r2, dist(a[j], f2));
        }

        best = min(best, r1 + r2);
    }

    for (int i = 0; i < n; i++) {
        ll r1 = 0, r2 = dist(a[i], f2);
        for (int j = 0; j < n; j++) {
            if (dist(a[j], f2) > r2)
                r1 = max(r1, dist(a[j], f1));
        }
        best = min(best, r1 + r2);
    }
    cout << best << "\n";
    return 0;
}
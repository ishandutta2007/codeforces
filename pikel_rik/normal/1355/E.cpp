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
const int N = 1e5 + 5;

int n, a, r, m, h[N];

ll f(int x) {
    ll p = 0, q = 0;

    for (int i = 0; i < n; i++) {
        if (h[i] < x)
            p += x - h[i];
        else q += h[i] - x;
    }
    if (p >= q)
        return a * (ll)(p - q) + m * q;
    return r * (ll)(q - p) + m * p;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> n >> a >> r >> m; m = min(m, a + r);
    for (int i = 0; i < n; i++) cin >> h[i];

    sort(h, h + n);
    int lo = 1, hi = 1e9;

    while (hi - lo >= 3) {
        int mid1 = lo + (hi - lo) / 3, mid2 = hi - (hi - lo) / 3;
        ll f1 = f(mid1), f2 = f(mid2);

        if (f1 < f2)
            hi = mid2;
        else lo = mid1;
    }

    ll best = LLONG_MAX;
    for (int i = lo; i <= hi; i++)
        best = min(best, f(i));

    cout << best << "\n";
    return 0;
}
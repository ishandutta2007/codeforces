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
const int N = 1e6 + 5;

int n, m, a[N];

ll f(int i) {
    int lo = 0, hi = n - 1;

    while (lo < hi) {
        int mid = lo + (hi - lo + 1) / 2;
        if (a[mid] < i)
            lo = mid;
        else hi = mid - 1;
    }

    int idx1 = (a[lo] >= i ? -1 : lo);
    int idx2 = upper_bound(a, a + n, i) - a;

    ll ans = 0, c = 0, last = 0;
    for (int j = 0; j <= idx1; j++) {
        c += 1;
        if (c == m) {
            ans += 2ll * abs(a[last] - i);
            c = 0;
            last = j + 1;
        }
    }

    if (c > 0)
        ans += 2ll * abs(a[last] - i);

    c = 0;
    last = n - 1;

    for (int j = n - 1; j >= idx2; j--) {
        c += 1;
        if (c == m) {
            ans += 2ll * abs(a[last] - i);
            c = 0;
            last = j - 1;
        }
    }

    if (c > 0)
        ans += 2ll * abs(a[last] - i);

    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> a[i];

    int lo = a[0], hi = a[n-1];

    while (hi - lo > 2) {
        int mid1 = lo + (hi - lo) / 3, mid2 = hi - (hi - lo) / 3;
        ll f1 = f(mid1), f2 = f(mid2);

        if (f1 > f2)
            lo = mid1;
        else hi = mid2;
    }

    ll best = LLONG_MAX;
    for (int i = lo; i <= hi; i++)
        best = min(best, f(i));

    cout << best << "\n";
    return 0;
}
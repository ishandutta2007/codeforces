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
const int N = 5e5 + 5;

int n, k, a[N];

bool f1(int x) {
    ll sum = 0;
    for (int i = 0; i < n; i++) {
        sum += max(0, a[i] - x);
    }
    return sum <= k;
}

bool f2(int x) {
    ll sum = 0;
    for (int i = 0; i < n; i++) {
        sum += max(0, x - a[i]);
    }
    return sum <= k;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> k;
    for (int i = 0; i < n; i++) cin >> a[i];

    int lo = 1, hi = (int)1e9;

    while (lo < hi) {
        int mid = lo + (hi - lo) / 2;
        if (f1(mid))
            hi = mid;
        else lo = mid + 1;
    }

    int mx = lo;
    lo = 1, hi = (int)1e9;

    while (lo < hi) {
        int mid = lo + (hi - lo + 1) / 2;
        if (f2(mid))
            lo = mid;
        else hi = mid - 1;
    }

    int mn = lo;
    int ans = mx - mn;

    if (ans <= 0) {
        ll sum = accumulate(a, a + n, 0ll);
        if (sum % n != 0)
            ans = 1;
        else ans = 0;
    }

    cout << ans << "\n";
    return 0;
}
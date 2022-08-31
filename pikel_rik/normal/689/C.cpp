#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define all(x) (x).begin(), (x).end()

using namespace __gnu_pbds;
using namespace std;

using ull = unsigned long long;
using ll = long long;
using ordered_set = tree<int, null_type, less<>, rb_tree_tag, tree_order_statistics_node_update>;

const int mod = 1e9 + 7;
const int inf = 2e9 + 5;
const int N = 1e5 + 5;

ll f(ll n) {
    ll sum = 0;
    for (int k = 2; k * (ll)k * k <= n; k++) {
        ll lo = 1, hi = (n + k * (ll)k * k - 1) / (k * (ll)k * k);

        while (lo < hi) {
            ll mid = lo + (hi - lo + 1) / 2;
            if (mid * k * k * k <= n)
                lo = mid;
            else hi = mid - 1;
        }
        sum += lo;
    }
    return sum;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    ll m;
    cin >> m;

    ll lo = 1, hi = 5e15;

    while (lo < hi) {
        ll mid = lo + (hi - lo) / 2;
        if (f(mid) >= m)
            hi = mid;
        else lo = mid + 1;
    }

    if (f(lo) != m)
        cout << "-1\n";
    else cout << lo << "\n";

    return 0;
}
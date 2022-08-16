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
const int N = 3e5 + 5;

int n;
ll a[N], b[N];

int next(int i) {
    return (i + 1) % n;
}

int prev(int i) {
    if (i > 0)
        return i - 1;
    return n - 1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        cin >> n;
        for (int i = 0; i < n; i++) cin >> a[i] >> b[i];

        ll sum = 0;
        for (int i = 0; i < n; i++) {
            sum += max(0ll, a[next(i)] - b[i]);
        }

        ll best = LLONG_MAX;
        for (int i = 0; i < n; i++) {
            ll temp = sum - max(0ll, a[i] - b[prev(i)]);
            best = min(best, temp + a[i]);
        }

        cout << best << "\n";
    }
    return 0;
}
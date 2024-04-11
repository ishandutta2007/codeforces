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
const int N = 1e5 + 5;

int n, a[N], pref[N], l, r, ql, qr;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> n >> l >> r >> ql >> qr;
    for (int i = 0; i < n; i++) cin >> a[i];

    for (int i = 1; i <= n; i++) {
        pref[i] = pref[i - 1] + a[i - 1];
    }

    int best = inf;
    for (int i = 0; i <= n; i++) {
        int left = i, right = n - i;

        int sum = 0;
        if (right > left)
            sum += (right - left - 1) * qr;
        else if (left > right)
            sum += (left - right - 1) * ql;
        sum += pref[i] * l + (pref[n] - pref[i]) * r;
        best = min(best, sum);
    }

    cout << best << "\n";
    return 0;
}
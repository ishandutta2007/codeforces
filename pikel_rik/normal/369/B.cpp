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
const int N = 1e3 + 5;

int n, k, l, r, sall, sk, a[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> k >> l >> r >> sall >> sk;
    for (int i = 0; i < n; i++) a[i] = l;

    sall -= n * l;
    sk -= k * l;

    r -= l;
    if (k > 0) {
        for (int i = 0; i < sk % k; i++)
            a[i] += sk / k + 1;
        for (int i = sk % k; i < k; i++)
            a[i] += sk / k;
    }

    sall -= sk;
    if (k != n) {
        for (int i = k; i < k + sall % (n - k); i++) {
            a[i] += sall / (n - k) + 1;
        }
        for (int i = k + sall % (n - k); i < n; i++) {
            a[i] += sall / (n - k);
        }
    }

    for (int i = 0; i < n; i++) cout << a[i] << " "; cout << "\n";
    return 0;
}
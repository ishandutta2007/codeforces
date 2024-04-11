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
const int N = 2e5 + 5;

int n, k, a[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> n >> k;
    for (int i = 0; i < n; i++) cin >> a[i];

    int mx = 0;
    while (2 * k != n and n > 0) {
        mx = max(mx, a[n-1]);
        n--; k--;
    }

    for (int i = 0; i < n / 2; i++) {
        mx = max(mx, a[i] + a[n - i - 1]);
    }

    cout << mx << "\n";
    return 0;
}
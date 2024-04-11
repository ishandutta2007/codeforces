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

int n, a[N];
ll k;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> n >> k;
    for (int i = 0; i < n; i++) cin >> a[i];

    sort(a, a + n);
    int num = a[(k % n != 0 ? k / n : k / n - 1)];
    int idx = lower_bound(a, a + n, num) - a, c = upper_bound(a, a + n, num) - a - idx;

    k -= idx * (ll)n;
    for (int i = 0; i < n; i++) {
        if (k <= c) {
            cout << num << " " << a[i] << "\n";
            break;
        }
        k -= c;
    }
    return 0;
}
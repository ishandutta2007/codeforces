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
const int N = 1e5 + 5;

int n, x, a[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        cin >> n >> x;
        for (int i = 0; i < n; i++) cin >> a[i];

        int sum = accumulate(a, a + n, 0);

        if (sum % x != 0) {
            cout << n << "\n";
            continue;
        }

        bool flag = false;
        for (int i = 0; i < n; i++) {
            flag |= (a[i] % x != 0);
        }

        if (!flag) {
            cout << "-1\n";
            continue;
        }

        int i, j;
        for (i = 0; a[i] % x == 0; i++) {}

        for (j = n - 1; a[j] % x == 0; j--) {}
        j = n - 1 - j;

        cout << n - 1 - min(i, j) << "\n";
    }
    return 0;
}
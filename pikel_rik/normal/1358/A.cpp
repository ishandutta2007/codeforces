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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n, m;
        cin >> n >> m;

        if (n >= m)
            swap(n, m);
        if (n == 1 and m == 1) {
            cout << "1\n";
            continue;
        }

        if (n % 2 == 0 or m % 2 == 0) {
            cout << (n * m) / 2 << "\n";
            continue;
        }

        cout << min((n * (m - 1)) / 2 + (n + 1) / 2, ((n - 1) * m) / 2 + (m + 1) / 2) << "\n";
    }
    return 0;
}
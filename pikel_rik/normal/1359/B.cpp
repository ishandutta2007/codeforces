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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n, m, x, y;
        cin >> n >> m >> x >> y;

        y = min(2 * x, y);

        vector<string> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];

        int cost = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (a[i][j] == '.') {
                    if (j + 1 < m and a[i][j+1] == '.') {
                        cost += y;
                        j += 1;
                    }
                    else {
                        cost += x;
                    }
                }
            }
        }

        cout << cost << "\n";
    }
    return 0;
}
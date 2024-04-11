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

int n, m, x, y;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m >> x >> y;

    vector<pair<int, int>> ans;
    ans.emplace_back(x, y);
    ans.emplace_back(1, y);
    ans.emplace_back(1, 1);

    for (int i = 1; i <= n; i++) {
        if (i & 1) {
            for (int j = 1; j <= m; j++) {
                if ((i == x and j == y) or (i == 1 and j == y) or (i == 1 and j == 1)) continue;
                ans.emplace_back(i, j);
            }
        }
        else {
            for (int j = m; j >= 1; j--) {
                if ((i == x and j == y) or (i == 1 and j == y) or (i == 1 and j == 1)) continue;
                ans.emplace_back(i, j);
            }
        }
    }

    for (auto &[i, j] : ans) cout << i << " " << j << "\n";
    return 0;
}
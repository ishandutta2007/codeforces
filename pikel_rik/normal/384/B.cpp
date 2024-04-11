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

int n, m, k;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m >> k;

    cout << (m * m - m) / 2 << "\n";
    for (int i = 1; i <= m; i++) {
        for (int j = i + 1; j <= m; j++) {
            if (k == 0)
                cout << i << " " << j << "\n";
            else cout << j << " " << i << "\n";
        }
    }
    return 0;
}
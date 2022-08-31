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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int n;
    cin >> n;

    cout << (n / 2) * ((n + 1) / 2) << "\n";
    for (int i = 1; i <= n / 2; i++) {
        for (int j = n / 2 + 1; j <= n; j++) {
            cout << i << " " << j << "\n";
        }
    }
    return 0;
}
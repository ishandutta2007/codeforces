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
const int N = 1e6 + 5;

int n, k, a[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> n >> k;

    if (n < 3 * k) {
        cout << "-1\n";
        return 0;
    }

    for (int i = 1; i <= k; i++)
        cout << i << " ";

    for (int i = 1; i <= k; i++)
        cout << i << " " << i << " ";

    n -= 3 * k;
    for (int i = 1; i <= n; i++)
        cout << 1 << " ";
    return 0;
}
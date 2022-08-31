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

    int x, y, z, x1, y1, z1, a[7];
    cin >> x >> y >> z >> x1 >> y1 >> z1;

    for (int i = 1; i <= 6; i++) cin >> a[i];

    int sum = 0;
    if (x < 0)
        sum += a[5];

    if (x > x1)
        sum += a[6];

    if (y < 0)
        sum += a[1];

    if (y > y1)
        sum += a[2];

    if (z < 0)
        sum += a[3];

    if (z > z1)
        sum += a[4];

    cout << sum << "\n";
    return 0;
}
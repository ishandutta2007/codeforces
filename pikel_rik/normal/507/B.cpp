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

int r, x, y, newx, newy;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> r >> x >> y >> newx >> newy;

    int diffx = x - newx, diffy = y - newy;
    double dist = sqrt(diffx * (ll)diffx + diffy * (ll)diffy);

    cout << ceil(dist / (2*r));
    return 0;
}
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

struct point {
    int x, y;
    point(int _x = 0, int _y = 0): x(_x), y(_y) {}
};

point a[3];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> a[0].x >> a[0].y >> a[1].x >> a[1].y >> a[2].x >> a[2].y;

    if (a[0].x == a[1].x and a[1].x == a[2].x) {
        cout << "1\n";
        return 0;
    }

    if (a[0].y == a[1].y and a[1].y == a[2].y) {
        cout << "1\n";
        return 0;
    }

    vector<vector<int>> v = {{1, 2, 3}, {1, 3, 2}, {2, 3, 1}};

    for (auto &some : v) {
        int i = some[0] - 1, j = some[1] - 1, k = some[2] - 1;
        if (a[i].x == a[j].x and (a[k].y >= max(a[i].y, a[j].y) or a[k].y <= min(a[i].y, a[j].y))) {
            cout << "2\n";
            return 0;
        }
        if (a[i].y == a[j].y and (a[k].x >= max(a[i].x, a[j].x) or a[k].x <= min(a[i].x, a[j].x))) {
            cout << "2\n";
            return 0;
        }
    }

    cout << "3\n";
    return 0;
}
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

ll area(int x1, int y1, int x2, int y2, int x3, int y3) {
    return x1 * (ll)(y2 - y3) + x2 * (ll)(y3 - y1) + x3 * (ll)(y1 - y2);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int a, b;
    cin >> a >> b;

    if (a == 0 and b == 0) {
        cout << "Yes\n";
        return 0;
    }

    string s;
    cin >> s;

    vector<pair<int, int>> points;

    int x = 0, y = 0;
    for (char i : s) {
        if (i == 'U')
            y++;
        else if (i == 'D')
            y--;
        else if (i == 'L')
            x--;
        else x++;

        points.emplace_back(x, y);
    }

    pair<int, int> final = points.back();

    for (auto &p : points) {
        if (area(p.first, p.second, p.first + final.first, p.second + final.second, a, b) == 0) {
            bool flag1, flag2;

            flag1 = (final.first != 0 and (a - p.first) % final.first == 0 and (a - p.first) / final.first >= 0);
            flag1 |= (final.first == 0 and a == p.first);

            flag2 = (final.second != 0 and (b - p.second) % final.second == 0 and (b - p.second) / final.second >= 0);
            flag2 |= (final.second == 0 and b == p.second);

            if (flag1 and flag2) {
                cout << "Yes\n";
                return 0;
            }
        }

    }

    cout << "No\n";
    return 0;
}
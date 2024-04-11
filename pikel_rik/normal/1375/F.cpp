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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    pair<ll, int> a[3];
    cin >> a[0].first >> a[1].first >> a[2].first;

    a[0].second = 0;
    a[1].second = 1;
    a[2].second = 2;

    cout << "First\n";
    cout.flush();

    sort(a, a + 3);
    cout << 2 * a[2].first - a[0].first - a[1].first << "\n";
    cout.flush();

    int pile;
    cin >> pile;

    if (pile == a[0].second + 1) {
        cout << a[2].first - a[1].first << "\n";
        cout.flush();
    }
    else if (pile == a[1].second + 1) {
        cout << a[2].first - a[0].first << "\n";
        cout.flush();
    }
    else {
        a[2].first += 2 * a[2].first - a[0].first - a[1].first;
        cout << 2 * a[2].first - a[0].first - a[1].first << "\n";
        cout.flush();

        cin >> pile;
        if (pile == a[0].second + 1) {
            cout << a[2].first - a[1].first << "\n";
            cout.flush();
        }
        else if (pile == a[1].second + 1) {
            cout << a[2].first - a[0].first << "\n";
            cout.flush();
        }
    }
    return 0;
}
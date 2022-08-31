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

    int t;
    cin >> t;

    while (t--) {
        int a, b, c;
        cin >> a >> b >> c;

        if (a == c) {
            cout << "-1 " << 2 << "\n";
            continue;
        }

        if (a < c) {
            cout << 1 << " ";
            if (a * (ll)b <= c)
                cout << "-1\n";
            else cout << b << "\n";
        }
        else cout << "-1 " << 1 << "\n";
    }
    return 0;
}
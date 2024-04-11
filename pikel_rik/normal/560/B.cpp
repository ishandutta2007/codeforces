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

    int a1, b1, a2, b2, a3, b3;
    cin >> a1 >> b1 >> a2 >> b2 >> a3 >> b3;

    if (a1 > b1) swap(a1, b1);
    if (a2 > b2) swap(a2, b2);
    if (a3 > b3) swap(a3, b3);

    for (int i = 0; i < 2; i++) {
        swap(a1, b1);
        for (int j = 0; j < 2; j++) {
            swap(a2, b2);
            for (int k = 0; k < 2; k++) {
                swap(a3, b3);
                if (a2 + a3 <= a1 and max(b2, b3) <= b1) {
                    cout << "YES\n";
                    return 0;
                }
            }
        }
    }

    cout << "NO\n";
    return 0;
}
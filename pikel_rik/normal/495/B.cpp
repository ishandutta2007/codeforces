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

    int a, b;
    cin >> a >> b;

    if (a < b) {
        cout << "0\n";
        return 0;
    }

    if (a == b) {
        cout << "infinity\n";
        return 0;
    }

    a -= b;

    int c = 0;
    for (int i = 1; i * i <= a; i++) {
        if (a % i == 0) {
            if (i > b)
                c += 1;
            if (i != a / i and a / i > b)
                c += 1;
        }
    }

    cout << c << "\n";
    return 0;
}
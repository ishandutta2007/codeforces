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

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        if (n & 1) {
            if (n == 1)
                cout << "FastestFinger\n";
            else cout << "Ashishgup\n";
            continue;
        }

        int c = 0;
        for (int i = 2; i * i <= n; i++) {
            if (n % i == 0) {
                if (i & 1)
                    c++;
                if (n / i != i and ((n / i) & 1))
                    c++;
            }
        }

        if (n == 2)
            cout << "Ashishgup\n";
        else if (c == 0)
            cout << "FastestFinger\n";
        else if (n % 4 == 0)
            cout << "Ashishgup\n";
        else {
            if (c > 1)
                cout << "Ashishgup\n";
            else cout << "FastestFinger\n";
        }
    }
    return 0;
}
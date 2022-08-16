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

    int n;
    cin >> n;

    if (n < 4) {
        cout << "NO\n";
        return 0;
    }

    cout << "YES\n";
    if (n % 4 == 0) {
        cout << "1 * 2 = 2\n2 * 3 = 6\n6 * 4 = 24\n";
        for (int i = 2; i <= n / 4; i++) {
            cout << 4 * i << " + " << 4 * i - 3 << " = " << 8 * i - 3 << "\n";
            cout << 4 * i - 1 << " + " << 4 * i - 2 << " = " << 8 * i - 3 << "\n";
            cout << 8 * i - 3 << " - " << 8 * i - 3 << " = " << 0 << "\n";
            cout << "24 + 0 = 24\n";
        }
    }
    else if (n % 4 == 1) {
        cout << "5 * 4 = 20\n3 - 1 = 2\n2 + 2 = 4\n4 + 20 = 24\n";
        for (int i = 6; i <= n; i += 4) {
            cout << i << " + " << i + 3 << " = " << 2*i + 3 << "\n";
            cout << i + 1 << " + " << i + 2 << " = " << 2*i + 3 << "\n";
            cout << 2*i + 3 << " - " << 2*i + 3 << " = " << 0 << "\n";
            cout << "24 + 0 = 24\n";
        }
    }
    else if (n % 4 == 2) {
        cout << "6 * 5 = 30\n4 - 2 = 2\n1 + 3 = 4\n4 + 2 = 6\n30 - 6 = 24\n";
        for (int i = 7; i <= n; i += 4) {
            cout << i << " + " << i + 3 << " = " << 2*i + 3 << "\n";
            cout << i + 1 << " + " << i + 2 << " = " << 2*i + 3 << "\n";
            cout << 2*i + 3 << " - " << 2*i + 3 << " = " << 0 << "\n";
            cout << "24 + 0 = 24\n";
        }
    }
    else {
        cout << "7 * 6 = 42\n4 * 5 = 20\n3 - 2 = 1\n20 - 1 = 19\n19 - 1 = 18\n42 - 18 = 24\n";
        for (int i = 8; i <= n; i += 4) {
            cout << i << " + " << i + 3 << " = " << 2*i + 3 << "\n";
            cout << i + 1 << " + " << i + 2 << " = " << 2*i + 3 << "\n";
            cout << 2*i + 3 << " - " << 2*i + 3 << " = " << 0 << "\n";
            cout << "24 + 0 = 24\n";
        }
    }
    return 0;
}
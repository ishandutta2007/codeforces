#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define all(x) (x).begin(), (x).end()

using namespace __gnu_pbds;
using namespace std;

using ull = unsigned long long;
using ll = long long;
using ordered_set = tree<int, null_type, less<>, rb_tree_tag, tree_order_statistics_node_update>;

int mod = 1e9 + 7;
const int inf = 2e9 + 5;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int n, a, b;
    cin >> n >> a >> b;
    
    if (n == 1) {
        cout << "1\n";
        return 0;
    }

    if (a == n - 1 and b == 0) {
        cout << "-1\n";
        return 0;
    }

    if (b == 0) {
        cout << "2 1 ";
        for (int i = 0; i < n - 2; i++) {
            if (a) {
                cout << 3 + i << " ";
                a -= 1;
            }
            else cout << 1 << " ";
        }
        return 0;
    }

    cout << "1 ";
    for (int i = 0; i < b; i++)
        cout << (1u << (i + 1)) << " ";

    for (int i = 0; i < n - b - 1; i++) {
        if (a) {
            cout << (1u << b) + i + 1 << " ";
            a -= 1;
        } else cout << 1 << " ";
    }
    return 0;
}
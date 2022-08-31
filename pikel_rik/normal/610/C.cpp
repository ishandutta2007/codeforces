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
const int N = 5e4 + 5;

int ans[512][512];

void recurse(int k, int x = 0, int y = 0, bool sign = false) {
    if (k == 0 and sign) {
        ans[x][y] = -1;
        return;
    }
    else if (k == 0 and !sign) {
        ans[x][y] = 1;
        return;
    }

    recurse(k - 1, x, y, sign);
    recurse(k - 1, x, y + (1 << (k - 1)), sign);
    recurse(k - 1, x + (1 << (k - 1)), y, sign);
    recurse(k - 1, x + (1 << (k - 1)), y + (1 << (k - 1)), !sign);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int k;
    cin >> k;

    recurse(k);
    for (int i = 0; i < (1 << k); i++) {
        for (int j = 0; j < (1 << k); j++) {
            if (ans[i][j] == 1) cout << '+';
            else cout << '*';
        }
        cout << "\n";
    }
    return 0;
}
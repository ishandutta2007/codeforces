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
const int N = 200 + 5;

int n, m, a[N], b[N];

bool isSubmask(int x, int y) {
    for (int i = 0; i < 9; i++) {
        if ((x & (1 << i)) and !(y & (1 << i)))
            return false;
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < m; i++) cin >> b[i];

    int ans = 0;
    for (int x = (1 << 9) - 1; x >= 0; x--) {
        bool ok = true;
        for (int i = 0; i < n; i++) {
            bool flag = false;
            for (int j = 0; j < m; j++) {
                if (isSubmask(a[i] & b[j], x)) {
                    flag = true;
                    break;
                }
            }
            ok &= flag;
        }
        if (ok)
            ans = x;
    }

    cout << ans << "\n";
    return 0;
}
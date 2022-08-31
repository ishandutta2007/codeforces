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
const int N = 5e6 + 5;

ll ans[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int t;
    cin >> t;

    for (int i = 2; i <= 5e6; i++) {
        if (!ans[i]) {
            for (int j = i; j <= 5e6; j += i) {
                ans[j] = ans[j / i] + 1;
            }
        }
    }

    for (int i = 1; i <= 5e6; i++)
        ans[i] += ans[i-1];

    while (t--) {
        int a, b;
        cin >> a >> b;

        cout << ans[a] - ans[b] << "\n";
    }
    return 0;
}
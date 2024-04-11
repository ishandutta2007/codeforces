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
const int N = 1e6 + 1;

int n, a[N], prefix[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];

    for (int i = 1; i <= n; i++)
        prefix[i] = prefix[i-1] ^ i;

    int ans = 0;
    for (int i = 0; i < n; i++) ans ^= a[i];

    for (int i = 2; i <= n; i++) {
        int div = n / i;

        if (div % 2 == 0) {
            ans = ans ^ (prefix[n % i]);
        }
        else {
            ans = ans ^ prefix[n % i] ^ prefix[i-1];
        }
    }

    cout << ans << "\n";
    return 0;
}
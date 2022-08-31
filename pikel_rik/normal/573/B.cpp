#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define all(x) (x).begin(), (x).end()

using namespace __gnu_pbds;
using namespace std;

using ull = unsigned long long;
using ll = long long;
using ordered_set = tree<int, null_type, less<>, rb_tree_tag, tree_order_statistics_node_update>;

const int mod = 1e9 + 7;
const int inf = 2e9 + 5;
const int N = 1e5 + 1;

int n, a[N], dp1[N], dp2[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];

    dp1[0] = 1;
    for (int i = 1; i < n; i++) {
        dp1[i] = min(a[i], 1 + dp1[i-1]);
    }

    dp2[n-1] = 1;
    for (int i = n - 2; i >= 0; i--) {
        dp2[i] = min(a[i], 1 + dp2[i+1]);
    }

    int ans = 0;
    for (int i = 0; i < n; i++) {
        ans = max(ans, min(dp1[i], dp2[i]));
    }

    cout << ans << "\n";
    return 0;
}
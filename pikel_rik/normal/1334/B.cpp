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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n, x;
        cin >> n >> x;

        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];

        sort(all(a));
        ll sum = accumulate(all(a), 0ll);

        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (sum >= (n - i) * (ll)x) {
                break;
            }
            ans++;
            sum -= a[i];
        }

        cout << n - ans << "\n";
    }
    return 0;
}
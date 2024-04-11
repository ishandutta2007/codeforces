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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];

        sort(all(a));

        int ans = 0, c = 0, cur = 0;
        for (int i = 0; i < n; i++) {
            if (i > 0 and a[i] != a[i-1]) {
                if (c >= a[i-1]) {
                    ans += cur;
                    cur = 0;
                }
            }
            cur += 1;
            c += 1;
        }

        if (c >= a[n-1])
            ans += cur;
        cout << ans + 1 << "\n";
    }
    return 0;
}
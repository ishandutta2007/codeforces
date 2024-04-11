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
        int n;
        cin >> n;

        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];

        vector<int> pos = {0};
        for (int i = 1; i < n; i++) {
            if (a[i] != a[i - 1])
                pos.push_back(i);
        }

        int ans = 0;
        for (int i = 1; i < pos.size() - 1; i++) {
            if (a[pos[i]] < a[pos[i - 1]] and a[pos[i]] < a[pos[i + 1]])
                ans = pos[i];
        }

        cout << ans << "\n";
    }
    return 0;
}
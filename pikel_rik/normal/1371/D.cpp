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
        int n, k;
        cin >> n >> k;

        vector<vector<int>> ans(n, vector<int>(n));

        for (int i = 0; i < n && k; i++) {
            for (int j = 0; j < n && k; j++) {
                ans[j][(i + j) % n] = 1;
                k--;
            }
        }

        int val = 0;
        int mx = -inf, mn = inf;

        for (int i = 0; i < n; i++) {
            int sum = 0;
            for (int j = 0; j < n; j++)
                sum += ans[i][j];
            mx = max(mx, sum);
            mn = min(mn, sum);
        }

        val += (mx - mn) * (mx - mn);
        mx = -inf; mn = inf;

        for (int j = 0; j < n; j++) {
            int sum = 0;
            for (int i = 0; i < n; i++)
                sum += ans[i][j];
            mx = max(mx, sum);
            mn = min(mn, sum);
        }

        val += (mx - mn) * (mx - mn);
        cout << val << "\n";
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) cout << ans[i][j];
            cout << "\n";
        }
    }
    return 0;
}
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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n, m;
        cin >> n >> m;

        vector<vector<int>> a(30, vector<int>(30));
        for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) cin >> a[i][j];

        if (n == 2 and m == 2) {
            int ans = 0;
            if (a[0][0] != a[1][1])
                ans++;
            cout << ans << "\n";
            continue;
        }

        int ans = 0;

        vector<pair<int, int>> cnt(n + m);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (a[i][j] == 0)
                    cnt[i + j].first++;
                else cnt[i + j].second++;
            }
        }

        for (int i = 0; i < n + m - i - 2; i++) {
            int sum1 = cnt[i].first + cnt[n + m - i - 2].first, sum2 = cnt[i].second + cnt[n + m - i - 2].second;
            ans += min(sum1, sum2);
        }

        cout << ans << "\n";
    }
    return 0;
}
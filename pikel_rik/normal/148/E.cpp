#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define all(x) (x).begin(), (x).end()

using namespace __gnu_pbds;
using namespace std;

using ull = unsigned long long;
using ll = long long;
template <typename T> using ordered_set = tree<T, null_type, less<>, rb_tree_tag, tree_order_statistics_node_update>;

const int mod = 1e9 + 7;
const int inf = INT_MAX;
const int N = 1e2 + 5;

int n, m, sum[N][N];
vector<int> a[N];

int dp[N][N*N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        int sz; cin >> sz;
        a[i].resize(sz);
        for (int j = 0; j < sz; j++)
            cin >> a[i][j];
    }

    for (int i = 0; i < n; i++) {
        vector<int> pref(a[i].size());
        pref[0] = a[i][0];

        for (int j = 1; j < a[i].size(); j++)
            pref[j] = pref[j - 1] + a[i][j];

        sum[i][a[i].size()] = pref[a[i].size() - 1];

        for (int j = 0; j < a[i].size() - 1; j++)
            sum[i][j + 1] = max(sum[i][j + 1], pref[j]);

        for (int j = a[i].size() - 1; j >= 1; j--)
            sum[i][a[i].size() - j] = max(sum[i][a[i].size() - j], pref[a[i].size() - 1] - pref[j - 1]);

        for (int j = 0; j < a[i].size(); j++) {
            for (int k = j + 2; k < a[i].size(); k++) {
                sum[i][j + 1 + a[i].size() - k] = max(sum[i][j + 1 + a[i].size() - k], pref[j] + pref[a[i].size() - 1] - pref[k - 1]);
            }
        }
    }

    for (int j = 1; j <= a[0].size(); j++)
        dp[0][j] = sum[0][j];

    for (int i = 1; i < n; i++) {
        for (int j = 1; j <= a[i].size(); j++) {
            for (int k = 0; k <= m; k++) {
                dp[i][k] = max(dp[i][k], dp[i-1][k]);
                if (k >= j)
                    dp[i][k] = max(dp[i][k], sum[i][j] + dp[i - 1][k - j]);
            }
        }
    }

    cout << dp[n-1][m] << "\n";
    return 0;
}
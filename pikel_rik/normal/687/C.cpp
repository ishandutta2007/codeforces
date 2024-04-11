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
const int N = 500 + 5;

int n, sum, c[N];
bool dp[N][N][N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> n >> sum;
    for (int i = 1; i <= n; i++) cin >> c[i];

    dp[0][0][0] = true;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= sum; j++) {
            for (int k = 0; k <= sum; k++) {
                dp[i][j][k] = dp[i - 1][j][k];
                if (j >= c[i])
                    dp[i][j][k] |= dp[i - 1][j - c[i]][k];
                if (j >= c[i] and k >= c[i])
                    dp[i][j][k] |= dp[i - 1][j - c[i]][k - c[i]];
            }
        }
    }

    vector<int> ans = {0};
    for (int i = 1; i <= sum; i++) {
        if (dp[n][sum][i])
            ans.push_back(i);
    }

    cout << ans.size() << "\n";
    for (int i : ans) cout << i << " "; cout << "\n";
    return 0;
}
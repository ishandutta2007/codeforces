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
const int N = 131072 + 5;

int n, dp[18][26][N], pref[N][26];
string s;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        cin >> n >> s;

        int k;
        for (k = 0; n >> k; k++) {}
        k--;

        for (int i = 1; i <= n; i++) {
            for (int j = 0; j < 26; j++) {
                pref[i][j] = pref[i - 1][j];
            }
            pref[i][s[i - 1] - 'a']++;
        }

        for (int j = 0; j < 26; j++) {
            for (int i = 0; i < n; i++) {
                dp[0][j][i] = (s[i] - 'a' != j);
            }
        }
        for (int l = 1; l <= k; l++) {
            for (int j = 0; j < 26 - l; j++) {
                for (int i = 0; i + (1 << l) <= n; i += (1 << l)) {
                    dp[l][j][i] = (1 << (l - 1)) - pref[i + (1 << (l - 1))][j] + pref[i][j] + dp[l - 1][j + 1][i + (1 << (l - 1))];
                    dp[l][j][i] = min(dp[l][j][i], (1 << (l - 1)) - pref[i + (1 << l)][j] + pref[i + (1 << (l - 1))][j] + dp[l - 1][j + 1][i]);
                }
            }
        }

        cout << dp[k][0][0] << "\n";
    }
    return 0;
}
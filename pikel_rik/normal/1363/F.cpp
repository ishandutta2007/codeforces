#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;
using ll = long long;
using ld = long double;

const int mod = 1e9 + 7;
const int inf = INT_MAX;
const int N = 2000 + 5;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        int n;
        cin >> n;

        string s, t;
        cin >> s >> t;
        s = ' ' + s;
        t = ' ' + t;

        vector<vector<int>> cnt1(n + 1, vector<int>(26)), cnt2(n + 1, vector<int>(26));
        for (int i = 1; i <= n; i++) {
            cnt1[i] = cnt1[i - 1];
            cnt2[i] = cnt2[i - 1];
            cnt1[i][s[i] - 'a']++;
            cnt2[i][t[i] - 'a']++;
        }

        bool impossible = false;
        for (int i = 0; i < 26; i++) {
            impossible |= (cnt1[n][i] - cnt2[n][i]);
        }
        if (impossible) {
            cout << "-1\n";
            continue;
        }

        vector<vector<int>> dp(n + 1, vector<int>(n + 1));

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                dp[i][j] = INT_MAX;
                if (s[i] == t[j]) {
                    dp[i][j] = min(dp[i][j], dp[i - 1][j - 1]);
                }
                if (cnt1[n][t[j] - 'a'] - cnt1[i][t[j] - 'a'] > cnt2[n][t[j] - 'a'] - cnt2[j][t[j] - 'a']) {
                    dp[i][j] = min(dp[i][j], dp[i][j - 1]);
                }
                dp[i][j] = min(dp[i][j], 1 + dp[i - 1][j]);
            }
        }

        cout << dp[n][n] << '\n';
    }
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;
using ll = long long;
using ld = long double;

const int mod = 1e9 + 7;
const int inf = INT_MAX;
const int N = 2e5 + 5;

int n, a[N], dp[N][3][3];
string s;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        cin >> n >> s;
        for (int i = 0; i < n; i++) a[i] = (s[i] == 'R');
        //L + R = anything, R + L = anything, R + R = L, L + L = R

        int ans = INT_MAX, x = a[0], y = a[1];
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                a[0] = i;
                a[1] = j;

                dp[0][a[0]][1] = 0;
                dp[0][1 - a[0]][1] = 1;
                dp[0][a[0]][2] = INT_MAX;
                dp[0][1 - a[0]][2] = INT_MAX;

                for (int k = 1; k < n; k++) {
                    dp[k][a[k]][1] = min(dp[k - 1][1 - a[k]][1], dp[k - 1][1 - a[k]][2]);
                    dp[k][a[k]][2] = dp[k - 1][a[k]][1];
                    dp[k][1 - a[k]][1] = 1 + min(dp[k - 1][a[k]][1], dp[k - 1][a[k]][2]);
                    dp[k][1 - a[k]][2] = 1 + dp[k - 1][1 - a[k]][1];
                }

                int temp = (x != a[0]) + (y != a[1]);
                if (a[0] == 0 and a[1] == 0)
                    temp += min(dp[n - 1][1][1], dp[n - 1][1][2]);
                else if (a[0] == 0 and a[1] == 1)
                    temp += min({dp[n - 1][1][1], dp[n - 1][1][2], dp[n - 1][0][1]});
                else if (a[0] == 1 and a[1] == 0)
                    temp += min({dp[n - 1][1][1], dp[n - 1][0][1], dp[n - 1][0][2]});
                else temp += min(dp[n - 1][0][1], dp[n - 1][0][2]);
                ans = min(ans, temp);
            }
        }

        cout << ans << "\n";
    }
    return 0;
}
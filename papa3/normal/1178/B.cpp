#include <bits/stdc++.h>

using namespace std;

#define int long long
#define double long double
#define mod 1000000007ll
#define INF 1000000000000000000ll

#define MAX_N 1000010

int dp[MAX_N][5];

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string s;
    int res = 0;
    cin >> s;
    for (int i = 0; i + 1 < s.size(); i++) {
        if (i) {
            for (int j = 1; j <= 3; j++) {
                dp[i][j] = dp[i - 1][j];
            }
        }
        if (s[i] == 'v') {

            if (s[i + 1] == 'v') {
                dp[i][1]++;
                if (i) {
                    dp[i][3] += dp[i - 1][2];
                    res += dp[i - 1][2];
                }
            }
        } else if (i) {
            dp[i][2] += dp[i - 1][1];
        }

        /*for (int j = 1; j <= 3; j++) {
            cout << dp[i][j] << " ";
        }
        cout << endl;*/
    }

    cout << res;

    return 0;
}
/*

*/
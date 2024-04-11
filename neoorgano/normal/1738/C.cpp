#include <bits/stdc++.h>
using namespace std;

const int MAXN = 200;
int dp[2][MAXN][MAXN];

main() {
    int tst;
    cin >> tst;
    while (tst--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        int cnt0 = 0, cnt1 = 0;
        for (int i = 0; i < n; ++i) {
            cin >> arr[i];
            if (arr[i] % 2 == 0) {
                cnt0++;
            } else {
                cnt1++;
            }
        }
        dp[0][0][0] = 1;
        dp[1][0][0] = 0;
        for (int i = 0; i <= cnt0; ++i) {
            for (int j = 0; j <= cnt1; ++j) {
                if (i == 0 && j == 0) continue;
                for (int t = 0; t < 2; ++t) {
                    dp[t][i][j] = 0;
                    if (i != 0) {
                        if (dp[(j % 2) ^ 1 ^ t][i - 1][j] == 0) {
                            dp[t][i][j] = 1;
                        }
                    }
                    if (j != 0) {
                        if (dp[(j % 2) ^ 1 ^ t][i][j - 1] == 0) {
                            dp[t][i][j] = 1;
                        }
                    }
                }
            }
        }
        if (dp[0][cnt0][cnt1]) {
            cout << "Alice" << endl;
        } else {
            cout << "Bob" << endl;
        }
    }
    return 0;
}
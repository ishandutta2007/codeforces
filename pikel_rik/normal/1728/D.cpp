#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        string s;
        cin >> s;

        int n = (int) s.length();

        s = '#' + s;

        enum state { win, draw, lose };
        vector<vector<state>> dp(n + 2, vector<state>(n + 2, draw));

        auto f = [&](int i, int j, char c) -> state {
            if (dp[i + 1][j] == lose || dp[i][j - 1] == lose) {
                return lose;
            } else if (dp[i + 1][j] == draw && s[i] < c) {
                return lose;
            } else if (dp[i][j - 1] == draw && s[j] < c) {
                return lose;
            } else if (dp[i + 1][j] == draw && s[i] == c) {
                return draw;
            } else if (dp[i][j - 1] == draw && s[j] == c) {
                return draw;
            } else {
                return win;
            }
        };

        for (int l = 2; l <= n; l++) {
            for (int i = 1; i + l <= n + 1; i++) {
                int j = i + l - 1;
                dp[i][j] = min(f(i + 1, j, s[i]), f(i, j - 1, s[j]));
            }
        }

        if (dp[1][n] == win) {
            cout << "Alice\n";
        } else if (dp[1][n] == lose) {
            cout << "Bob\n";
        } else {
            cout << "Draw\n";
        }
    }
    return 0;
}
#include <bits/stdc++.h>

using namespace std;

void run();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    run();
    return 0;
}

const int INF = (int) (1e9 + 1e6 + 123);

bool test(int mask, int bit) {
    return (bool) (mask & (1 << bit));
}

void update(int &x, int y) {
    if (y > x) {
        x = y;
    }
}

void run() {
    string a[2];
    cin >> a[0] >> a[1];
    int n = (int) a[0].size();
    a[0] = "X" + a[0];
    a[1] = "X" + a[1];
    vector<vector<int>> dp(n + 1, vector<int>(4, -INF));
    dp[0][3] = 0;

    for (int i = 0; i < n; i++) {
        for (int mask = 0; mask < 4; mask++) {
            bool up = !test(mask, 0) && a[0][i] != 'X';
            bool down = !test(mask, 1) && a[1][i] != 'X';
            bool right_up = a[0][i + 1] != 'X';
            bool right_down = a[1][i + 1] != 'X';
            if (up && down && right_up) {
                update(dp[i + 1][1 << 0], dp[i][mask] + 1);
            }
            if (up && down && right_down) {
                update(dp[i + 1][1 << 1], dp[i][mask] + 1);
            }
            if (up && right_up && right_down) {
                update(dp[i + 1][(1 << 0) | (1 << 1)], dp[i][mask] + 1);
            }
            if (down && right_up && right_down) {
                update(dp[i + 1][(1 << 0) | (1 << 1)], dp[i][mask] + 1);
            }
            update(dp[i + 1][0], dp[i][mask]);
        }
    }

    cout << *max_element(dp[n].begin(), dp[n].end()) << "\n";
}
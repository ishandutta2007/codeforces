#include <algorithm>
#include <cassert>
#include <iomanip>
#include <iostream>
#include <vector>
using namespace std;

const int N = 10;
const int SIDES = 6;

int ladder[N][N];
double dp[N][N];

pair<int, int> transition(int r, int c, int s) {
    if (r % 2 == 0) {
        if (s > c && r == 0)
            return {-1, -1};

        if (c >= s)
            return {r, c - s};

        return {r - 1, s - c - 1};
    } else {
        if (c + s < N)
            return {r, c + s};

        return {r - 1, N - 1 - (c + s - N)};
    }
}

int main() {
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> ladder[i][j];

    for (int r = 0; r < N; r++) {
        vector<int> order;

        for (int c = 0; c < N; c++)
            order.push_back(c);

        if (r % 2 == 1)
            reverse(order.begin(), order.end());

        for (int c : order) {
            if (r == 0 && c == 0) {
                dp[r][c] = 0;
                continue;
            }

            double sum = 0, missing = 0;

            for (int s = 1; s <= SIDES; s++) {
                pair<int, int> p = transition(r, c, s);

                if (p.first < 0) {
                    missing += 1.0 / SIDES;
                } else {
                    double value = dp[p.first][p.second];

                    if (ladder[p.first][p.second] > 0)
                        value = min(value, dp[p.first - ladder[p.first][p.second]][p.second]);

                    sum += 1.0 / SIDES * (value + 1);
                }
            }

            dp[r][c] = (sum + missing) / (1 - missing);
        }
    }

    cout << fixed << setprecision(10);
    cout << dp[N - 1][0] << '\n';
}
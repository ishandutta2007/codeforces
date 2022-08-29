#include <algorithm>
#include <cassert>
#include <cstring>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

const int N_MAX = 52;
const char EMPTY = '.';

int N;
vector<string> grid;
int dp[N_MAX][N_MAX][N_MAX][N_MAX];
int row_sum[N_MAX][N_MAX];
int col_sum[N_MAX][N_MAX];

int solve(int h1, int h2, int w1, int w2) {
    if (h1 >= h2 || w1 >= w2)
        return 0;

    int &answer = dp[h1][h2][w1][w2];

    if (answer >= 0)
        return answer;

    answer = max(h2 - h1, w2 - w1);

    if (h2 - h1 > w2 - w1) {
        for (int h = h1; h < h2; h++)
            if (row_sum[h][w2] - row_sum[h][w1] == 0)
                answer = min(answer, solve(h1, h, w1, w2) + solve(h + 1, h2, w1, w2));
    } else {
        for (int w = w1; w < w2; w++)
            if (col_sum[w][h2] - col_sum[w][h1] == 0)
                answer = min(answer, solve(h1, h2, w1, w) + solve(h1, h2, w + 1, w2));
    }

    return answer;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    grid.resize(N);

    for (string &row : grid)
        cin >> row;

    for (int i = 0; i < N; i++) {
        row_sum[i][0] = 0;
        col_sum[i][0] = 0;

        for (int j = 0; j < N; j++) {
            row_sum[i][j + 1] = row_sum[i][j] + (grid[i][j] != EMPTY ? 1 : 0);
            col_sum[i][j + 1] = col_sum[i][j] + (grid[j][i] != EMPTY ? 1 : 0);
        }
    }

    memset(dp, -1, sizeof(dp));
    cout << solve(0, N, 0, N) << '\n';
}
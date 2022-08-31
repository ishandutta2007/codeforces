#include <algorithm>
#include <cassert>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int N, K;
vector<string> grid;
vector<int> row_first, row_last, col_first, col_last;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> K;
    grid.resize(N);

    for (string &row : grid)
        cin >> row;

    row_first.assign(N, -1);
    row_last.assign(N, -1);
    col_first.assign(N, -1);
    col_last.assign(N, -1);

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            if (grid[i][j] == 'B') {
                if (row_first[i] == -1)
                    row_first[i] = j;

                row_last[i] = j;

                if (col_first[j] == -1)
                    col_first[j] = i;

                col_last[j] = i;
            }

    int best = 0;

    for (int row = 0; row + K <= N; row++) {
        int lines = 0;

        for (int i = 0; i < N; i++) {
            if (row_first[i] < 0)
                lines++;

            if (col_first[i] < 0)
                lines++;
        }

        vector<int> loss(N, 0), gain(N, 0);

        for (int i = row; i < row + K; i++)
            if (row_first[i] >= 0  && row_last[i] - row_first[i] < K) {
                loss[row_first[i]]++;
                gain[row_last[i]]++;
            }

        for (int end = 0; end < N; end++) {
            lines += gain[end];

            if (row <= col_first[end] && col_last[end] < row + K)
                lines++;

            if (end >= K) {
                lines -= loss[end - K];

                if (row <= col_first[end - K] && col_last[end - K] < row + K)
                    lines--;
            }

            best = max(best, lines);
        }
    }

    cout << best << '\n';
}
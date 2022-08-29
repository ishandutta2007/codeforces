#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

const int MOD = 1e9 + 7;

enum cell {
    UNKNOWN,
    ON,
    OFF
};

int H, W;
vector<vector<cell>> status;

bool set_cell(int row, int col, cell state) {
    if (status[row][col] != UNKNOWN && status[row][col] != state)
        return false;

    status[row][col] = state;
    return true;
}

bool set_row(int row, int r) {
    for (int i = 0; i < r; i++)
        if (!set_cell(row, i, OFF))
            return false;

    if (r < W && !set_cell(row, r, ON))
        return false;

    return true;
}

bool set_col(int col, int c) {
    for (int i = 0; i < c; i++)
        if (!set_cell(i, col, OFF))
            return false;

    if (c < H && !set_cell(c, col, ON))
        return false;

    return true;
}

int main() {
    cin >> H >> W;
    status.assign(H, vector<cell>(W, UNKNOWN));

    for (int h = 0; h < H; h++) {
        int r;
        cin >> r;

        if (!set_row(h, r)) {
            cout << 0 << '\n';
            return 0;
        }
    }

    for (int w = 0; w < W; w++) {
        int c;
        cin >> c;

        if (!set_col(w, c)) {
            cout << 0 << '\n';
            return 0;
        }
    }

    int answer = 1;

    for (int h = 0; h < H; h++)
        for (int w = 0; w < W; w++)
            if (status[h][w] == UNKNOWN)
                answer = 2 * answer % MOD;

    cout << answer << '\n';
}
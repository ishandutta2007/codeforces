#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int R, C;
vector<string> grid;

bool is_all_A(int start_r, int end_r, int start_c, int end_c) {
    for (int r = start_r; r < end_r; r++)
        for (int c = start_c; c < end_c; c++)
            if (grid[r][c] != 'A')
                return false;

    return true;
}

void solve_case() {
    cin >> R >> C;
    grid.resize(R);

    for (string &row : grid)
        cin >> row;

    bool all_A = true, all_P = true;

    for (int r = 0; r < R; r++)
        for (int c = 0; c < C; c++)
            if (grid[r][c] == 'A') {
                all_P = false;
            } else {
                all_A = false;
            }

    if (all_P) {
        cout << "MORTAL" << '\n';
        return;
    }

    if (all_A) {
        cout << 0 << '\n';
        return;
    }

    if (is_all_A(0, 1, 0, C) || is_all_A(R - 1, R, 0, C) || is_all_A(0, R, 0, 1) || is_all_A(0, R, C - 1, C)) {
        cout << 1 << '\n';
        return;
    }

    bool is_two = grid[0][0] == 'A' || grid[0][C - 1] == 'A' || grid[R - 1][0] == 'A' || grid[R - 1][C - 1] == 'A';

    for (int r = 0; r < R; r++)
        if (is_all_A(r, r + 1, 0, C))
            is_two = true;

    for (int c = 0; c < C; c++)
        if (is_all_A(0, R, c, c + 1))
            is_two = true;

    if (is_two) {
        cout << 2 << '\n';
        return;
    }

    bool is_three = false;

    for (int r = 0; r < R; r++)
        for (int c = 0; c < C; c++)
            if (grid[r][c] == 'A' && (r == 0 || r == R - 1 || c == 0 || c == C - 1))
                is_three = true;

    cout << (is_three ? 3 : 4) << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T-- > 0)
        solve_case();
}
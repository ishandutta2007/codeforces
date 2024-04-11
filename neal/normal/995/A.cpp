#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

const int N_MAX = 105;

int N, K;
int grid[5][N_MAX];
vector<string> answer;
vector<pair<int, int>> ring;

void add_to_answer(int x, int r, int c) {
    answer.push_back(to_string(x) + ' ' + to_string(r) + ' ' + to_string(c));
}

void make_immediate_moves() {
    for (int row = 2; row <= 3; row++) {
        int park_row = row == 2 ? 1 : 4;

        for (int i = 1; i <= N; i++)
            if (grid[row][i] > 0 && grid[row][i] == grid[park_row][i]) {
                add_to_answer(grid[row][i], park_row, i);
                grid[row][i] = 0;
            }
    }
}

bool grid_is_full() {
    for (int i = 1; i <= N; i++)
        if (grid[2][i] == 0 || grid[3][i] == 0)
            return false;

    return true;
}

bool grid_is_empty() {
    for (int i = 1; i <= N; i++)
        if (grid[2][i] > 0 || grid[3][i] > 0)
            return false;

    return true;
}

void make_ring() {
    for (int i = 1; i <= N; i++)
        ring.emplace_back(2, i);

    for (int i = N; i >= 1; i--)
        ring.emplace_back(3, i);

    ring.push_back(ring[0]);
}

void cycle_grid(int index) {
    int r = ring[index].first, c = ring[index].second;
    int new_r = ring[index + 1].first, new_c = ring[index + 1].second;

    if (grid[r][c] > 0 && grid[new_r][new_c] == 0) {
        add_to_answer(grid[r][c], new_r, new_c);
        swap(grid[r][c], grid[new_r][new_c]);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> K;

    for (int row = 1; row <= 4; row++)
        for (int i = 1; i <= N; i++)
            cin >> grid[row][i];

    make_immediate_moves();

    if (grid_is_full()) {
        cout << -1 << '\n';
        return 0;
    }

    make_ring();
    int iteration = 0;

    while (!grid_is_empty()) {
        cycle_grid(iteration % (2 * N));
        make_immediate_moves();
        iteration++;
    }

    cout << answer.size() << '\n';

    for (string move : answer)
        cout << move << '\n';

    return 0;
}
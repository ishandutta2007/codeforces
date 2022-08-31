#include <algorithm>
#include <cassert>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

char to_char(int x) {
    if (x < 10)
        return '0' + x;

    x -= 10;

    if (x < 26)
        return 'a' + x;

    x -= 26;
    assert(x < 26);
    return 'A' + x;
}

int R, C, K;
vector<string> grid;

void solve_case() {
    cin >> R >> C >> K;
    grid.resize(R);

    for (string &row : grid)
        cin >> row;

    int rice = 0;

    for (int r = 0; r < R; r++)
        for (int c = 0; c < C; c++)
            rice += grid[r][c] == 'R' ? 1 : 0;

    vector<int> amounts(K, 0);

    for (int k = 0; k < K; k++)
        amounts[k] = (rice + k) / K;

    int current = 0, current_count = 0;
    vector<string> answer = grid;

    for (int r = 0; r < R; r++) {
        int direction = r % 2 == 0 ? +1 : -1;
        int start, end;

        if (direction == +1) {
            start = 0;
            end = C;
        } else {
            start = C - 1;
            end = -1;
        }

        for (int c = start; c != end; c += direction) {
            answer[r][c] = to_char(current);

            if (grid[r][c] == 'R') {
                current_count++;

                if (current_count == amounts[current]) {
                    current = min(current + 1, K - 1);
                    current_count = 0;
                }
            }
        }
    }

    for (int r = 0; r < R; r++)
        cout << answer[r] << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T-- > 0)
        solve_case();
}
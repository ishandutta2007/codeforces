#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

const int N_MAX = 2005;

int N, K;
char matrix[N_MAX][N_MAX];
short most_a[N_MAX][N_MAX];
bool seen[N_MAX][N_MAX];

template<typename T1, typename T2>
void maximize(T1 &a, T2 b) {
    if (b > a)
        a = b;
}

int main() {
    scanf("%d %d", &N, &K);

    for (int i = 0; i < N; i++)
        scanf("%s", matrix[i]);

    for (int r = 0; r <= N; r++)
        for (int c = 0; c <= N; c++) {
            most_a[r][c] = 0;

            if (r > 0)
                maximize(most_a[r][c], most_a[r - 1][c] + (matrix[r - 1][c] == 'a' ? 1 : 0));

            if (c > 0)
                maximize(most_a[r][c], most_a[r][c - 1] + (matrix[r][c - 1] == 'a' ? 1 : 0));
        }

    // Handle all a's.
    if (most_a[N][N] + K >= 2 * N - 1) {
        cout << string(2 * N - 1, 'a') << '\n';
        return 0;
    }

    int most = 0;
    vector<pair<int, int>> locations;

    for (int r = 0; r < N; r++)
        for (int c = 0; c < N; c++)
            if (matrix[r][c] != 'a' && most_a[r][c] + K == r + c) {
                if (r + c > most) {
                    most = r + c;
                    locations = {{r, c}};
                } else if (r + c == most) {
                    locations.emplace_back(r, c);
                }
            }

    string answer(most, 'a');

    while (!locations.empty()) {
        char least_char = 'z';

        for (auto &p : locations)
            least_char = min(least_char, matrix[p.first][p.second]);

        answer += least_char;
        vector<pair<int, int>> next_locations;

        for (auto &p : locations)
            if (matrix[p.first][p.second] == least_char) {
                if (p.first + 1 < N && !seen[p.first + 1][p.second]) {
                    next_locations.emplace_back(p.first + 1, p.second);
                    seen[p.first + 1][p.second] = true;
                }

                if (p.second + 1 < N && !seen[p.first][p.second + 1]) {
                    next_locations.emplace_back(p.first, p.second + 1);
                    seen[p.first][p.second + 1] = true;
                }

                seen[p.first][p.second] = true;
            }

        locations = next_locations;
    }

    cout << answer << '\n';
}
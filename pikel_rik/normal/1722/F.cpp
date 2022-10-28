#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    constexpr int di[] = {1, -1, 0, 0};
    constexpr int dj[] = {0, 0, 1, -1};

    while (t--) {
        int n, m;
        cin >> n >> m;

        vector<string> grid(n);
        for (auto &row : grid) cin >> row;

        auto is_okay = [&](int i, int j) -> bool {
            return 0 <= i && i < n && 0 <= j && j < m;
        };

        vector<vector<bool>> visited(n, vector<bool>(m));
        auto dfs = [&](int i, int j, auto &&self) -> int {
            visited[i][j] = true;
            int sz = 1;
            for (int k = 0; k < 4; k++) {
                int ni = i + di[k], nj = j + dj[k];
                if (is_okay(ni, nj) && grid[ni][nj] == '*' && !visited[ni][nj]) {
                    sz += self(ni, nj, self);
                }
            }
            return sz;
        };

        bool all_three = true;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == '*' && !visited[i][j]) {
                    all_three &= dfs(i, j, dfs) == 3;
                }
            }
        }

        if (!all_three) {
            cout << "NO\n";
            continue;
        }

        bool row_three = false;
        for (const auto &row : grid) {
            for (int j = 2; j < m; j++) {
                if (row[j - 2] == '*' && row[j - 2] == row[j - 1] && row[j - 1] == row[j]) {
                    row_three = true;
                    break;
                }
            }
        }

        if (row_three) {
            cout << "NO\n";
            continue;
        }

        bool col_three = false;
        for (int i = 2; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i - 2][j] == '*' && grid[i - 1][j] == '*' && grid[i][j] == '*') {
                    col_three = true;
                    break;
                }
            }
        }

        if (col_three) {
            cout << "NO\n";
            continue;
        }

        bool corner = false;
        for (int i = 1; i < n; i++) {
            for (int j = 1; j < m; j++) {
                if (grid[i - 1][j - 1] == '*' && grid[i][j] == '*' && grid[i - 1][j] != '*' && grid[i][j - 1] != '*') {
                    corner = true;
                    break;
                }
                if (grid[i - 1][j] == '*' && grid[i][j - 1] == '*' && grid[i - 1][j - 1] != '*' && grid[i][j] != '*') {
                    corner = true;
                    break;
                }
            }
        }

        cout << (corner ? "NO" : "YES") << '\n';
    }
    return 0;
}
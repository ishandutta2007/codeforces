#include <bits/stdc++.h>
using namespace std;
int C, R, N, grid[10][55];
vector<pair<int, pair<int, int>>> ans;
int main() {
    cin >> C >> N;
    R = 4;
    for (int i = 1; i <= R; i++) {
        for (int j = 1; j <= C; j++) {
            cin >> grid[i][j];
        }
    }
    int spin = 2 * C + 5;
    while (spin--) {
        for (int i = 2; i <= 3; i++) {
            for (int j = 1; j <= C; j++) {
                if (grid[i][j] == 0) continue;
                if (i == 2) {
                    if (grid[i][j] == grid[i - 1][j]) {
                        ans.push_back({grid[i][j], {i - 1, j}});
                        grid[i][j] = 0;
                    }
                } else {
                    if (grid[i][j] == grid[i + 1][j]) {
                        ans.push_back({grid[i][j], {i + 1, j}});
                        grid[i][j] = 0;
                    }
                }
            }
        }
        bool swapped = false, vis[10][55];
        int zero = 0;
        for (int i = 2; i <= 3; i++) {
            for (int j = 1; j <= C; j++) {
                if (grid[i][j] == 0) zero++;
            }
        }
        memset(vis, 0, sizeof(vis));
        for (int k = 1; k <= 105; k++) {
            for (int i = 2; i <= 3; i++) {
                for (int j = 1; j <= C; j++) {
                    if (vis[i][j]) continue;
                    if (i == 2) {
                        if (j == 1) {
                            if (grid[i + 1][j] == 0 && grid[i][j] != 0) {
                                swap(grid[i][j], grid[i + 1][j]);
                                ans.push_back({grid[i + 1][j], {i + 1, j}});
                                swapped = true;
                                vis[i + 1][j] = true;
                            }
                        } else {
                            if (grid[i][j - 1] == 0 && grid[i][j] != 0) {
                                swap(grid[i][j], grid[i][j - 1]);
                                ans.push_back({grid[i][j - 1], {i, j - 1}});
                                swapped = true;
                                vis[i][j - 1] = true;
                            }
                        }
                    } else {
                        if (j == C) {
                            if (grid[i - 1][j] == 0 && grid[i][j] != 0) {
                                swap(grid[i][j], grid[i - 1][j]);
                                ans.push_back({grid[i - 1][j], {i - 1, j}});
                                swapped = true;
                                vis[i - 1][j] = true;
                            }
                        } else {
                            if (grid[i][j + 1] == 0 && grid[i][j] != 0) {
                                swap(grid[i][j], grid[i][j + 1]);
                                ans.push_back({grid[i][j + 1], {i, j + 1}});
                                swapped = true;
                                vis[i][j + 1] = true;
                            }
                        }
                    }
                }
            }
        }
        if (!swapped && zero == 2 * C) {
            cout << ans.size() << "\n";
            for (auto i : ans) {
                cout << i.first << " " << i.second.first << " " << i.second.second << "\n";
            }
            return 0;
        }
        if (!swapped) {
            cout << "-1\n";
            return 0;
        }
    }
}
#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, k, r, c;
        cin >> n >> k >> r >> c;
        --r, --c;

        vector<string> grid(n, string(n, '.'));
        for (int i = 0; i < n; i += k) {
            for (int j = 0; j < n; j += k) {
                for (int kk = 0; kk < k && i + kk < n && j + kk < n; kk++) {
                    grid[i + kk][j + kk] = 'X';
                }
            }
        }

        vector<string> answer(n, string(n, '.'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 'X') {
                    answer[(i + r) % n][(j + c) % n] = 'X';
                }
            }
        }

        for (const auto &row : answer) {
            cout << row << '\n';
        }
    }
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int n, q;
    cin >> n >> q;
    vector<vector<int>> grid(2, vector<int>(n, 0));
    int cc = 0;

    for (int qi = 0; qi < q; qi++) {
        int r, c;
        cin >> r >> c;
        r--, c--;
        if (grid[r][c] == 0) {
            grid[r][c] = 1;
            for (int i = max(0, c - 1); i <= min(n - 1, c + 1); i++) {
                if (grid[1 - r][i] == 1) {
                    cc++;
                }
            }
        } else {
            grid[r][c] = 0;
            for (int i = max(0, c - 1); i <= min(n - 1, c + 1); i++) {
                if (grid[1 - r][i] == 1) {
                    cc--;
                }
            }
        }
        if (cc == 0) {
            cout << "Yes\n";
        } else {
            cout << "No\n";
        }
    }
}
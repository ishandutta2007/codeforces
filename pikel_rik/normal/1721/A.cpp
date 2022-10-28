#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        vector<string> grid(2);
        for (auto &row : grid) cin >> row;

        array<char, 26> freq = {};
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                freq[grid[i][j] - 'a'] += 1;
            }
        }

        int cnt = (int) count(freq.begin(), freq.end(), 4);
        if (cnt == 1) {
            cout << "0\n";
            continue;
        }

        cnt = (int) count(freq.begin(), freq.end(), 3);
        if (cnt == 1) {
            cout << "1\n";
            continue;
        }

        cnt = (int) count(freq.begin(), freq.end(), 2);
        if (cnt == 2) {
            cout << "1\n";
        } else if (cnt == 1) {
            cout << "2\n";
        } else {
            cout << "3\n";
        }
    }
    return 0;
}
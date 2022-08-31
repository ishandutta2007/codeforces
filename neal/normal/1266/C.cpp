#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int R, C;
    cin >> R >> C;

    if (R == 1 && C == 1) {
        cout << 0 << '\n';
        return 0;
    }

    vector<int> row(R, -1), col(C, -1);

    if (R < C) {
        for (int r = 0; r < R; r++)
            row[r] = r + 1;

        for (int c = 0; c < C; c++)
            col[c] = R + c + 1;
    } else {
        for (int r = 0; r < R; r++)
            row[r] = C + r + 1;

        for (int c = 0; c < C; c++)
            col[c] = c + 1;
    }

    for (int r = 0; r < R; r++)
        for (int c = 0; c < C; c++)
            cout << row[r] * col[c] << (c < C - 1 ? ' ' : '\n');
}
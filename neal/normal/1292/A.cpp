#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, Q;
    cin >> N >> Q;
    int bad_count = 0;
    vector<vector<bool>> lava(2, vector<bool>(N + 2, false));

    for (int q = 0; q < Q; q++) {
        int r, c;
        cin >> r >> c;
        r--;
        int sign = lava[r][c] ? -1 : +1;
        lava[r][c] = !lava[r][c];

        if (lava[!r][c - 1])
            bad_count += sign;

        if (lava[!r][c])
            bad_count += sign;

        if (lava[!r][c + 1])
            bad_count += sign;

        cout << (bad_count == 0 ? "Yes" : "No") << '\n';
    }
}
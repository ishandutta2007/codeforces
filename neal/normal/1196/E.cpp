#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int ADD;

void output(int row, int col) {
    cout << row + ADD << ' ' << col << '\n';
}

void solve_case() {
    int B, W;
    cin >> B >> W;
    ADD = 0;

    if (B < W) {
        swap(B, W);
        ADD = 1;
    }

    if (B > 3 * W + 1) {
        cout << "NO" << '\n';
        return;
    }

    cout << "YES" << '\n';

    for (int i = 1; i <= 2 * W; i++)
        output(i, 2);

    B -= W;

    if (B > 0) {
        output(2 * W + 1, 2);
        B--;
    }

    for (int i = 1; i <= B && i <= W; i++)
        output(2 * i, 3);

    B -= W;

    for (int i = 1; i <= B && i <= W; i++)
        output(2 * i, 1);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int Q;
    cin >> Q;

    while (Q-- > 0)
        solve_case();
}
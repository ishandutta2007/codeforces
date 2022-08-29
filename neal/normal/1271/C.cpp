#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, SX, SY;
    cin >> N >> SX >> SY;
    int x0 = 0, x1 = 0, y0 = 0, y1 = 0;

    for (int i = 0; i < N; i++) {
        int x, y;
        cin >> x >> y;
        x0 += x < SX;
        x1 += x > SX;
        y0 += y < SY;
        y1 += y > SY;
    }

    int answer = max({x0, x1, y0, y1});
    cout << answer << '\n';

    if (answer == x0)
        cout << SX - 1 << ' ' << SY << '\n';
    else if (answer == x1)
        cout << SX + 1 << ' ' << SY << '\n';
    else if (answer == y0)
        cout << SX << ' ' << SY - 1 << '\n';
    else if (answer == y1)
        cout << SX << ' ' << SY + 1 << '\n';
    else
        assert(false);
}
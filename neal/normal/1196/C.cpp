#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

const int INF = 1e5;

void solve_case() {
    int N;
    cin >> N;

    int x_min = -INF, x_max = INF;
    int y_min = -INF, y_max = INF;

    for (int i = 0; i < N; i++) {
        int x, y, f1, f2, f3, f4;
        cin >> x >> y >> f1 >> f2 >> f3 >> f4;

        if (f1 == 0)
            x_min = max(x_min, x);

        if (f2 == 0)
            y_max = min(y_max, y);

        if (f3 == 0)
            x_max = min(x_max, x);

        if (f4 == 0)
            y_min = max(y_min, y);
    }

    if (x_min <= x_max && y_min <= y_max) {
        cout << 1 << ' ' << x_min << ' ' << y_min << '\n';
    } else {
        cout << 0 << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int Q;
    cin >> Q;

    while (Q-- > 0)
        solve_case();
}
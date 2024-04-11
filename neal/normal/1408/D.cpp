#include <algorithm>
#include <array>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

const int INF = 1e9 + 5;
const int X_MAX = 1e6 + 5;

int main() {
    ios::sync_with_stdio(false);
#ifndef NEAL_DEBUG
    cin.tie(nullptr);
#endif

    int N, M;
    cin >> N >> M;
    vector<array<int, 2>> robbers(N);
    vector<array<int, 2>> lights(M);

    for (auto &xy : robbers)
        cin >> xy[0] >> xy[1];

    for (auto &xy : lights)
        cin >> xy[0] >> xy[1];

    vector<int> need_y(X_MAX + 1, 0);

    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++) {
            int x_diff = lights[j][0] - robbers[i][0];
            int y_diff = lights[j][1] - robbers[i][1];

            // If dx <= x_diff, dy must be > y_diff
            if (x_diff >= 0 && y_diff >= 0)
                need_y[x_diff] = max(need_y[x_diff], y_diff + 1);
        }

    // Compute suffix maxes.
    for (int x = X_MAX - 1; x >= 0; x--)
        need_y[x] = max(need_y[x], need_y[x + 1]);

    int best = INF;

    for (int x = 0; x <= X_MAX; x++)
        best = min(best, x + need_y[x]);

    cout << best << '\n';
}
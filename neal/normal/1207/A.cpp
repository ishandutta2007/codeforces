#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

void solve_case() {
    int B, P, F, H, C;
    cin >> B >> P >> F >> H >> C;
    int best = 0;

    for (int h = 0; h <= P; h++)
        for (int c = 0; c <= F; c++)
            if (h <= P && c <= F && 2 * h + 2 * c <= B)
                best = max(best, h * H + c * C);

    cout << best << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T-- > 0)
        solve_case();
}
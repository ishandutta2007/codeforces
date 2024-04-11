#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

const int INF = 1e9 + 5;

void solve_case() {
    int N, X;
    cin >> N >> X;
    int biggest = -INF, biggest_diff = -INF;

    for (int i = 0; i < N; i++) {
        int D, H;
        cin >> D >> H;
        biggest = max(biggest, D);
        biggest_diff = max(biggest_diff, D - H);
    }

    if (biggest >= X) {
        cout << 1 << '\n';
        return;
    }

    if (biggest_diff <= 0) {
        cout << -1 << '\n';
        return;
    }

    cout << (X - biggest + biggest_diff - 1) / biggest_diff + 1 << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T-- > 0)
        solve_case();
}
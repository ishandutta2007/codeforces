#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

void solve_case() {
    long long C, M, X;
    cin >> C >> M >> X;

    long long low = 0, high = min(C, M);

    while (low < high) {
        long long mid = (low + high + 1) / 2;

        bool possible = C >= mid && M >= mid && X + (C - mid) + (M - mid) >= mid;

        if (possible)
            low = mid;
        else
            high = mid - 1;
    }

    cout << low << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int Q;
    cin >> Q;

    while (Q-- > 0)
        solve_case();
}
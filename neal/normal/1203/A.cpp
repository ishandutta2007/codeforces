#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

void solve_case() {
    int N;
    cin >> N;
    vector<int> P(N);

    for (int &p : P)
        cin >> p;

    int one = find(P.begin(), P.end(), 1) - P.begin();
    bool clockwise = true, counterclockwise = true;

    for (int i = 0; i < N; i++) {
        if (P[(one + i) % N] != i + 1)
            clockwise = false;

        if (P[(one + N - i) % N] != i + 1)
            counterclockwise = false;
    }

    cout << (clockwise || counterclockwise ? "YES" : "NO") << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int Q;
    cin >> Q;

    while (Q-- > 0)
        solve_case();
}
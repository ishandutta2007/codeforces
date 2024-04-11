#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

void solve_case() {
    int S, I, E;
    cin >> S >> I >> E;
    int difference = S - I;

    if (difference + E <= 0) {
        cout << 0 << '\n';
        return;
    }

    int minimum = max(1 - difference, -E);

    if (abs(minimum) % 2 != E % 2)
        minimum++;

    int maximum = E;
    cout << (maximum - minimum) / 2 + 1 << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T-- > 0)
        solve_case();
}
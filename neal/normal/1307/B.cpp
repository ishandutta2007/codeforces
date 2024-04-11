#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int N, X;

void run_case() {
    cin >> N >> X;
    bool exact = false;
    int biggest = 0;

    for (int i = 0; i < N; i++) {
        int a;
        cin >> a;

        if (a == X)
            exact = true;

        biggest = max(biggest, a);
    }

    if (exact)
        cout << 1 << '\n';
    else
        cout << max((X + biggest - 1) / biggest, 2) << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tests;
    cin >> tests;

    while (tests-- > 0)
        run_case();
}
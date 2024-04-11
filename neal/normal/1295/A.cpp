#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

void run_case() {
    int N;
    cin >> N;

    if (N % 2 != 0) {
        cout << '7';
        N -= 3;
    }

    cout << string(N / 2, '1') << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tests;
    cin >> tests;

    while (tests-- > 0)
        run_case();
}
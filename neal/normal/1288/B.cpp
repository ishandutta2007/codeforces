#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

void run_case() {
    long long A, B;
    cin >> A >> B;
    long long total = 0;

    for (long long x = 9; x <= B; x = 10 * x + 9)
        total += A;

    cout << total << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tests;
    cin >> tests;

    while (tests-- > 0)
        run_case();
}
#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

void run_case() {
    long long N, D;
    cin >> N >> D;
    long long best = D;

    for (long long x = 1; ; x++) {
        long long option = x + (D + x) / (x + 1);

        if (option <= best)
            best = option;
        else
            break;
    }

    cout << (best <= N ? "YES" : "NO") << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tests;
    cin >> tests;

    while (tests-- > 0)
        run_case();
}
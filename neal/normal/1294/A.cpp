#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

void run_case() {
    long long A, B, C, N;
    cin >> A >> B >> C >> N;

    if ((A + B + C + N) % 3 != 0 || N < 3 * max({A, B, C}) - (A + B + C))
        cout << "NO" << '\n';
    else
        cout << "YES" << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tests;
    cin >> tests;

    while (tests-- > 0)
        run_case();
}
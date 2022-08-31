#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

void run_case() {
    long long X, Y, A, B;
    cin >> X >> Y >> A >> B;

    if ((Y - X) % (A + B) == 0)
        cout << (Y - X) / (A + B) << '\n';
    else
        cout << -1 << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tests;
    cin >> tests;

    while (tests-- > 0)
        run_case();
}
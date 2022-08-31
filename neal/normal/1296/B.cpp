#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

void run_case() {
    long long S;
    cin >> S;
    long long spent = 0;

    while (S >= 10) {
        long long extra = S % 10;
        spent += S - extra;
        S = S / 10 + extra;
    }

    spent += S;
    cout << spent << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tests;
    cin >> tests;

    while (tests-- > 0)
        run_case();
}
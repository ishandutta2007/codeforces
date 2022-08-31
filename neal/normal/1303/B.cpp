#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

void run_case() {
    long long N, G, B;
    cin >> N >> G >> B;
    long long need = (N + 1) / 2;
    long long full = (need - 1) / G;
    long long extra = need - full * G;
    long long answer = full * (G + B) + extra;
    answer = max(answer, N);
    cout << answer << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tests;
    cin >> tests;

    while (tests-- > 0)
        run_case();
}
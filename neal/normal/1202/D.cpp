#include <algorithm>
#include <cassert>
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

void run_case() {
    long long N;
    cin >> N;

    long long threes = max(2LL, (long long) round(pow(4 * N, 1.0 / 3)));
    vector<long long> sevens(threes + 1, 0);

    for (long long t = threes; t >= 2; t--) {
        long long each = t * (t - 1) / 2;
        sevens[t] = N / each;
        N %= each;
    }

    cout << '1';

    for (long long t = 1; t <= threes; t++)
        cout << '3' << string(sevens[t], '7');

    cout << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tests;
    cin >> tests;

    while (tests-- > 0)
        run_case();
}
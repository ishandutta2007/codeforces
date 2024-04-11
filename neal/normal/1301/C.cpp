#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

void run_case() {
    long long N, M;
    cin >> N >> M;
    long long Z = N - M;
    long long sections = M + 1;
    long long low = Z / sections;
    long long high = (Z + sections - 1) / sections;
    long long high_count = Z % sections;
    long long low_count = sections - high_count;
    long long bad_pairs = low * (low + 1) / 2 * low_count + high * (high + 1) / 2 * high_count;
    long long all_pairs = N * (N + 1) / 2;
    cout << all_pairs - bad_pairs << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tests;
    cin >> tests;

    while (tests-- > 0)
        run_case();
}
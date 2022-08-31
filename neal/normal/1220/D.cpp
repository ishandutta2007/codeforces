#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    vector<long long> B(N);
    vector<int> counts(64, 0);

    for (long long &b : B) {
        cin >> b;
        counts[__builtin_ctzll(b)]++;
    }

    int most = 0;

    for (int bits = 0; bits < 64; bits++)
        if (counts[bits] > counts[most])
            most = bits;

    int erased = N - counts[most];
    cout << erased << '\n';

    for (long long b : B)
        if (__builtin_ctzll(b) != most)
            cout << b << (--erased > 0 ? ' ' : '\n');
}
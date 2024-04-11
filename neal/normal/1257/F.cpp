#include <algorithm>
#include <cassert>
#include <iostream>
#include <map>
#include <vector>
using namespace std;

const int BITS = 30;
const int HALF = BITS / 2;

int N;
vector<int> A;

void normalize(vector<int> &counts) {
    assert((int) counts.size() == N);

    for (int i = N - 1; i >= 0; i--)
        counts[i] -= counts[0];
}

int main() {
    cin >> N;
    A.resize(N);

    for (auto &a : A)
        cin >> a;

    map<vector<int>, int> possible;

    for (int mask = 0; mask < 1 << HALF; mask++) {
        vector<int> counts(N, 0);

        for (int i = 0; i < N; i++)
            counts[i] = __builtin_popcount((A[i] & ((1 << HALF) - 1)) ^ mask);

        normalize(counts);

        if (possible.find(counts) == possible.end())
            possible[counts] = mask;
    }

    for (int mask = 0; mask < 1 << HALF; mask++) {
        vector<int> counts(N, 0);

        for (int i = 0; i < N; i++)
            counts[i] = __builtin_popcount(A[i] >> HALF ^ mask);

        normalize(counts);

        for (int i = 0; i < N; i++)
            counts[i] = -counts[i];

        if (possible.find(counts) != possible.end()) {
            int other = possible[counts];
            cout << (mask << HALF) + other << '\n';
            return 0;
        }
    }

    cout << -1 << '\n';
}
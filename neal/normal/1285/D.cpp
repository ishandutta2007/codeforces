#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

const int BITS = 30;

int N;
vector<int> A;

int solve(int start, int end, int bit, int prefix) {
    assert(start < end);

    if (bit < 0)
        return prefix;

    int half = start;

    while (half < end && (A[half] >> bit & 1) == 0)
        half++;

    if (half == start || half == end)
        return solve(start, end, bit - 1, prefix);

    prefix |= 1 << bit;
    return min(solve(start, half, bit - 1, prefix), solve(half, end, bit - 1, prefix));
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    A.resize(N);

    for (auto &a : A)
        cin >> a;

    sort(A.begin(), A.end());
    cout << solve(0, N, BITS - 1, 0) << '\n';
}
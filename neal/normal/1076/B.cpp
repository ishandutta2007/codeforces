#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

long long smallest_factor(long long N) {
    for (long long p = 2; p * p <= N; p++)
        if (N % p == 0)
            return p;

    return N;
}

int main() {
    long long N;
    cin >> N;
    N -= smallest_factor(N);
    assert(N % 2 == 0);
    cout << N / 2 + 1 << '\n';
}
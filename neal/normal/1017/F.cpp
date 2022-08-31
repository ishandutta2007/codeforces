#include <algorithm>
#include <bitset>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

const int SIEVE = 18000;
const int SEGMENT_SIZE = 1e6 + 5;

int N;
unsigned A, B, C, D;
bitset<SEGMENT_SIZE> is_prime;
bitset<SIEVE> sieve_prime;

unsigned f(unsigned x) {
    return D + x * (C + x * (B + x * A));
}

unsigned contribution(unsigned p) {
    unsigned count = 0;
    unsigned n = N;

    while (n >= p) {
        n /= p;
        count += n;
    }

    return count * f(p);
}

long long steps = 0;

void initial_sieve() {
    sieve_prime.set();
    sieve_prime[0] = sieve_prime[1] = 0;

    for (int p = 2; p < SIEVE; p++)
        if (sieve_prime[p])
            for (int x = 2 * p; x < SIEVE; x += p)
                sieve_prime[x] = 0;
}

void segment_sieve(int offset) {
    is_prime.set();

    if (0 >= offset)
        is_prime[-offset] = 0;

    if (1 >= offset)
        is_prime[1 - offset] = 0;

    for (int p = 2; p < SIEVE; p++)
        if (sieve_prime[p]) {
            int start = max(offset, 2 * p);
            int remainder = start % p;
            start = remainder == 0 ? start : start + p - remainder;

            for (int x = start - offset; x < SEGMENT_SIZE; x += p) {
                is_prime[x] = 0;
                steps++;
            }
        }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> A >> B >> C >> D;
    initial_sieve();
    unsigned total = 0;

    for (int iter = 0; iter * SEGMENT_SIZE <= N; iter++) {
        int offset = iter * SEGMENT_SIZE;
        segment_sieve(offset);

        for (int i = offset; i < offset + SEGMENT_SIZE; i++)
            if (is_prime[i - offset])
                total += contribution(i);
    }

    cout << total << '\n';
    cerr << steps << '\n';
    return 0;
}
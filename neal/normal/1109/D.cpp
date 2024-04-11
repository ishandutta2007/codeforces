#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

const int MOD = 1e9 + 7;

inline int mod_add(int a, int b, int m = MOD) {
    int sum = a + b;
    return sum >= m ? sum - m : sum;
}

inline int mod_sub(int a, int b, int m = MOD) {
    int diff = a - b;
    return diff < 0 ? diff + m : diff;
}

inline unsigned fast_mod(uint64_t x, unsigned m = MOD) {
#if !defined(_WIN32) || defined(_WIN64)
    return x % m;
#endif
    // Optimized mod for Codeforces 32-bit machines.
    // x must be less than 2^32 * m for this to work, so that x / m fits in a 32-bit integer.
    unsigned x_high = x >> 32, x_low = (unsigned) x;
    unsigned quot, rem;
    assert(x_high < m);
    asm("divl %4\n"
        : "=a" (quot), "=d" (rem)
        : "d" (x_high), "a" (x_low), "r" (m));
    return rem;
}

inline int mod_mul(int a, int b, int m = MOD) {
    return fast_mod((uint64_t) a * b, m);
}

inline int mod_pow(int a, long long p, int m = MOD) {
    assert(p >= 0);
    int result = 1;

    while (p > 0) {
        if (p & 1)
            result = mod_mul(result, a, m);

        a = mod_mul(a, a, m);
        p >>= 1;
    }

    return result;
}

inline int mod_inv(int a, int m = MOD) {
    // https://en.wikipedia.org/wiki/Extended_Euclidean_algorithm#Example
    int g = m, r = a, x = 0, y = 1;

    while (r != 0) {
        int q = g / r;
        g %= r; swap(g, r);
        x -= q * y; swap(x, y);
    }

    assert(g == 1);
    assert(y == m || y == -m);
    return x < 0 ? x + m : x;
}

// Note: these are stored as int to save memory, but beware of overflow.
vector<int> factorial, inv_factorial;
vector<int> inv;

void prepare_factorials(int max) {
    inv.assign(max + 1, 1);

    // Make sure MOD is prime, which is necessary for the inverse algorithm below.
    for (int p = 2; p * p <= MOD; p++)
        assert(MOD % p != 0);

    for (int i = 2; i <= max; i++)
        inv[i] = mod_mul(inv[MOD % i], MOD - MOD / i);

    factorial.resize(max + 1);
    inv_factorial.resize(max + 1);
    factorial[0] = inv_factorial[0] = 1;

    for (int i = 1; i <= max; i++) {
        factorial[i] = mod_mul(i, factorial[i - 1]);
        inv_factorial[i] = mod_mul(inv[i], inv_factorial[i - 1]);
    }
}

long long choose(int n, int r) {
    assert(0 <= r && r <= n);
    return mod_mul(factorial[n], mod_mul(inv_factorial[r], inv_factorial[n - r]));
}

int main() {
    int N, M;
    cin >> N >> M;
    prepare_factorials(max(N, M) + 5);
    vector<int> n_powers(N, 1), m_powers(N, 1);

    for (int i = 0; i + 1 < N; i++) {
        n_powers[i + 1] = mod_mul(n_powers[i], N);
        m_powers[i + 1] = mod_mul(m_powers[i], M);
    }

    int total = 0;

    for (int k = 2; k <= min(N, M + 1); k++) {
        int ways = mod_mul(factorial[N - 2], inv_factorial[N - k]);
        ways = mod_mul(ways, k == N ? 1 : mod_mul(k, n_powers[N - k - 1]));
        ways = mod_mul(ways, m_powers[N - k]);
        ways = mod_mul(ways, choose(M - 1, k - 2));
        total = mod_add(total, ways);
    }

    cout << total << '\n';
}
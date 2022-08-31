#include <algorithm>
#include <cassert>
#include <iostream>
#include <set>
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


const int MAX_EXPONENT = 60;

long long N, K;
int F;
vector<pair<int, int>> factors;
vector<int> probability[MAX_EXPONENT];
vector<int> inv;

int solve(int position, int prob, int value) {
    if (position >= F)
        return mod_mul(prob, value);

    int p = factors[position].first;
    int power = 1;
    int exponent = factors[position].second;
    int sum = 0;

    for (int e = 0; e <= exponent; e++) {
        sum = mod_add(sum, solve(position + 1, mod_mul(prob, probability[exponent][e]), mod_mul(value, power)));
        power = mod_mul(power, p);
    }

    return sum;
}

int main() {
    inv.resize(MAX_EXPONENT);

    for (int i = 1; i < MAX_EXPONENT; i++)
        inv[i] = mod_inv(i);

    cin >> N >> K;
    set<int> exponents;

    for (long long p = 2; p * p <= N; p++)
        if (N % p == 0) {
            int exponent = 0;

            do {
                N /= p;
                exponent++;
            } while (N % p == 0);

            factors.emplace_back(p % MOD, exponent);
            exponents.insert(exponent);
        }

    if (N > 1) {
        factors.emplace_back(N % MOD, 1);
        exponents.insert(1);
    }

    F = factors.size();

    for (int exponent : exponents) {
        vector<int> prob(exponent + 1, 0);
        prob[exponent] = 1;

        for (int k = 0; k < K; k++)
            for (int i = 0; i <= exponent; i++) {
                int add = mod_mul(prob[i], inv[i + 1]);

                for (int j = 0; j < i; j++)
                    prob[j] = mod_add(prob[j], add);

                prob[i] = add;
            }

        probability[exponent] = prob;
    }

    cout << solve(0, 1, 1) << '\n';
}
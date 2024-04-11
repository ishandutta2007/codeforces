#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

const int MOD = 1e9 + 7;

struct mod_int {
    int val;

    mod_int(long long v = 0) {
        if (v < 0)
            v = v % MOD + MOD;

        if (v >= MOD)
            v %= MOD;

        val = v;
    }

    static int mod_inv(int a, int m = MOD) {
        // https://en.wikipedia.org/wiki/Extended_Euclidean_algorithm#Example
        int g = m, r = a, x = 0, y = 1;

        while (r != 0) {
            int q = g / r;
            g %= r; swap(g, r);
            x -= q * y; swap(x, y);
        }

        return x < 0 ? x + m : x;
    }

    explicit operator int() const {
        return val;
    }

    mod_int& operator+=(const mod_int &other) {
        val += other.val;
        if (val >= MOD) val -= MOD;
        return *this;
    }

    mod_int& operator-=(const mod_int &other) {
        val -= other.val;
        if (val < 0) val += MOD;
        return *this;
    }

    static unsigned fast_mod(uint64_t x, unsigned m = MOD) {
#if !defined(_WIN32) || defined(_WIN64)
        return x % m;
#endif
        // Optimized mod for Codeforces 32-bit machines.
        // x must be less than 2^32 * m for this to work, so that x / m fits in a 32-bit integer.
        unsigned x_high = x >> 32, x_low = (unsigned) x;
        unsigned quot, rem;
        asm("divl %4\n"
            : "=a" (quot), "=d" (rem)
            : "d" (x_high), "a" (x_low), "r" (m));
        return rem;
    }

    mod_int& operator*=(const mod_int &other) {
        val = fast_mod((uint64_t) val * other.val);
        return *this;
    }

    mod_int& operator/=(const mod_int &other) {
        return *this *= other.inv();
    }

    friend mod_int operator+(const mod_int &a, const mod_int &b) { return mod_int(a) += b; }
    friend mod_int operator-(const mod_int &a, const mod_int &b) { return mod_int(a) -= b; }
    friend mod_int operator*(const mod_int &a, const mod_int &b) { return mod_int(a) *= b; }
    friend mod_int operator/(const mod_int &a, const mod_int &b) { return mod_int(a) /= b; }

    mod_int& operator++() {
        val = val == MOD - 1 ? 0 : val + 1;
        return *this;
    }

    mod_int& operator--() {
        val = val == 0 ? MOD - 1 : val - 1;
        return *this;
    }

    mod_int operator++(int) { mod_int before = *this; ++*this; return before; }
    mod_int operator--(int) { mod_int before = *this; --*this; return before; }

    mod_int operator-() const {
        return val == 0 ? 0 : MOD - val;
    }

    bool operator==(const mod_int &other) const { return val == other.val; }
    bool operator!=(const mod_int &other) const { return val != other.val; }

    mod_int inv() const {
        return mod_inv(val);
    }

    mod_int pow(long long p) const {
        assert(p >= 0);
        mod_int a = *this, result = 1;

        while (p > 0) {
            if (p & 1)
                result *= a;

            a *= a;
            p >>= 1;
        }

        return result;
    }
};

// Note: totient is also known as phi. See https://en.wikipedia.org/wiki/Euler%27s_totient_function
vector<int> smallest_factor;
vector<int> totient;
vector<mod_int> totient_sum;
vector<bool> prime;
vector<int> primes;

// Note: this sieve is O(n).
void sieve(int maximum) {
    maximum = max(maximum, 2);
    smallest_factor.assign(maximum + 1, 0);
    totient.assign(maximum + 1, 0);
    prime.assign(maximum + 1, true);
    totient[1] = 1;
    prime[0] = prime[1] = false;
    primes = {};

    for (int i = 2; i <= maximum; i++) {
        if (prime[i]) {
            smallest_factor[i] = i;
            totient[i] = i - 1;
            primes.push_back(i);
        }

        for (int p : primes) {
            if (p > smallest_factor[i] || i * p > maximum)
                break;

            prime[i * p] = false;
            smallest_factor[i * p] = p;
            totient[i * p] = (smallest_factor[i] == p ? p : p - 1) * totient[i];
        }
    }

    totient_sum.assign(maximum + 1, 0);

    for (int i = 1; i <= maximum; i++)
        totient_sum[i] = totient_sum[i - 1] + totient[i];
}


int main() {
    int N, K;
    cin >> N >> K;
    sieve(N);
    vector<mod_int> freq(N);

    // Add x + y - N for all pairs where it is >= 0.
    for (int i = 0; i < N; i++)
        freq[i] = N - 1 - i;

    for (int g = 1; g < N; g++) {
        // If gcd(x, y) = g > x + y - N >= 0, then x + y = N rounded up to a multiple of g.
        int v = (N + g - 1) / g;

        // totient[v] pairs need to be moved from x + y - N to gcd(x, y) = g.
        if (v > 1) {
            freq[v * g - N] -= totient[v];
            freq[g] += totient[v];
        }

        // Add gcd(x, y) for all pairs where x + y - N < 0. Subtract one because totient[1] = 1.
        freq[g] += totient_sum[(N - 1) / g] - 1;
    }

    reverse(freq.begin() + 1, freq.end());
    mod_int total = 0, pp = 1, inv_K = mod_int(1) / K;

    for (int p = 0; p < N; p++) {
        total += freq[p] * pp;
        pp *= inv_K;
    }

    cout << (int) total << '\n';
}
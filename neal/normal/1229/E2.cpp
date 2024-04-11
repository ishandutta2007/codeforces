#include <algorithm>
#include <cassert>
#include <chrono>
#include <iostream>
#include <vector>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;

auto random_address = [] { char *p = new char; delete p; return (uint64_t) p; };

struct safe_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    uint64_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = splitmix64(chrono::steady_clock::now().time_since_epoch().count() * (random_address() | 1));
        return splitmix64(x ^ FIXED_RANDOM);
    }
};

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


const int N_MAX = 7;

int N;
mod_int probability[N_MAX][N_MAX];

int main() {
    cin >> N;

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++) {
            int p;
            cin >> p;
            probability[i][j] = mod_int(p) / mod_int(100);
        }

    vector<vector<int>> masks_with_count(N_MAX + 1);
    vector<int> lookup(1 << N, -1);

    for (int mask = 0; mask < 1 << N; mask++) {
        int count = __builtin_popcount(mask);
        lookup[mask] = masks_with_count[count].size();
        masks_with_count[count].push_back(mask);
    }

    gp_hash_table<long long, mod_int, safe_hash> possible_masks;
    possible_masks[1 << lookup[0]] = 1;

    for (int left = 0; left < N; left++) {
        gp_hash_table<long long, mod_int, safe_hash> new_possible_masks;
        vector<mod_int> products(1 << N, 1);

        for (int current = 0; current < 1 << N; current++)
            for (int right = 0; right < N; right++)
                products[current] *= (current >> right & 1) ? probability[left][right] : 1 - probability[left][right];

        vector<long long> new_bits(N, 0);
        vector<long long> new_possible(1 << N, 0);

        for (auto &p : possible_masks) {
            long long possible = p.first;
            mod_int prob = p.second;

            new_bits.assign(N, 0);

            for (int mask : masks_with_count[left])
                if (possible >> lookup[mask] & 1)
                    for (int i = 0; i < N; i++)
                        if ((mask >> i & 1) == 0)
                            new_bits[i] |= 1LL << lookup[mask | 1 << i];

            new_possible[0] = 0;

            for (int current = 1; current < 1 << N; current++) {
                new_possible[current] = new_possible[current & (current - 1)] | new_bits[__builtin_ctz(current)];
                new_possible_masks[new_possible[current]] += prob * products[current];
            }
        }

        possible_masks = new_possible_masks;
        cerr << possible_masks.size() << endl;
    }

    mod_int answer = 0;

    for (auto &p : possible_masks)
        if (p.first >> lookup[(1 << N) - 1] & 1)
            answer += p.second;

    cout << (int) answer << '\n';
}
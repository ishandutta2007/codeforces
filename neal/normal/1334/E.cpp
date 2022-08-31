#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

template<typename T> ostream& operator<<(ostream &os, const vector<T> &v) { os << '{'; string sep; for (const auto &x : v) os << sep << x, sep = ", "; return os << '}'; }
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }

void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }

#ifdef NEAL_DEBUG
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif

template<const int &MOD>
struct _m_int {
    int val;

    _m_int(int64_t v = 0) {
        if (v < 0) v = v % MOD + MOD;
        if (v >= MOD) v %= MOD;
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

    explicit operator int() const { return val; }
    explicit operator int64_t() const { return val; }

    _m_int& operator+=(const _m_int &other) {
        val += other.val;
        if (val >= MOD) val -= MOD;
        return *this;
    }

    _m_int& operator-=(const _m_int &other) {
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

    _m_int& operator*=(const _m_int &other) {
        val = fast_mod((uint64_t) val * other.val);
        return *this;
    }

    _m_int& operator/=(const _m_int &other) {
        return *this *= other.inv();
    }

    friend _m_int operator+(const _m_int &a, const _m_int &b) { return _m_int(a) += b; }
    friend _m_int operator-(const _m_int &a, const _m_int &b) { return _m_int(a) -= b; }
    friend _m_int operator*(const _m_int &a, const _m_int &b) { return _m_int(a) *= b; }
    friend _m_int operator/(const _m_int &a, const _m_int &b) { return _m_int(a) /= b; }

    _m_int& operator++() {
        val = val == MOD - 1 ? 0 : val + 1;
        return *this;
    }

    _m_int& operator--() {
        val = val == 0 ? MOD - 1 : val - 1;
        return *this;
    }

    _m_int operator++(int) { _m_int before = *this; ++*this; return before; }
    _m_int operator--(int) { _m_int before = *this; --*this; return before; }

    _m_int operator-() const {
        return val == 0 ? 0 : MOD - val;
    }

    bool operator==(const _m_int &other) const { return val == other.val; }
    bool operator!=(const _m_int &other) const { return val != other.val; }

    _m_int inv() const {
        return mod_inv(val);
    }

    _m_int pow(int64_t p) const {
        if (p < 0)
            return inv().pow(-p);

        _m_int a = *this, result = 1;

        while (p > 0) {
            if (p & 1)
                result *= a;

            a *= a;
            p >>= 1;
        }

        return result;
    }

    friend ostream& operator<<(ostream &stream, const _m_int &m) {
        return stream << m.val;
    }
};

extern const int MOD = 998244353;
using mod_int = _m_int<MOD>;


vector<mod_int> inv, factorial, inv_factorial;
int prepared_maximum = -1;

void prepare_factorials(int maximum) {
    static int prepare_calls = 0;

    if (prepare_calls++ == 0) {
        // Make sure MOD is prime, which is necessary for the inverse algorithm below.
        for (int p = 2; p * p <= MOD; p += p % 2 + 1)
            assert(MOD % p != 0);

        inv = {0, 1};
        factorial = inv_factorial = {1, 1};
        prepared_maximum = 1;
    }

    if (maximum > prepared_maximum) {
        inv.resize(maximum + 1);
        factorial.resize(maximum + 1);
        inv_factorial.resize(maximum + 1);

        for (int i = prepared_maximum + 1; i <= maximum; i++) {
            inv[i] = inv[MOD % i] * (MOD - MOD / i);
            factorial[i] = i * factorial[i - 1];
            inv_factorial[i] = inv[i] * inv_factorial[i - 1];
        }

        prepared_maximum = maximum;
    }
}

mod_int get_factorial(int n) {
    prepare_factorials(n);
    return factorial[n];
}

mod_int get_inv(int n) {
    prepare_factorials(n);
    return inv[n];
}

mod_int get_inv_factorial(int n) {
    prepare_factorials(n);
    return inv_factorial[n];
}

mod_int choose(int64_t n, int64_t r) {
    if (r < 0 || r > n) return 0;
    prepare_factorials(n);
    return factorial[n] * inv_factorial[r] * inv_factorial[n - r];
}

mod_int inv_choose(int64_t n, int64_t r) {
    assert(0 <= r && r <= n);
    prepare_factorials(n);
    return inv_factorial[n] * factorial[r] * factorial[n - r];
}

mod_int permute(int64_t n, int64_t r) {
    if (r < 0 || r > n) return 0;
    prepare_factorials(n);
    return factorial[n] * inv_factorial[n - r];
}

mod_int inv_permute(int64_t n, int64_t r) {
    assert(0 <= r && r <= n);
    prepare_factorials(n);
    return inv_factorial[n] * factorial[n - r];
}


int main() {
    ios::sync_with_stdio(false);
#ifndef NEAL_DEBUG
    cin.tie(nullptr);
#endif

    int64_t D;
    int Q;
    cin >> D >> Q;
    vector<int64_t> primes;

    for (int64_t p = 2; p * p <= D; p += p % 2 + 1)
        if (D % p == 0) {
            primes.push_back(p);

            do {
                D /= p;
            } while (D % p == 0);
        }

    if (D > 1)
        primes.push_back(D);

    int N = primes.size();
    auto &&count_ways = [&](vector<int> diff) {
        mod_int ways = 1;
        int sum = 0;

        for (int d : diff) {
            ways *= get_inv_factorial(d);
            sum += d;
        }

        ways *= get_factorial(sum);
        return ways;
    };

    for (int q = 0; q < Q; q++) {
        int64_t u, v;
        cin >> u >> v;

        if (u > v)
            swap(u, v);

        vector<int> u_freq(N, 0), v_freq(N, 0);

        for (int i = 0; i < N; i++) {
            while (u % primes[i] == 0) {
                u /= primes[i];
                u_freq[i]++;
            }

            while (v % primes[i] == 0) {
                v /= primes[i];
                v_freq[i]++;
            }

            int least = min(u_freq[i], v_freq[i]);
            u_freq[i] -= least;
            v_freq[i] -= least;
        }

        cout << count_ways(u_freq) * count_ways(v_freq) << '\n';
    }
}
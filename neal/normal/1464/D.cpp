#include <algorithm>
#include <array>
#include <cassert>
#include <chrono>
#include <cmath>
#include <cstring>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <vector>
using namespace std;

template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }

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
        val = int(v);
    }

    _m_int(uint64_t v) {
        if (v >= MOD) v %= MOD;
        val = int(v);
    }

    _m_int(int v) : _m_int(int64_t(v)) {}
    _m_int(unsigned v) : _m_int(uint64_t(v)) {}

    explicit operator int() const { return val; }
    explicit operator unsigned() const { return val; }
    explicit operator int64_t() const { return val; }
    explicit operator uint64_t() const { return val; }
    explicit operator double() const { return val; }
    explicit operator long double() const { return val; }

    _m_int& operator+=(const _m_int &other) {
        val -= MOD - other.val;
        if (val < 0) val += MOD;
        return *this;
    }

    _m_int& operator-=(const _m_int &other) {
        val -= other.val;
        if (val < 0) val += MOD;
        return *this;
    }

    static unsigned fast_mod(uint64_t x, unsigned m = MOD) {
#if !defined(_WIN32) || defined(_WIN64)
        return unsigned(x % m);
#endif
        // Optimized mod for Codeforces 32-bit machines.
        // x must be less than 2^32 * m for this to work, so that x / m fits in an unsigned 32-bit int.
        unsigned x_high = unsigned(x >> 32), x_low = unsigned(x);
        unsigned quot, rem;
        asm("divl %4\n"
            : "=a" (quot), "=d" (rem)
            : "d" (x_high), "a" (x_low), "r" (m));
        return rem;
    }

    _m_int& operator*=(const _m_int &other) {
        val = fast_mod(uint64_t(val) * other.val);
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

    friend bool operator==(const _m_int &a, const _m_int &b) { return a.val == b.val; }
    friend bool operator!=(const _m_int &a, const _m_int &b) { return a.val != b.val; }
    friend bool operator<(const _m_int &a, const _m_int &b) { return a.val < b.val; }
    friend bool operator>(const _m_int &a, const _m_int &b) { return a.val > b.val; }
    friend bool operator<=(const _m_int &a, const _m_int &b) { return a.val <= b.val; }
    friend bool operator>=(const _m_int &a, const _m_int &b) { return a.val >= b.val; }

    static const int SAVE_INV = int(1e6) + 5;
    static _m_int save_inv[SAVE_INV];

    static void prepare_inv() {
        // Make sure MOD is prime, which is necessary for the inverse algorithm below.
        for (int64_t p = 2; p * p <= MOD; p += p % 2 + 1)
            assert(MOD % p != 0);

        save_inv[0] = 0;
        save_inv[1] = 1;

        for (int i = 2; i < SAVE_INV; i++)
            save_inv[i] = save_inv[MOD % i] * (MOD - MOD / i);
    }

    _m_int inv() const {
        if (save_inv[1] == 0)
            prepare_inv();

        if (val < SAVE_INV)
            return save_inv[val];

        _m_int product = 1;
        int v = val;

        while (v >= SAVE_INV) {
            product *= MOD - MOD / v;
            v = MOD % v;
        }

        return product * save_inv[v];
    }

    _m_int pow(int64_t p) const {
        if (p < 0)
            return inv().pow(-p);

        _m_int a = *this, result = 1;

        while (p > 0) {
            if (p & 1)
                result *= a;

            p >>= 1;

            if (p > 0)
                a *= a;
        }

        return result;
    }

    friend ostream& operator<<(ostream &os, const _m_int &m) {
        return os << m.val;
    }
};

template<const int &MOD> _m_int<MOD> _m_int<MOD>::save_inv[_m_int<MOD>::SAVE_INV];

extern const int MOD = int(1e9) + 7;
using mod_int = _m_int<MOD>;


const int INF = int(1e9) + 5;

mod_int get_product(int n) {
    mod_int product = 1;

    while (n % 3 != 0) {
        product *= 2;
        n -= 2;
    }

    while (n > 0) {
        product *= 3;
        n -= 3;
    }

    return product;
}

int solve12(int ones, int twos) {
    assert((ones + 2 * twos) % 3 == 0);
    int ops = 0;

    while (twos > ones) {
        twos--;
        ones += 2;
        ops++;
    }

    int combine = min(twos, ones);
    ops += combine;
    twos -= combine;
    ones -= combine;
    assert(twos == 0);
    ops += 2 * (ones / 3);
    return ops;
}

int solve22(vector<int> numbers) {
    int n = accumulate(numbers.begin(), numbers.end(), 0);
    assert(n % 3 == 1);

    int ops = 0;
    array<int, 3> counts = {0, 0, 0};

    for (int x : numbers) {
        while (x > 3) {
            x -= 3;
            ops++;
        }

        if (x <= 2)
            counts[x]++;
    }

    if (counts[1] == 1 && counts[2] == 0) {
        ops++;
        return ops;
    }

    assert(counts[1] + 2 * counts[2] >= 4);

    if (counts[2] >= 2) {
        counts[2] -= 2;
    } else if (counts[2] >= 1) {
        assert(counts[1] >= 2);
        counts[1] -= 2;
        counts[2]--;
        ops++;
    } else {
        assert(counts[1] >= 4);
        counts[1] -= 4;
        ops += 2;
    }

    ops += solve12(counts[1], counts[2]);
    return ops;
}

int solve_ops(vector<int> numbers);

int solve4(vector<int> numbers) {
    int n = accumulate(numbers.begin(), numbers.end(), 0);
    int s = int(numbers.size());
    vector<int> save_numbers = numbers;
    assert(n % 3 == 1);
    int ops = 0;
    int best = INF;

    for (int i = 0; i < s; i++) {
        int x = numbers[i];

        if (x >= 4 && x % 3 == 1) {
            ops += (x - 4) / 3;
            numbers.erase(numbers.begin() + i);
            best = min(best, ops + solve_ops(numbers));
            break;
        }
    }

    numbers = save_numbers;
    ops = 0;

    for (int i = 0; i < s; i++) {
        int x = numbers[i];

        if (x >= 5 && x % 3 == 2) {
            ops += (x - 5) / 3;
            ops++;
            numbers[i] = 1;
            best = min(best, ops + solve_ops(numbers));
            break;
        }
    }

    numbers = save_numbers;
    ops = 0;

    for (int i = 0; i < s; i++) {
        int x = numbers[i];

        if (x >= 6 && x % 3 == 0) {
            ops += (x - 6) / 3;
            ops++;
            numbers[i] = 2;
            best = min(best, ops + solve_ops(numbers));
            break;
        }
    }

    return best;
}

int solve_ops(vector<int> numbers) {
    int n = accumulate(numbers.begin(), numbers.end(), 0);

    if (n % 3 == 0 || n % 3 == 2) {
        int ops = 0;
        array<int, 3> counts = {0, 0, 0};

        for (int x : numbers) {
            while (x > 3) {
                x -= 3;
                ops++;
            }

            if (x <= 2)
                counts[x]++;
        }

        if (n % 3 == 2) {
            if (counts[2] > 0) {
                counts[2]--;
            } else {
                assert(counts[1] >= 2);
                counts[1] -= 2;
                ops++;
            }
        }

        ops += solve12(counts[1], counts[2]);
        return ops;
    }

    assert(n % 3 == 1);
    return min(solve22(numbers), solve4(numbers));
}

void run_case() {
    int N;
    cin >> N;
    vector<int> P(N);

    for (auto &p : P) {
        cin >> p;
        p--;
    }

    vector<bool> done(N, false);
    vector<int> cycles;

    for (int start = 0; start < N; start++) {
        if (done[start])
            continue;

        int x = start, count = 0;

        do {
            done[x] = true;
            x = P[x];
            count++;
        } while (!done[x]);

        cycles.push_back(count);
    }

    sort(cycles.begin(), cycles.end());
    dbg(cycles);
    cout << get_product(N) << ' ' << solve_ops(cycles) << '\n';
}

int main() {
    ios::sync_with_stdio(false);
#ifndef NEAL_DEBUG
    cin.tie(nullptr);
#endif

    int tests;
    cin >> tests;

    while (tests-- > 0)
        run_case();
}
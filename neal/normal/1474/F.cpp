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

extern const int MOD = 998244353;
using mod_int = _m_int<MOD>;


vector<mod_int> _factorial = {1, 1}, _inv_factorial = {1, 1};

void prepare_factorials(int64_t maximum) {
    static int prepared_maximum = 1;

    if (maximum <= prepared_maximum)
        return;

    // Prevent increasing maximum by only 1 each time.
    maximum += maximum / 16;
    _factorial.resize(maximum + 1);
    _inv_factorial.resize(maximum + 1);

    for (int i = prepared_maximum + 1; i <= maximum; i++) {
        _factorial[i] = i * _factorial[i - 1];
        _inv_factorial[i] = _inv_factorial[i - 1] / i;
    }

    prepared_maximum = int(maximum);
}

mod_int factorial(int n) {
    if (n < 0) return 0;
    prepare_factorials(n);
    return _factorial[n];
}

mod_int inv_factorial(int n) {
    if (n < 0) return 0;
    prepare_factorials(n);
    return _inv_factorial[n];
}

mod_int choose(int64_t n, int64_t r) {
    if (r < 0 || r > n) return 0;
    prepare_factorials(n);
    return _factorial[n] * _inv_factorial[r] * _inv_factorial[n - r];
}

mod_int permute(int64_t n, int64_t r) {
    if (r < 0 || r > n) return 0;
    prepare_factorials(n);
    return _factorial[n] * _inv_factorial[n - r];
}

mod_int inv_choose(int64_t n, int64_t r) {
    assert(0 <= r && r <= n);
    prepare_factorials(n);
    return _inv_factorial[n] * _factorial[r] * _factorial[n - r];
}

mod_int inv_permute(int64_t n, int64_t r) {
    assert(0 <= r && r <= n);
    prepare_factorials(n);
    return _inv_factorial[n] * _factorial[n - r];
}


int main() {
    int N, _;
    cin >> N >> _;
    vector<int64_t> D(N);

    for (auto &d : D)
        cin >> d;

    if (*max_element(D.begin(), D.end()) <= 0) {
        cout << 1 << ' ' << -accumulate(D.begin(), D.end(), mod_int(0)) + 1 << '\n';
        return 0;
    }

    D.erase(remove(D.begin(), D.end(), 0), D.end());
    vector<int64_t> sorted = {0};

    for (auto &d : D)
        sorted.push_back(sorted.back() + d);

    sort(sorted.begin(), sorted.end());
    sorted.erase(unique(sorted.begin(), sorted.end()), sorted.end());
    int ON = N;
    N = int(sorted.size());
    vector<int64_t> sequence = {0};

    auto get_index = [&](int64_t value) -> int {
        return int(lower_bound(sorted.begin(), sorted.end(), value) - sorted.begin());
    };

    for (auto &d : D) {
        auto it = lower_bound(sorted.begin(), sorted.end(), sequence.back());
        int64_t target = sequence.back() + d;

        if (d > 0) {
            while (*it != target)
                sequence.push_back(*++it);
        } else {
            while (*it != target)
                sequence.push_back(*--it);
        }
    }

    int S = int(sequence.size());
    int64_t longest = 0;

    for (int i = 0; i < S; i++)
        for (int j = i; j < S; j++)
            longest = max(longest, sequence[j] - sequence[i]);

    auto choose_loop = [&](int64_t n, int64_t r) -> mod_int {
        if (r < 0 || r > n)
            return 0;

        mod_int product = 1;

        for (int64_t i = 0; i < r; i++)
            product *= n - i;

        product *= inv_factorial(int(r));
        return product;
    };

    // vector<vector<vector<mod_int>>> choose_save(N + 1, vector<vector<mod_int>>(ON + 1, vector<mod_int>(ON + 1, 0)));

    // for (int i = 1; i < N; i++)
    //     for (int p = 0; p <= ON; p++)
    //         for (int n = 0; p + n <= ON; n++) {
    //             int64_t diff = sorted[i] - sorted[i - 1];
    //             choose_save[i][p][n] = p == 0 ? (n == diff ? 1 : 0) : choose_loop(diff - n - 1, p - 1);
    //         }

    mod_int total = 0;

    for (int initial = 0; initial < N; initial++) {
        int goal = get_index(sorted[initial] + longest);

        if (goal >= N || sorted[goal] != sorted[initial] + longest)
            continue;

        vector<mod_int> ready_for(N, 0);
        vector<vector<vector<mod_int>>> dp(N + 1, vector<vector<mod_int>>(ON + 1, vector<mod_int>(ON + 1, 0)));
        ready_for[initial] = 1;

        auto recompute_ready_for = [&](int index) -> void {
            if (index <= initial || index > goal)
                return;

            ready_for[index] = 0;
            int64_t diff = sorted[index] - sorted[index - 1];

            for (int p = 0; p <= ON; p++)
                for (int n = 0; p + n <= ON; n++)
                    ready_for[index] += dp[index - 1][p][n] * (p == 0 ? (n == diff ? 1 : 0) : choose_loop(diff - n - 1, p - 1));
        };

        for (int i = 0; i < S - 1; i++) {
            if (sequence[i] == sorted[goal])
                total += ready_for[goal];

            int64_t smaller = min(sequence[i], sequence[i + 1]);
            int64_t bigger = max(sequence[i], sequence[i + 1]);
            int s_index = get_index(smaller);
            int b_index = get_index(bigger);
            assert(b_index == s_index + 1);

            if (sequence[i] < sequence[i + 1]) {
                for (int p = ON - 1; p >= 0; p--)
                    for (int n = ON - 1 - p; n >= 0; n--)
                        dp[s_index][p + 1][n] += dp[s_index][p][n];

                dp[s_index][1][0] += ready_for[s_index];
                recompute_ready_for(b_index);
            } else {
                for (int p = ON - 1; p >= 0; p--)
                    for (int n = ON - 1 - p; n >= 0; n--)
                        dp[s_index][p][n + 1] += dp[s_index][p][n];

                if (i == 0 || sequence[i - 1] < sequence[i])
                    dp[b_index][0][1] += ready_for[b_index];

                if (i + 2 < S && sequence[i + 1] > sequence[i + 2])
                    dp[s_index][0][1] += ready_for[s_index];
            }
        }

        if (sequence.back() == sorted[goal])
            total += ready_for[goal];
    }

    cout << longest + 1 << ' ' << total << '\n';
}
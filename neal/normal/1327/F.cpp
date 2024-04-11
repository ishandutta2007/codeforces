#include <algorithm>
#include <cassert>
#include <deque>
#include <iostream>
#include <vector>
using namespace std;

template<typename T> ostream& operator<<(ostream &os, const vector<T> &v) { os << '{'; string sep; for (const auto &x : v) os << sep << x, sep = ", "; return os << '}'; }
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }

void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }

#ifdef NEAL
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif


template<const int &MOD>
struct _m_int {
    int val;

    _m_int(long long v = 0) {
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
    explicit operator long long() const { return val; }

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

    _m_int pow(long long p) const {
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


struct condition {
    int L, R, X;
};

int N, K, M;
vector<vector<condition>> conditions;

mod_int count_ways(int bit) {
    // DP state = number of ways to solve a prefix up to i where a[i] = 0
    deque<pair<int, mod_int>> dp = {{-1, 1}};
    mod_int total = 1;

    for (int i = 0; i < N; i++) {
        dp.emplace_back(i, total);
        total += total;

        for (condition &cond : conditions[i + 1])
            if (cond.X >> bit & 1) {
                while (!dp.empty() && dp.back().first >= cond.L) {
                    total -= dp.back().second;
                    dp.pop_back();
                }
            } else {
                while (!dp.empty() && dp.front().first < cond.L) {
                    total -= dp.front().second;
                    dp.pop_front();
                }
            }
    }

    dbg(bit, total);
    return total;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> K >> M;
    conditions.assign(N + 1, {});

    for (int i = 0; i < M; i++) {
        condition cond;
        cin >> cond.L >> cond.R >> cond.X;
        cond.L--;
        conditions[cond.R].push_back(cond);
    }

    mod_int answer = 1;

    for (int bit = 0; bit < K; bit++)
        answer *= count_ways(bit);

    cout << answer << '\n';
}
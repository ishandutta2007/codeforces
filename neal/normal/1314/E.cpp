#include <algorithm>
#include <cassert>
#include <iostream>
#include <numeric>
#include <vector>
using namespace std;

template<typename T> ostream& operator<<(ostream &os, const vector<T> &v) { os << "{"; for (typename vector<T>::const_iterator vi = v.begin(); vi != v.end(); ++vi) { if (vi != v.begin()) os << ", "; os << *vi; } os << "}"; return os; }
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { os << '(' << p.first << ", " << p.second << ')'; return os; }

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
        assert(p >= 0);
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


int N, K;

mod_int solve1() {
    vector<mod_int> partitions(N + 1, 0);
    partitions[0] = 1;

    for (int x = 1; x <= N; x++)
        for (int i = 0; i + x <= N; i++)
            partitions[i + x] += partitions[i];

    return accumulate(partitions.begin() + 1, partitions.end(), mod_int());
}

mod_int solve2() {
    vector<mod_int> dp(N + 1, 0);
    dp[0] = 1;

    for (int a = 1; a * (a + 1) / 2 <= N; a++) {
        int add = a * (a + 1) / 2;

        for (int x = 0; x + add <= N; x++)
            dp[x + add] += dp[x];
    }

    return accumulate(dp.begin() + 1, dp.end(), mod_int());
}

int sum_up_to(int n) {
    return n * (n + 1) / 2;
}

bool acceptable3(vector<int> current) {
    int sum = 0, next = 1;

    for (int i = (int) current.size() - 1; i >= 0; i--) {
        // Simulate two steps at a time.
        int number = i + 1;
        int count = current[i];
        sum += number * (sum_up_to(next + count - 1) - sum_up_to(next - 1));
        next += count;
    }

    return sum <= N;
}

bool acceptable(vector<int> current) {
    if (K == 3)
        return acceptable3(current);

    for (int iter = K - 1; iter >= 1; iter--) {
        vector<int> next_current;
        int next_sum = 0;

        for (int i = 0; i < (int) current.size(); i++) {
            int number = i + 1;

            if (iter > 1) {
                for (int rep = 0; rep < current[i]; rep++) {
                    next_current.push_back(number);
                    next_sum += number;
                }
            } else {
                next_sum += current[i] * number;
            }

            if (next_sum > N)
                return false;
        }

        reverse(next_current.begin(), next_current.end());
        swap(current, next_current);
    }

    return true;
}

int recurse(vector<int> current, int limit) {
    int answer = 1;
    current.emplace_back();

    for (int x = 1; x <= limit; x++) {
        current.back() = x;

        if (acceptable(current))
            answer += recurse(current, x);
        else
            break;
    }

    return answer;
}

int solve() {
    return recurse({}, N) - 1;
}

int main() {
    cin >> N >> K;

    if (K == 1)
        cout << solve1() << '\n';
    else if (K == 2)
        cout << solve2() << '\n';
    else
        cout << solve() << '\n';
}
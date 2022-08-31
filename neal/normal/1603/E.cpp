#include <algorithm>
#include <array>
#include <bitset>
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

// http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2016/p0200r0.html
template<class Fun> class y_combinator_result {
    Fun fun_;
public:
    template<class T> explicit y_combinator_result(T &&fun): fun_(std::forward<T>(fun)) {}
    template<class ...Args> decltype(auto) operator()(Args &&...args) { return fun_(std::ref(*this), std::forward<Args>(args)...); }
};
template<class Fun> decltype(auto) y_combinator(Fun &&fun) { return y_combinator_result<std::decay_t<Fun>>(std::forward<Fun>(fun)); }


template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }

void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
#ifdef NEAL_DEBUG
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif

struct barrett_reduction {
    unsigned mod;
    uint64_t div;

    barrett_reduction(unsigned m) : mod(m), div(-1LLU / m) {}

    unsigned operator()(uint64_t a) const {
#ifdef __SIZEOF_INT128__
        uint64_t q = uint64_t(__uint128_t(div) * a >> 64);
        uint64_t r = a - q * mod;
        return unsigned(r < mod ? r : r - mod);
#endif
        return unsigned(a % mod);
    }
};

template<const int &MOD, const barrett_reduction &barrett>
struct _b_int {
    int val;

    _b_int(int64_t v = 0) {
        if (v < 0) v = v % MOD + MOD;
        if (v >= MOD) v %= MOD;
        val = int(v);
    }

    _b_int(uint64_t v) {
        if (v >= MOD) v %= MOD;
        val = int(v);
    }

    _b_int(int v) : _b_int(int64_t(v)) {}
    _b_int(unsigned v) : _b_int(uint64_t(v)) {}

    static int inv_mod(int a, int m = MOD) {
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
    explicit operator unsigned() const { return val; }
    explicit operator int64_t() const { return val; }
    explicit operator uint64_t() const { return val; }
    explicit operator double() const { return val; }
    explicit operator long double() const { return val; }

    _b_int& operator+=(const _b_int &other) {
        val -= MOD - other.val;
        if (val < 0) val += MOD;
        return *this;
    }

    _b_int& operator-=(const _b_int &other) {
        val -= other.val;
        if (val < 0) val += MOD;
        return *this;
    }

    static unsigned fast_mod(uint64_t x) {
#if !defined(_WIN32) || defined(_WIN64)
        return barrett(x);
#endif
        // Optimized mod for Codeforces 32-bit machines.
        // x must be less than 2^32 * MOD for this to work, so that x / MOD fits in an unsigned 32-bit int.
        unsigned x_high = unsigned(x >> 32), x_low = unsigned(x);
        unsigned quot, rem;
        asm("divl %4\n"
            : "=a" (quot), "=d" (rem)
            : "d" (x_high), "a" (x_low), "r" (MOD));
        return rem;
    }

    _b_int& operator*=(const _b_int &other) {
        val = fast_mod(uint64_t(val) * other.val);
        return *this;
    }

    _b_int& operator/=(const _b_int &other) {
        return *this *= other.inv();
    }

    friend _b_int operator+(const _b_int &a, const _b_int &b) { return _b_int(a) += b; }
    friend _b_int operator-(const _b_int &a, const _b_int &b) { return _b_int(a) -= b; }
    friend _b_int operator*(const _b_int &a, const _b_int &b) { return _b_int(a) *= b; }
    friend _b_int operator/(const _b_int &a, const _b_int &b) { return _b_int(a) /= b; }

    _b_int& operator++() {
        val = val == MOD - 1 ? 0 : val + 1;
        return *this;
    }

    _b_int& operator--() {
        val = val == 0 ? MOD - 1 : val - 1;
        return *this;
    }

    _b_int operator++(int) { _b_int before = *this; ++*this; return before; }
    _b_int operator--(int) { _b_int before = *this; --*this; return before; }

    _b_int operator-() const {
        return val == 0 ? 0 : MOD - val;
    }

    friend bool operator==(const _b_int &a, const _b_int &b) { return a.val == b.val; }
    friend bool operator!=(const _b_int &a, const _b_int &b) { return a.val != b.val; }
    friend bool operator<(const _b_int &a, const _b_int &b) { return a.val < b.val; }
    friend bool operator>(const _b_int &a, const _b_int &b) { return a.val > b.val; }
    friend bool operator<=(const _b_int &a, const _b_int &b) { return a.val <= b.val; }
    friend bool operator>=(const _b_int &a, const _b_int &b) { return a.val >= b.val; }

    _b_int inv() const {
        return inv_mod(val);
    }

    _b_int pow(int64_t p) const {
        if (p < 0)
            return inv().pow(-p);

        _b_int a = *this, result = 1;

        while (p > 0) {
            if (p & 1)
                result *= a;

            p >>= 1;

            if (p > 0)
                a *= a;
        }

        return result;
    }

    friend ostream& operator<<(ostream &os, const _b_int &m) {
        return os << m.val;
    }

    friend istream& operator>>(istream &is, _b_int &m) {
        int64_t x;
        is >> x;
        m = x;
        return is;
    }
};

int MOD = 1;
barrett_reduction barrett(1);
using barrett_int = _b_int<MOD, barrett>;


int main() {
    int N;
    cin >> N >> MOD;
    barrett = barrett_reduction(MOD);
    vector<barrett_int> inv(N + 2, 1);
    vector<barrett_int> factorial(N + 2, 1);
    vector<barrett_int> inv_factorial(N + 2, 1);

    for (int i = 1; i <= N + 1; i++) {
        inv[i] = barrett_int(i).inv();
        factorial[i] = i * factorial[i - 1];
        inv_factorial[i] = inv[i] * inv_factorial[i - 1];
    }

    auto solve = [&](vector<int> A) -> barrett_int {
        if (A[0] == N + 1)
            return 1;

        if (A[0] == N)
            return barrett_int(2).pow(N) - 1;

        assert(int(A.size()) == N && A.back() == N + 1);
        vector<int> prefix_sum(N + 1, 0);

        for (int i = 0; i < N; i++)
            prefix_sum[i + 1] = prefix_sum[i] + A[i];

        int initial_slack = A[0] * A[N - 1] - accumulate(A.begin(), A.end(), 0);
        vector<vector<vector<barrett_int>>> dp(2, vector<vector<barrett_int>>(N + 2 - A[0], vector<barrett_int>(initial_slack + 1, 0)));
        dp[1][N + 1 - A[0]][initial_slack] = 1;

        for (int i = N - 2; i >= 0; i--) {
            vector<vector<vector<barrett_int>>> ndp(N - i + 1, vector<vector<barrett_int>>(N + 2 - A[0], vector<barrett_int>(initial_slack + 1, 0)));

            for (int same = 1; same < N - i; same++)
                for (int after = A[i + 1]; after <= N + 1; after++)
                    for (int slack = 0; slack <= initial_slack; slack++) {
                        if (dp[same][after - A[0]][slack] == 0)
                            continue;

                        for (int now = A[i]; now <= after && now - A[i] <= slack; now++) {
                            int diff = now - A[i];
                            int nsame = now == after ? same + 1 : 1;
                            int nslack = min(slack - diff, A[0] * now - (prefix_sum[i] + now));
                            assert(nslack >= 0);
                            ndp[nsame][now - A[0]][nslack] += dp[same][after - A[0]][slack] * inv[nsame];
                        }
                    }

            dp.swap(ndp);
        }

        barrett_int ans = 0;

        for (int same = 1; same <= N; same++)
            for (int slack = 0; slack <= initial_slack; slack++)
                ans += dp[same][0][slack];

        return ans * factorial[N];
    };

    barrett_int total = 0;

    for (int a = 1; a <= N + 1; a++) {
        vector<int> A(N, a);
        bool fail = false;

        for (int i = 1; i < N; i++)
            while (true) {
                int product = A[0] * A[i];
                int sum = 0;

                for (int j = 0; j <= i; j++)
                    sum += A[j];

                if (product >= sum)
                    break;

                A[i]++;

                if (A[i] > N + 1) {
                    fail = true;
                    break;
                }
            }

        int slack = A[0] * A[N - 1] - accumulate(A.begin(), A.end(), 0);

        if (!fail) {
            barrett_int ways = solve(A);
            cerr << slack << ' ' << A << ' ' << ways << endl;
            total += ways;
        }
    }

    cout << total << '\n';
}
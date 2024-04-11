#include <algorithm>
#include <cassert>
#include <iostream>
#include <numeric>
#include <vector>
using namespace std;

const int MOD = 998244353;

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

vector<mod_int> inv, factorial, inv_factorial;

void prepare_factorials(int maximum) {
    inv.assign(maximum + 1, 1);

    // Make sure MOD is prime, which is necessary for the inverse algorithm below.
    for (int p = 2; p * p <= MOD; p++)
        assert(MOD % p != 0);

    for (int i = 2; i <= maximum; i++)
        inv[i] = inv[MOD % i] * (MOD - MOD / i);

    factorial.resize(maximum + 1);
    inv_factorial.resize(maximum + 1);
    factorial[0] = inv_factorial[0] = 1;

    for (int i = 1; i <= maximum; i++) {
        factorial[i] = i * factorial[i - 1];
        inv_factorial[i] = inv[i] * inv_factorial[i - 1];
    }
}

mod_int choose(long long n, long long r) {
    if (r < 0 || r > n)
        return 0;

    return factorial[n] * inv_factorial[r] * inv_factorial[n - r];
}

mod_int inv_choose(long long n, long long r) {
    assert(0 <= r && r <= n);
    return inv_factorial[n] * factorial[r] * factorial[n - r];
}

mod_int permute(long long n, long long k) {
    if (k < 0 || k > n)
        return 0;

    return factorial[n] * inv_factorial[n - k];
}

mod_int inv_permute(long long n, long long k) {
    assert(0 <= k && k <= n);
    return inv_factorial[n] * factorial[n - k];
}


vector<mod_int> solve_dp(int n, vector<bool> good) {
    vector<mod_int> dp1 = {1}, dp2 = {1}, dp3;

    for (int row = 2; row <= n; row++) {
        dp3 = dp2;

        if (row % 2 == 0)
            dp3.push_back(0);

        if (good[row - 1] && good[row])
            for (int blocks = 1; 2 * blocks <= row; blocks++)
                dp3[blocks] += dp1[blocks - 1];

        swap(dp1, dp2);
        swap(dp2, dp3);
    }

    return dp2;
}

int main() {
    int H, W, N;
    cin >> H >> W >> N;
    prepare_factorials(max(H, W));
    vector<bool> row_good(H + 1, true);
    vector<bool> col_good(W + 1, true);

    for (int i = 0; i < N; i++) {
        int r1, c1, r2, c2;
        cin >> r1 >> c1 >> r2 >> c2;
        row_good[r1] = row_good[r2] = col_good[c1] = col_good[c2] = false;
    }

    int GR = accumulate(row_good.begin() + 1, row_good.end(), 0);
    int GC = accumulate(col_good.begin() + 1, col_good.end(), 0);

    vector<mod_int> row_dp = solve_dp(H, row_good);
    vector<mod_int> col_dp = solve_dp(W, col_good);
    mod_int total = 0;

    for (int vert = 0; 2 * vert <= GR && vert <= GC; vert++)
        for (int horiz = 0; 2 * vert + horiz <= GR && vert + 2 * horiz <= GC; horiz++)
            total += row_dp[vert] * col_dp[horiz] * permute(GR - 2 * vert, horiz) * permute(GC - 2 * horiz, vert);

    cout << (int) total << '\n';
}
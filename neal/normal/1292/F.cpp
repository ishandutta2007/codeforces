#include <algorithm>
#include <cassert>
#include <iostream>
#include <numeric>
#include <vector>
using namespace std;

const int MOD = 1e9 + 7;

struct mod_int {
    int val;

    mod_int(long long v = 0) {
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

    friend ostream& operator<<(ostream &stream, const mod_int &m) {
        return stream << m.val;
    }
};

vector<mod_int> inv, factorial, inv_factorial;

void prepare_factorials(int maximum) {
    // Make sure MOD is prime, which is necessary for the inverse algorithm below.
    for (int p = 2; p * p <= MOD; p++)
        assert(MOD % p != 0);

    inv = {0, 1};
    factorial = inv_factorial = {1, 1};

    maximum = max(maximum, 1);
    inv.resize(maximum + 1);
    factorial.resize(maximum + 1);
    inv_factorial.resize(maximum + 1);

    for (int i = 2; i <= maximum; i++) {
        inv[i] = inv[MOD % i] * (MOD - MOD / i);
        factorial[i] = i * factorial[i - 1];
        inv_factorial[i] = inv[i] * inv_factorial[i - 1];
    }
}

mod_int choose(long long n, long long r) {
    if (r < 0 || r > n) return 0;
    return factorial[n] * inv_factorial[r] * inv_factorial[n - r];
}

mod_int inv_choose(long long n, long long r) {
    assert(0 <= r && r <= n);
    return inv_factorial[n] * factorial[r] * factorial[n - r];
}

mod_int permute(long long n, long long k) {
    if (k < 0 || k > n) return 0;
    return factorial[n] * inv_factorial[n - k];
}

mod_int inv_permute(long long n, long long k) {
    assert(0 <= k && k <= n);
    return inv_factorial[n] * factorial[n - k];
}

struct union_find {
    vector<int> parent;

    union_find(int n = -1) {
        if (n >= 0)
            init(n);
    }

    void init(int n) {
        parent.resize(n + 1);

        for (int i = 0; i <= n; i++)
            parent[i] = i;
    }

    int find(int x) {
        return x == parent[x] ? x : parent[x] = find(parent[x]);
    }

    bool unite(int x, int y) {
        x = find(x);
        y = find(y);
        parent[y] = x;
        return x != y;
    }
};


mod_int solve(int S, vector<int> component) {
    vector<mod_int> dp(1 << S, 0);

    for (int mask : component)
        dp[mask]++;

    for (int c = 1; c < (int) component.size(); c++) {
        vector<mod_int> next_dp(1 << S, 0);

        for (int mask = 0; mask < 1 << S; mask++) {
            if (dp[mask] == 0)
                continue;

            int contained = 0;

            for (int next : component)
                if ((mask & next) == next)
                    contained++;
                else if ((mask & next) != 0)
                    next_dp[mask | next] += dp[mask];

            assert(contained >= c);
            next_dp[mask] += dp[mask] * (contained - c);
        }

        dp = next_dp;
    }

    return accumulate(dp.begin(), dp.end(), mod_int(0));
}

int main() {
    int N;
    cin >> N;
    prepare_factorials(N);
    vector<int> A(N);
    A.resize(N);

    for (int &a : A)
        cin >> a;

    sort(A.begin(), A.end());
    vector<int> special;

    for (int i = 0; i < N; i++) {
        bool good = true;

        for (int j = 0; j < i; j++)
            if (A[i] % A[j] == 0)
                good = false;

        int divisible = 0;

        for (int j = i + 1; j < N; j++)
            if (A[j] % A[i] == 0)
                divisible++;

        if (good && divisible >= 2)
            special.push_back(A[i]);
    }

    int S = special.size();
    assert(S <= (A.back() + 3) / 6);
    vector<int> masks(N, 0);

    for (int i = 0; i < N; i++)
        for (int s = 0; s < S; s++)
            if (A[i] > special[s] && A[i] % special[s] == 0)
                masks[i] |= 1 << s;

    union_find UF(S);

    for (int i = 0; i < N; i++)
        if (masks[i] != 0) {
            int first = __builtin_ctz(masks[i]);

            for (int s = first + 1; s < S; s++)
                if (masks[i] >> s & 1)
                    UF.unite(first, s);
        }

    mod_int answer = 1;
    int count = 0;

    for (int s = 0; s < S; s++)
        if (UF.find(s) == s) {
            vector<int> component;

            for (int i = 0; i < N; i++)
                if (masks[i] != 0 && UF.find(__builtin_ctz(masks[i])) == s)
                    component.push_back(masks[i]);

            if (!component.empty()) {
                int current = component.size();
                answer *= choose(count + current - 1, current - 1) * solve(S, component);
                count += current - 1;
            }
        }

    cout << answer << '\n';
}
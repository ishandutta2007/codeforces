#include <algorithm>
#include <cassert>
#include <iostream>
#include <set>
#include <vector>
using namespace std;

const int MOD = 998244353;

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


const mod_int INV_100 = mod_int(1) / mod_int(100);

int N, Q;
vector<mod_int> P;
vector<mod_int> product, product_sum;

mod_int get_product(int start, int end) {
    return product[end] / product[start];
}

mod_int get_product_sum(int start, int end) {
    return (product_sum[end] - product_sum[start]) / product[start];
}

mod_int get_contribution(int start, int end) {
    return get_product_sum(start, end) / get_product(start, end);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> Q;
    P.resize(N);

    for (int i = 0; i < N; i++) {
        int p;
        cin >> p;
        P[i] = p * INV_100;
    }

    product.assign(N + 1, 1);
    product_sum.assign(N + 1, 0);

    for (int i = 0; i < N; i++) {
        product[i + 1] = product[i] * P[i];
        product_sum[i + 1] = product_sum[i] + product[i];
    }

    set<int> checkpoints;
    checkpoints.insert(0);
    checkpoints.insert(N);
    mod_int answer = get_contribution(0, N);

    for (int q = 0; q < Q; q++) {
        int u;
        cin >> u;
        u--;

        if (checkpoints.find(u) == checkpoints.end()) {
            checkpoints.insert(u);
            auto it = checkpoints.find(u);
            auto next_it = it; next_it++;
            auto prev_it = it; prev_it--;
            answer -= get_contribution(*prev_it, *next_it);
            answer += get_contribution(*prev_it, *it);
            answer += get_contribution(*it, *next_it);
        } else {
            auto it = checkpoints.find(u);
            auto next_it = it; next_it++;
            auto prev_it = it; prev_it--;
            answer -= get_contribution(*prev_it, *it);
            answer -= get_contribution(*it, *next_it);
            answer += get_contribution(*prev_it, *next_it);
            checkpoints.erase(it);
        }

        cout << answer << '\n';
    }
}
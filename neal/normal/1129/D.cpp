#include <algorithm>
#include <cassert>
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

template<typename T> ostream& operator<<(ostream &os, const vector<T> &v) { os << "{"; for (typename vector<T>::const_iterator vi = v.begin(); vi != v.end(); ++vi) { if (vi != v.begin()) os << ", "; os << *vi; } os << "}"; return os; }
template<> ostream& operator<<(ostream &os, const vector<string> &v) { os << "{"; for (vector<string>::const_iterator vi = v.begin(); vi != v.end(); ++vi) { if (vi != v.begin()) os << ", "; os << "\"" << *vi << "\""; } os << "}"; return os; }

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

    friend ostream& operator<<(ostream &stream, const mod_int &m) {
        return stream << m.val;
    }
};


int N, K, BLOCK_SIZE;
vector<int> A;
vector<int> next_same;
vector<mod_int> dp;

struct block {
    int start, end, minimum = 0;

    // values[i] + minimum = the single count at index start + i.
    vector<int> values;

    // dp_sums[i] = the sum of DP values whose single count is <= minimum + i.
    vector<mod_int> dp_prefix_sums;

    void init(int _start, int _end) {
        start = _start;
        end = _end;
        minimum = 0;
        values.assign(end - start, 0);
        dp_prefix_sums = {0};
    }

    void add_dp(int index) {
        for (int i = values[index - start]; i < (int) dp_prefix_sums.size(); i++)
            dp_prefix_sums[i] += dp[index];
    }

    void update(int a, int b, int change) {
        if (a == start && b == end) {
            minimum += change;
            return;
        }

        for (int i = a; i < b; i++)
            values[i - start] += change;

        // Determine the new minimum.
        int offset = *min_element(values.begin(), values.end());
        minimum += offset;

        for (int i = start; i < end; i++)
            values[i - start] -= offset;

        int maximum = *max_element(values.begin(), values.end());
        dp_prefix_sums.assign(maximum + 1, 0);

        for (int i = start; i < end; i++)
            dp_prefix_sums[values[i - start]] += dp[i];

        for (int i = 1; i <= maximum; i++)
            dp_prefix_sums[i] += dp_prefix_sums[i - 1];
    }

    mod_int query() const {
        int index = K - minimum;

        if (index < 0)
            return 0;

        if (index >= (int) dp_prefix_sums.size())
            return dp_prefix_sums.back();

        return dp_prefix_sums[index];
    }
};

vector<block> blocks;

void update_all_blocks(int start, int end, int change) {
    // cerr << "update_all " << start << ' ' << end << ' ' << change << endl;

    if (start >= end)
        return;

    for (block &blk : blocks) {
        int a = max(start, blk.start);
        int b = min(end, blk.end);

        if (a < b)
            blk.update(a, b, change);
    }
}

mod_int query_all_blocks() {
    mod_int total = 0;

    for (block &blk : blocks)
        total += blk.query();

    return total;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> K;
    BLOCK_SIZE = (int) (0.8 * sqrt(N)) + 1;
    A.resize(N);

    for (int &a : A)
        cin >> a;

    next_same.assign(N + 1, N);
    vector<int> last_seen(N + 1, N);

    for (int i = N - 1; i >= 0; i--) {
        next_same[i] = last_seen[A[i]];
        last_seen[A[i]] = i;
    }

    dp.assign(N + 1, 0);
    dp[N] = 1;

    for (int start = 0; start <= N; start += BLOCK_SIZE) {
        blocks.emplace_back();
        blocks.back().init(start, min(start + BLOCK_SIZE, N + 1));
    }

    for (block &blk : blocks)
        if (blk.start <= N && N < blk.end)
            blk.add_dp(N);

    for (int i = N - 1; i >= 0; i--) {
        update_all_blocks(i + 1, next_same[i] + 1, +1);
        update_all_blocks(next_same[i] + 1, next_same[next_same[i]] + 1, -1);
        dp[i] = query_all_blocks();

        for (block &blk : blocks)
            if (blk.start <= i && i < blk.end)
                blk.add_dp(i);

        // for (block &blk : blocks) {
        //     cerr << blk.start << ' ' << blk.end << ' ' << blk.minimum << endl;
        //     cerr << blk.values << ' ' << blk.dp_prefix_sums << endl;
        // }

        // cerr << i << ": " << dp[i] << endl;
    }

    cout << dp[0] << '\n';
}
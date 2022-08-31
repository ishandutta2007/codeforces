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
        // Ensures that MOD is prime, which is necessary for the inverse algorithm below.
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

        do {
            product *= MOD - MOD / v;
            v = MOD % v;
        } while (v >= SAVE_INV);

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

template<typename T>
struct fenwick_tree {
    static int highest_bit(unsigned x) {
        return x == 0 ? -1 : 31 - __builtin_clz(x);
    }

    int tree_n = 0;
    T tree_sum = T();
    vector<T> tree;

    fenwick_tree(int n = -1) {
        if (n >= 0)
            init(n);
    }

    void init(int n) {
        tree_n = n;
        tree_sum = T();
        tree.assign(tree_n + 1, T());
    }

    // O(n) initialization of the Fenwick tree.
    template<typename T_array>
    void build(const T_array &initial) {
        assert(int(initial.size()) == tree_n);
        tree_sum = T();

        for (int i = 1; i <= tree_n; i++) {
            tree[i] = initial[i - 1];
            tree_sum += initial[i - 1];

            for (int k = (i & -i) >> 1; k > 0; k >>= 1)
                tree[i] += tree[i - k];
        }
    }

    // index is in [0, tree_n).
    void update(int index, const T &change) {
        assert(0 <= index && index < tree_n);
        tree_sum += change;

        for (int i = index + 1; i <= tree_n; i += i & -i)
            tree[i] += change;
    }

    // Returns the sum of the range [0, count).
    T query(int count) const {
        count = min(count, tree_n);
        T sum = T();

        for (int i = count; i > 0; i -= i & -i)
            sum += tree[i];

        return sum;
    }

    // Returns the sum of the range [start, tree_n).
    T query_suffix(int start) const {
        return tree_sum - query(start);
    }

    // Returns the sum of the range [a, b).
    T query(int a, int b) const {
        return query(b) - query(a);
    }

    // Returns the element at index a in O(1) amortized across every index. Equivalent to query(a, a + 1).
    T get(int a) const {
        assert(0 <= a && a < tree_n);
        int above = a + 1;
        T sum = tree[above];
        above -= above & -above;

        while (a != above) {
            sum -= tree[a];
            a -= a & -a;
        }

        return sum;
    }

    bool set(int index, T value) {
        assert(0 <= index && index < tree_n);
        T current = get(index);

        if (current == value)
            return false;

        update(index, value - current);
        return true;
    }

    // Returns the largest p in `[0, tree_n]` such that `query(p) <= sum`. Returns -1 if no such p exists (`sum < 0`).
    // Can be used as an ordered set/multiset on indices in `[0, tree_n)` by using the tree as a 0/1 or frequency array:
    // `set(index, 1)` is equivalent to insert(index). `update(index, +1)` is equivalent to multiset.insert(index).
    // `set(index, 0)` or `update(index, -1)` are equivalent to erase(index).
    // `get(index)` provides whether index is present or not, or the count of index (if multiset).
    // `query(index)` provides the count of elements < index.
    // `find_last_prefix(k)` finds the k-th smallest element (0-indexed). Returns `tree_n` for `sum >= set.size()`.
    int find_last_prefix(T sum) const {
        if (sum < T())
            return -1;

        int prefix = 0;

        for (int k = highest_bit(tree_n); k >= 0; k--)
            if (prefix + (1 << k) <= tree_n && tree[prefix + (1 << k)] <= sum) {
                prefix += 1 << k;
                sum -= tree[prefix];
            }

        return prefix;
    }
};

// Compresses the values in arr to be in the range [0, n).
template<typename T>
vector<int> compress_array(const vector<T> &arr) {
    int n = int(arr.size());
    vector<T> sorted = arr;
    sort(sorted.begin(), sorted.end());
    sorted.erase(unique(sorted.begin(), sorted.end()), sorted.end());
    vector<int> compressed(n);

    for (int i = 0; i < n; i++)
        compressed[i] = int(lower_bound(sorted.begin(), sorted.end(), arr[i]) - sorted.begin());

    return compressed;
}


void run_case() {
    int N;
    cin >> N;
    vector<int> A(N);

    for (auto &a : A)
        cin >> a;

    A = compress_array(A);
    vector<mod_int> num_ending(N, 0);
    vector<mod_int> sum_ending(N, 0);
    fenwick_tree<mod_int> num_tree(N), sum_tree(N);

    for (int i = 0; i < N; i++) {
        num_ending[i] = num_tree.query(A[i]) + 1;
        sum_ending[i] = num_ending[i] + sum_tree.query(A[i]);
        num_tree.update(A[i], num_ending[i]);
        sum_tree.update(A[i], sum_ending[i]);
    }

    vector<int> suffix_max(N + 1, -1);

    for (int i = N - 1; i >= 0; i--)
        suffix_max[i] = max(A[i], suffix_max[i + 1]);

    vector<mod_int> dp(N, 0);
    fenwick_tree<mod_int> dp_tree(N);
    num_tree.init(N);
    sum_tree.init(N);

    for (int i = 0; i < N; i++) {
        int low = 0, high = N;

        while (low < high) {
            int mid = low + (high - low) / 2;

            if (suffix_max[mid] <= A[i])
                high = mid;
            else
                low = mid + 1;
        }

        int suffix = A[i] >= suffix_max[i + 1] ? i + 1 : low;
        int cutoff = suffix_max[suffix];

        if (cutoff >= 0)
            dp[i] = dp_tree.query(cutoff, A[i]) + sum_tree.query(0, cutoff);

        dp_tree.update(A[i], dp[i]);
        num_tree.update(A[i], num_ending[i]);
        sum_tree.update(A[i], sum_ending[i]);
    }

    dbg(sum_ending);
    dbg(dp);
    mod_int total = 0;

    for (int i = 0; i < N; i++)
        if (A[i] < suffix_max[i + 1])
            total += sum_ending[i];
        else
            total += dp[i];

    cout << total << '\n';
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
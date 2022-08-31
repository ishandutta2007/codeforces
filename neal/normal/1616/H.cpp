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

int highest_bit(unsigned x) {
    return x == 0 ? -1 : 31 - __builtin_clz(x);
}

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

extern const int MOD = 998244353;
using mod_int = _m_int<MOD>;


const int BITS = 30;

template<int ALPHABET = 2>
struct array_trie {
    struct trie_node {
        array<int, ALPHABET> child;
        int nums = 0;

        trie_node() {
            memset(&child[0], -1, ALPHABET * sizeof(int));
        }
    };

    static const int ROOT = 0;

    vector<trie_node> nodes = {trie_node()};

    array_trie(int total_length = -1) {
        if (total_length >= 0)
            nodes.reserve(total_length + 1);
    }

    int get_or_create_child(int node, int c) {
        if (nodes[node].child[c] < 0) {
            nodes[node].child[c] = int(nodes.size());
            nodes.emplace_back();
        }

        return nodes[node].child[c];
    }

    int add(int num) {
        int node = ROOT;
        nodes[node].nums++;

        for (int bit = BITS - 1; bit >= 0; bit--) {
            node = get_or_create_child(node, (num >> bit & 1));
            nodes[node].nums++;
        }

        return node;
    }

    int get_count(int node) const {
        if (node < 0)
            return 0;

        return nodes[node].nums;
    }
};

int main() {
    ios::sync_with_stdio(false);
#ifndef NEAL_DEBUG
    cin.tie(nullptr);
#endif

    int N, X;
    cin >> N >> X;
    vector<int> A(N);
    array_trie<2> trie;

    for (auto &a : A) {
        cin >> a;
        trie.add(a);
    }

    vector<mod_int> p2(N + 1, 1);

    for (int i = 1; i <= N; i++)
        p2[i] = 2 * p2[i - 1];

    if (X == 0) {
        map<int, int> freq;

        for (auto &a : A)
            freq[a]++;

        mod_int total = 0;

        for (auto &pr : freq)
            total += p2[pr.second] - 1;

        cout << total << '\n';
        return 0;
    }

    auto solve = y_combinator([&](auto self, int a, int b, int a_trie, int b_trie, int bit) -> mod_int {
        if (a_trie < 0 || b_trie < 0)
            return 0;

        int a_cnt = trie.nodes[a_trie].nums;
        int b_cnt = trie.nodes[b_trie].nums;

        if (bit < 0)
            return (p2[a_cnt] - 1) * (p2[b_cnt] - 1);

        if ((X >> bit & 1) == 0) {
            mod_int zero = self(a, b, trie.nodes[a_trie].child[0], trie.nodes[b_trie].child[0], bit - 1);
            mod_int one = self(a | 1 << bit, b | 1 << bit, trie.nodes[a_trie].child[1], trie.nodes[b_trie].child[1], bit - 1);
            return zero + one;
        }

        int a0_cnt = trie.get_count(trie.nodes[a_trie].child[0]);
        int a1_cnt = trie.get_count(trie.nodes[a_trie].child[1]);
        int b0_cnt = trie.get_count(trie.nodes[b_trie].child[0]);
        int b1_cnt = trie.get_count(trie.nodes[b_trie].child[1]);
        mod_int a0b1 = self(a, b | 1 << bit, trie.nodes[a_trie].child[0], trie.nodes[b_trie].child[1], bit - 1);
        mod_int a1b0 = self(a | 1 << bit, b, trie.nodes[a_trie].child[1], trie.nodes[b_trie].child[0], bit - 1);
        mod_int ans = 0;
        ans += a0b1 * p2[b0_cnt] + (p2[a0_cnt] - 1) * (p2[b0_cnt] - 1);
        ans += a1b0 * p2[b1_cnt] + (p2[a1_cnt] - 1) * (p2[b1_cnt] - 1);
        ans += a0b1 * a1b0;
        ans += a0b1 * (p2[a1_cnt] - 1) + a1b0 * (p2[a0_cnt] - 1);
        return ans;
    });

    int high = highest_bit(X);

    auto dfs = y_combinator([&](auto self, int num, int n_trie, int bit) -> mod_int {
        if (n_trie < 0)
            return 0;

        int trie0 = trie.nodes[n_trie].child[0];
        int trie1 = trie.nodes[n_trie].child[1];

        if (bit == high) {
            int cnt0 = trie.get_count(trie0);
            int cnt1 = trie.get_count(trie1);
            mod_int ans = (p2[cnt0] - 1) + (p2[cnt1] - 1);
            ans += solve(num, num | 1 << bit, trie0, trie1, bit - 1);
            return ans;
        }

        return self(num, trie0, bit - 1) + self(num, trie1, bit - 1);
    });

    cout << dfs(0, 0, BITS - 1) << '\n';
}
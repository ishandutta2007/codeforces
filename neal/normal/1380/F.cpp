#include <algorithm>
#include <array>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

template<typename T> ostream& operator<<(ostream &os, const vector<T> &v) { os << '{'; string sep; for (const auto &x : v) os << sep << x, sep = ", "; return os << '}'; }
template<typename T, size_t size> ostream& operator<<(ostream &os, const array<T, size> &arr) { os << '{'; string sep; for (const auto &x : arr) os << sep << x, sep = ", "; return os << '}'; }
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }

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

    _m_int inv() const {
        return inv_mod(val);
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

extern const int MOD = 998244353;
using mod_int = _m_int<MOD>;


struct mod_matrix_fixed_size {
    static const int SIZE = 2;

    mod_int values[SIZE][SIZE];

    mod_matrix_fixed_size() {
        for (int i = 0; i < SIZE; i++)
            for (int j = 0; j < SIZE; j++)
                values[i][j] = 0;
    }

    template<typename T>
    mod_matrix_fixed_size(const vector<vector<T>> &v) {
        init(v);
    }

    template<typename T>
    void init(const vector<vector<T>> &v) {
        assert(v.size() == SIZE);

        for (int i = 0; i < SIZE; i++) {
            assert(v[i].size() == SIZE);

            for (int j = 0; j < SIZE; j++)
                values[i][j] = v[i][j];
        }
    }

    mod_int *operator[](int index) { return values[index]; }
    const mod_int *operator[](int index) const { return values[index]; }

    void make_identity() {
        for (int i = 0; i < SIZE; i++)
            for (int j = 0; j < SIZE; j++)
                values[i][j] = i == j ? 1 : 0;
    }

    mod_matrix_fixed_size operator*(const mod_matrix_fixed_size &other) const {
        mod_matrix_fixed_size product;

        for (int i = 0; i < SIZE; i++)
            for (int k = 0; k < SIZE; k++) {
                uint64_t result = 0;

                for (int j = 0; j < SIZE; j++)
                    result += uint64_t(values[i][j]) * uint64_t(other[j][k]);

                product[i][k] = result;
            }

        return product;
    }

    mod_matrix_fixed_size& operator*=(const mod_matrix_fixed_size &other) {
        return *this = *this * other;
    }

    mod_matrix_fixed_size power(int64_t p) const {
        assert(p >= 0);
        mod_matrix_fixed_size m = *this;
        mod_matrix_fixed_size result;
        result.make_identity();

        while (p > 0) {
            if (p & 1)
                result *= m;

            p >>= 1;

            if (p > 0)
                m *= m;
        }

        return result;
    }

    void print() const {
        for (int i = 0; i < SIZE; i++)
            for (int j = 0; j < SIZE; j++)
                cout << values[i][j] << (j < SIZE - 1 ? ' ' : '\n');
    }
};


struct segment {
    mod_matrix_fixed_size transition;

    segment(int digit = -1) {
        if (digit < 0)
            transition.make_identity();
        else
            transition.init(vector<vector<int>>{{0, 9 - digit}, {digit == 1, digit + 1}});
    }

    void join(const segment &other) {
        transition *= other.transition;
    }

    void join(const segment &a, const segment &b) {
        transition = a.transition * b.transition;
    }
};

int right_half[32];

struct basic_seg_tree {
    static const bool POWER_OF_TWO_MODE = true;

    int tree_n = 0;
    vector<segment> tree;

    basic_seg_tree(int n = -1) {
        if (n >= 0)
            init(n);
    }

    void init(int n) {
        if (POWER_OF_TWO_MODE) {
            tree_n = 1;

            while (tree_n < n)
                tree_n *= 2;
        } else {
            tree_n = n;
        }

        tree.assign(2 * tree_n, segment());
    }

    // Builds our tree from an array in O(n).
    void build(const vector<segment> &initial) {
        int n = int(initial.size());
        init(n);
        assert(n <= tree_n);

        for (int i = 0; i < n; i++)
            tree[tree_n + i] = initial[i];

        for (int position = tree_n - 1; position > 0; position--)
            tree[position].join(tree[2 * position], tree[2 * position + 1]);
    }

    segment query(int a, int b) const {
        assert(0 <= a && a <= b && b <= tree_n);
        segment answer;
        int r_size = 0;

        for (a += tree_n, b += tree_n; a < b; a /= 2, b /= 2) {
            if (a & 1)
                answer.join(tree[a++]);

            if (b & 1)
                right_half[r_size++] = --b;
        }

        for (int i = r_size - 1; i >= 0; i--)
            answer.join(tree[right_half[i]]);

        return answer;
    }

    segment query_single(int index) const {
        assert(0 <= index && index < tree_n);
        return tree[tree_n + index];
    }

    void join_up(int position) {
        while (position > 1) {
            position /= 2;
            tree[position].join(tree[2 * position], tree[2 * position + 1]);
        }
    }

    void update(int index, const segment &seg) {
        assert(0 <= index && index < tree_n);
        int position = tree_n + index;
        tree[position] = seg;
        join_up(position);
    }
};


int main() {
    ios::sync_with_stdio(false);
#ifndef NEAL_DEBUG
    cin.tie(nullptr);
#endif

    int N, M;
    string C;
    cin >> N >> M >> C;
    basic_seg_tree tree(N);
    vector<segment> initial(N);

    for (int i = 0; i < N; i++)
        initial[i] = segment(C[i] - '0');

    tree.build(initial);
    mod_matrix_fixed_size dp_start;
    dp_start[0][1] = 1;

    for (int q = 0; q < M; q++) {
        int x, d;
        cin >> x >> d;
        x--;
        tree.update(x, segment(d));
        cout << (dp_start * tree.tree[1].transition)[0][1] << '\n';
    }
}
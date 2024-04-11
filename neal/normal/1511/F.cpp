#include <algorithm>
#include <array>
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
        // Make sure MOD is prime, which is necessary for the inverse algorithm below.
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

        while (v >= SAVE_INV) {
            product *= MOD - MOD / v;
            v = MOD % v;
        }

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


// TODO: if using mod_column_vector, we can write the mod_matrix in the format matrix[x] = a row of coefficients used to
// build the x-th element of the mod_column_vector. So matrix[0][2] is the coefficient that element 2 contributes to the
// next element 0.
// The other option is to take a single-row 1 * n mod_matrix and multiply it by the n * n mod_matrix. Then matrix[0][2]
// is the coefficient that 0 contributes to the next element 2.
struct mod_column_vector {
    int rows;
    vector<mod_int> values;

    mod_column_vector(int _rows = 0) {
        init(_rows);
    }

    template<typename T>
    mod_column_vector(const vector<T> &v) {
        init(v);
    }

    void init(int _rows) {
        rows = _rows;
        values.assign(rows, 0);
    }

    template<typename T>
    void init(const vector<T> &v) {
        rows = int(v.size());
        values.resize(rows);

        for (int i = 0; i < rows; i++)
            values[i] = v[i];
    }

    mod_int& operator[](int index) { return values[index]; }
    const mod_int& operator[](int index) const { return values[index]; }
};

// Warning: very inefficient for many small matrices of fixed size. For that, use mod_matrix_fixed_size.cc instead.
struct mod_matrix {
    static const uint64_t U64_BOUND = numeric_limits<uint64_t>::max() - uint64_t(MOD) * MOD;

    int rows, cols;
    vector<vector<mod_int>> values;

    mod_matrix(int _rows = 0, int _cols = -1) {
        init(_rows, _cols);
    }

    template<typename T>
    mod_matrix(const vector<vector<T>> &v) {
        init(v);
    }

    void init(int _rows, int _cols = -1) {
        rows = _rows;
        cols = _cols < 0 ? rows : _cols;
        values.assign(rows, vector<mod_int>(cols, 0));
    }

    template<typename T>
    void init(const vector<vector<T>> &v) {
        rows = int(v.size());
        cols = v.empty() ? 0 : int(v[0].size());
        values.assign(rows, vector<mod_int>(cols, 0));

        for (int i = 0; i < rows; i++)
            for (int j = 0; j < cols; j++)
                values[i][j] = v[i][j];
    }

    vector<mod_int>& operator[](int index) { return values[index]; }
    const vector<mod_int>& operator[](int index) const { return values[index]; }

    bool is_square() const {
        return rows == cols;
    }

    void make_identity() {
        assert(is_square());

        for (int i = 0; i < rows; i++) {
            values[i].assign(cols, 0);
            values[i][i] = 1;
        }
    }

    mod_matrix operator*(const mod_matrix &other) const {
        assert(cols == other.rows);
        mod_matrix product(rows, other.cols);
        vector<uint64_t> row;

        for (int i = 0; i < rows; i++) {
            row.assign(other.cols, 0);

            for (int j = 0; j < cols; j++)
                if (values[i][j] != 0)
                    for (int k = 0; k < other.cols; k++) {
                        row[k] += uint64_t(values[i][j]) * uint64_t(other[j][k]);

                        if (row[k] > U64_BOUND)
                            row[k] %= MOD;
                    }

            for (int k = 0; k < other.cols; k++)
                product[i][k] = row[k];
        }

        return product;
    }

    mod_matrix& operator*=(const mod_matrix &other) {
        return *this = *this * other;
    }

    mod_column_vector operator*(const mod_column_vector &column) const {
        assert(cols == column.rows);
        mod_column_vector product(rows);

        for (int i = 0; i < rows; i++) {
            uint64_t result = 0;

            for (int j = 0; j < cols; j++) {
                result += uint64_t(values[i][j]) * uint64_t(column[j]);

                if (result > U64_BOUND)
                    result %= MOD;
            }

            product[i] = result;
        }

        return product;
    }

    mod_matrix power(int64_t p) const {
        assert(p >= 0);
        assert(is_square());
        mod_matrix m = *this;
        mod_matrix result(rows);
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
        cout << rows << ' ' << cols << '\n';

        for (int i = 0; i < rows; i++)
            for (int j = 0; j < cols; j++)
                cout << values[i][j] << (j < cols - 1 ? ' ' : '\n');
    }
};


const int LEN = 5;

int main() {
    ios::sync_with_stdio(false);
#ifndef NEAL_DEBUG
    cin.tie(nullptr);
#endif

    int N, M;
    cin >> N >> M;
    vector<string> words(N);
    vector<int> length(N);

    for (auto &word : words)
        cin >> word;

    for (int i = 0; i < N; i++)
        length[i] = int(words[i].size());

    auto is_word = [&](string str) -> bool {
        return find(words.begin(), words.end(), str) != words.end();
    };

    map<string, mod_int> save;

    auto solve_dp = y_combinator([&](auto self, string str) -> mod_int {
        if (str.empty())
            return 1;

        if (save.find(str) != save.end())
            return save[str];

        mod_int ans = 0;

        for (auto &word : words)
            if (str.size() >= word.size() && str.substr(0, word.size()) == word)
                ans += self(str.substr(word.size()));

        return save[str] = ans;
    });

    auto encode = [&](int len, int gap, int last) -> int {
        return (len * (LEN + 1) + gap) * N + last;
    };

    auto decode = [&](int encoded) -> array<int, 3> {
        int last = encoded % N;
        encoded /= N;
        int gap = encoded % (LEN + 1);
        encoded /= LEN + 1;
        int len = encoded;
        return {len, gap, last};
    };

    int DIM = LEN * (LEN + 1) * N;

    for (int x = 0; x < DIM; x++) {
        array<int, 3> decoded = decode(x);
        assert(encode(decoded[0], decoded[1], decoded[2]) == x);
    }

    mod_matrix adv_length(DIM, DIM);
    mod_matrix same_length(DIM, DIM);

    for (int a = 0; a < DIM; a++)
        for (int b = 0; b < DIM; b++) {
            array<int, 3> a_decode = decode(a);
            array<int, 3> b_decode = decode(b);

            int a_len = a_decode[0], a_gap = a_decode[1], a_last = a_decode[2];
            int b_len = b_decode[0], b_gap = b_decode[1], b_last = b_decode[2];
            b_len++;

            if (a_len > b_len)
                continue;

            if (a_len == b_len) {
                if (a_gap == b_gap && a_last == b_last)
                    adv_length[a][b] = 1;

                continue;
            }

            if (a_len > 0)
                continue;

            assert(a_len == 0 && a_len < b_len);

            if (length[a_last] >= a_gap && length[b_last] == a_gap + b_gap && b_gap == b_len - a_len) {
                if (words[a_last].substr(length[a_last] - a_gap) == words[b_last].substr(0, a_gap))
                    adv_length[a][b] = 1;
            }
        }

    for (int a = 0; a < DIM; a++)
        for (int b = 0; b < DIM; b++) {
            array<int, 3> a_decode = decode(a);
            array<int, 3> b_decode = decode(b);

            int a_len = a_decode[0], a_gap = a_decode[1], a_last = a_decode[2];
            int b_len = b_decode[0], b_gap = b_decode[1], b_last = b_decode[2];

            if (a_len == b_len) {
                if (a_last != b_last)
                    continue;

                if (a_gap == b_gap) {
                    same_length[a][b] = 1;
                    continue;
                }

                if (a_len == 0 && a_gap > b_gap && length[a_last] >= a_gap)
                    same_length[a][b] = solve_dp(words[a_last].substr(length[a_last] - a_gap, a_gap - b_gap));

                continue;
            }
        }

    mod_matrix transition = adv_length * same_length;

    mod_matrix initial(1, DIM);
    initial[0][0] = 1;
    mod_matrix result = initial * transition.power(M);
    mod_int total = 0;

    for (int i = 0; i < N; i++)
        total += result[0][encode(0, 0, i)];

    cout << total << '\n';
}
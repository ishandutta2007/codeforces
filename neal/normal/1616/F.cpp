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

    friend int abs(const _m_int &m) {
        return m.val;
    }
};

extern const int MOD = 3;
using mod_int = _m_int<MOD>;


// Warning: to check for invalid solutions, verify the original equations again afterward.
// If a variable has no constraints on it, it will be set to zero.
template<typename float_t>
struct gaussian {
    int n;
    vector<vector<float_t>> coefficients;
    vector<float_t> values;

    gaussian(int _n = 0) {
        init(_n);
    }

    void init(int _n) {
        n = _n;
        coefficients = {};
        values = {};
    }

    void add_equation(const vector<float_t> &coefs, float_t value) {
        assert(int(coefs.size()) == n);
        coefficients.push_back(coefs);
        values.push_back(value);
    }

    void swap_rows(int a, int b) {
        swap(coefficients[a], coefficients[b]);
        swap(values[a], values[b]);
    }

    // Eliminates `coefficients[target][col]` by canceling the `target` row with the `source` row.
    void eliminate(int target, int source, int col, int start_col = 0) {
        if (coefficients[target][col] == 0)
            return;

        assert(coefficients[source][col] != 0);
        float_t ratio = coefficients[target][col] / coefficients[source][col];

        for (int i = start_col; i < n; i++)
            coefficients[target][i] -= coefficients[source][i] * ratio;

        coefficients[target][col] = 0;
        values[target] -= values[source] * ratio;
    }

    vector<float_t> solve() {
        int rows = int(coefficients.size());
        vector<int> row_for_column(n, -1);
        int current_row = 0;

        for (int i = 0; i < n; i++) {
            int largest = current_row;

            for (int row = current_row + 1; row < rows; row++)
                if (abs(coefficients[row][i]) > abs(coefficients[largest][i]))
                    largest = row;

            if (current_row >= rows || coefficients[largest][i] == 0)
                continue;

            swap_rows(largest, current_row);
            row_for_column[i] = current_row;

            for (int row = current_row + 1; row < rows; row++)
                eliminate(row, current_row, i, i);

            current_row++;
        }

        vector<float_t> answers(n, 0);

        for (int i = n - 1; i >= 0; i--) {
            // If this variable has no constraints on it, set it to zero and continue.
            if (row_for_column[i] < 0)
                continue;

            current_row = row_for_column[i];

            for (int j = 0; j < i; j++)
                assert(coefficients[current_row][j] == 0);

            float_t value = values[current_row];

            for (int j = i + 1; j < n; j++)
                value -= coefficients[current_row][j] * answers[j];

            answers[i] = value / coefficients[current_row][i];
        }

        return answers;
    }
};


template<typename T_vector>
void output_vector(const T_vector &v, bool add_one = false, int start = -1, int end = -1) {
    if (start < 0) start = 0;
    if (end < 0) end = int(v.size());

    for (int i = start; i < end; i++)
        cout << v[i] + (add_one ? 1 : 0) << (i < end - 1 ? ' ' : '\n');
}


void run_case() {
    int N, M;
    cin >> N >> M;
    vector<vector<int>> edge_index(N, vector<int>(N, -1));
    vector<int> color(M, -1);

    for (int e = 0; e < M; e++) {
        int a, b, c;
        cin >> a >> b >> c;
        a--; b--;
        c -= c >= 0;
        edge_index[a][b] = edge_index[b][a] = e;
        color[e] = c;
    }

    gaussian<mod_int> solver(M);

    for (int e = 0; e < M; e++)
        if (color[e] >= 0) {
            vector<mod_int> coefs(M, 0);
            coefs[e] = 1;
            solver.add_equation(coefs, color[e]);
        }

    for (int i = 0; i < N; i++)
        for (int j = i + 1; j < N; j++)
            for (int k = j + 1; k < N; k++)
                if (edge_index[i][j] >= 0 && edge_index[j][k] >= 0 && edge_index[i][k] >= 0) {
                    vector<mod_int> coefs(M, 0);
                    coefs[edge_index[i][j]] = coefs[edge_index[j][k]] = coefs[edge_index[i][k]] = 1;
                    solver.add_equation(coefs, 0);
                }

    vector<mod_int> answers = solver.solve();

    for (int e = 0; e < M; e++)
        if (color[e] >= 0 && answers[e] != color[e]) {
            cout << -1 << '\n';
            return;
        }

    for (int i = 0; i < N; i++)
        for (int j = i + 1; j < N; j++)
            for (int k = j + 1; k < N; k++)
                if (edge_index[i][j] >= 0 && edge_index[j][k] >= 0 && edge_index[i][k] >= 0)
                    if (answers[edge_index[i][j]] + answers[edge_index[j][k]] + answers[edge_index[i][k]] != 0) {
                        cout << -1 << '\n';
                        return;
                    }

    output_vector(vector<int>(answers.begin(), answers.end()), true);
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
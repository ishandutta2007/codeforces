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

    friend int abs(const _m_int &m) {
        return m.val;
    }
};

template<const int &MOD> _m_int<MOD> _m_int<MOD>::save_inv[_m_int<MOD>::SAVE_INV];

extern const int MOD = 998244353;
using mod_int = _m_int<MOD>;

// Note: if there is a cycle, the size of the return will be less than n.
vector<int> topological_sort(const vector<vector<int>> &adj) {
    int n = int(adj.size());
    vector<int> in_degree(n, 0);
    vector<int> order;

    for (int i = 0; i < n; i++)
        for (int neighbor : adj[i])
            in_degree[neighbor]++;

    for (int i = 0; i < n; i++)
        if (in_degree[i] == 0)
            order.push_back(i);

    int current = 0;

    while (current < int(order.size())) {
        int node = order[current++];

        for (int neighbor : adj[node])
            if (--in_degree[neighbor] == 0)
                order.push_back(neighbor);
    }

    return order;
}

// Note: if a variable has no constraints on it, it will be set to zero.
template<typename float_t>
struct gaussian {
    int n;
    vector<vector<float_t>> coefficients;
    vector<float_t> values;
    bool solve_called;

    gaussian(int _n = 0) {
        init(_n);
    }

    void init(int _n) {
        n = _n;
        coefficients = {};
        values = {};
        solve_called = false;
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
        solve_called = true;
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

    template<typename T_bool>
    bool invalid(T_bool &&is_zero) const {
        assert(solve_called);
        int rows = int(coefficients.size());

        for (int row = 0; row < rows; row++)
            if (!is_zero(values[row]) && all_of(coefficients[row].begin(), coefficients[row].end(), is_zero))
                return true;

        return false;
    }
};


int main() {
    ios::sync_with_stdio(false);
#ifndef NEAL_DEBUG
    cin.tie(nullptr);
#endif

    int N, M;
    cin >> N >> M;
    vector<vector<int>> adj(N);

    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        adj[u].push_back(v);
    }

    vector<int> order = topological_sort(adj);
    vector<int> SG(N, -1);
    int S = 0;

    for (int i = N - 1; i >= 0; i--) {
        int x = order[i];
        int degree = int(adj[x].size());
        vector<bool> seen(degree + 1, false);
        SG[x] = 0;

        for (int neigh : adj[x])
            if (SG[neigh] <= degree)
                seen[SG[neigh]] = true;

        while (seen[SG[x]])
            SG[x]++;

        S = max(S, SG[x] + 1);
    }

    while (S & (S - 1))
        S++;

    vector<int> freq(S, 0);

    for (int i = 0; i < N; i++)
        freq[SG[i]]++;

    gaussian<mod_int> solver(S);

    for (int x = 0; x < S; x++) {
        vector<mod_int> coefs(S, 0);
        mod_int value = mod_int(x != 0) / (N + 1);
        coefs[x] = 1;

        for (int y = 0; y < S; y++)
            coefs[x ^ y] += mod_int(-freq[y]) / (N + 1);

        solver.add_equation(coefs, value);
    }

    cout << solver.solve()[0] << '\n';
}
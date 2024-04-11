#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

template<typename T> ostream& operator<<(ostream &os, const vector<T> &v) { os << '{'; string sep; for (const auto &x : v) os << sep << x, sep = ", "; return os << '}'; }
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
        val = v;
    }

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
    explicit operator int64_t() const { return val; }

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

    _m_int& operator*=(const _m_int &other) {
        val = fast_mod((uint64_t) val * other.val);
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

    bool operator==(const _m_int &other) const { return val == other.val; }
    bool operator!=(const _m_int &other) const { return val != other.val; }

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

            a *= a;
            p >>= 1;
        }

        return result;
    }

    friend ostream& operator<<(ostream &os, const _m_int &m) {
        return os << m.val;
    }
};

extern const int MOD = 1e9 + 7;
using mod_int = _m_int<MOD>;

extern const int CHECK_MOD = 2014437851;
using check_int = _m_int<CHECK_MOD>;

// https://csacademy.com/blog/fast-fourier-transform-and-variations-of-it
namespace walsh_hadamard {
    bool is_power_of_two(int n) {
        return (n & (n - 1)) == 0;
    }

    int round_up_power_two(int n) {
        while (n & (n - 1))
            n = (n | (n - 1)) + 1;

        return max(n, 1);
    }

    template<typename T>
    typename enable_if<is_integral<T>::value>::type divide_all(int n, vector<T> &values) {
        for (int i = 0; i < n; i++)
            values[i] >>= __builtin_ctz(n);
    }

    template<typename T>
    typename enable_if<!is_integral<T>::value>::type divide_all(int n, vector<T> &values) {
        T inv_n = T(1) / n;

        for (int i = 0; i < n; i++)
            values[i] *= inv_n;
    }

    template<typename T>
    void fwht_xor(int n, vector<T> &values, bool inverse = false) {
        assert(is_power_of_two(n));
        assert((int) values.size() >= n);

        for (int len = 1; len < n; len *= 2)
            for (int start = 0; start < n; start += 2 * len)
                for (int i = start; i < start + len; i++) {
                    T u = values[i];
                    const T &v = values[i + len];
                    values[i] = u + v;
                    values[i + len] = u - v;
                }

        if (inverse)
            divide_all(n, values);
    }

    // Warning: make sure to select the type `T_out` so that it can contain N^2 * max(left) * max(right).
    // One option is to use doubles and round at the end, since we are simply dividing by a power of two to finish.
    template<typename T_out, typename T_in>
    vector<T_out> xor_convolution(const vector<T_in> &_left, const vector<T_in> &_right) {
        if (_left.empty() || _right.empty())
            return {};

        vector<T_out> left(_left.begin(), _left.end());
        vector<T_out> right(_right.begin(), _right.end());

        int n = left.size();
        int m = right.size();

        int N = round_up_power_two(max(n, m));
        left.resize(N, 0);
        right.resize(N, 0);

        if (left == right) {
            fwht_xor(N, left);
            right = left;
        } else {
            fwht_xor(N, left);
            fwht_xor(N, right);
        }

        for (int i = 0; i < N; i++)
            left[i] *= right[i];

        fwht_xor(N, left, true);
        return left;
    }
}


const int BITS = 17;

struct edge {
    int node, weight;

    edge() {}

    edge(int _node, int _weight) : node(_node), weight(_weight) {}
};

int N, M;
vector<vector<edge>> adj;
vector<bool> visited;
vector<int> parent;
vector<int> depth;
vector<int> up_weight;
vector<vector<int>> cycles;

void dfs(int node, int par, int weight) {
    assert(!visited[node]);
    visited[node] = true;
    parent[node] = par;
    depth[node] = par < 0 ? 0 : depth[par] + 1;
    up_weight[node] = weight;

    for (edge &e : adj[node]) {
        if (e.node == par)
            continue;

        if (!visited[e.node]) {
            dfs(e.node, node, e.weight);
        } else if (depth[e.node] < depth[node]) {
            vector<int> cycle = {e.weight};
            int x = node;

            while (x != e.node) {
                cycle.push_back(up_weight[x]);
                x = parent[x];
            }

            cycles.push_back(cycle);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
#ifndef NEAL_DEBUG
    cin.tie(nullptr);
#endif

    cin >> N >> M;
    adj.assign(N, {});
    int all_xor = 0;

    for (int i = 0; i < M; i++) {
        int u, v, weight;
        cin >> u >> v >> weight;
        u--; v--;
        adj[u].emplace_back(v, weight);
        adj[v].emplace_back(u, weight);
        all_xor ^= weight;
    }

    visited.assign(N, false);
    parent.assign(N, -1);
    depth.assign(N, -1);
    up_weight.assign(N, -1);
    dfs(0, -1, 0);

    vector<mod_int> ways(1 << BITS, 0);
    ways[0] = 1;
    walsh_hadamard::fwht_xor(1 << BITS, ways);

    vector<check_int> check_ways(1 << BITS, 0);
    check_ways[0] = 1;
    walsh_hadamard::fwht_xor(1 << BITS, check_ways);

    for (vector<int> &cycle : cycles) {
        vector<mod_int> freq(1 << BITS, 0);
        vector<check_int> check_freq(1 << BITS, 0);

        for (int weight : cycle) {
            freq[weight]++;
            check_freq[weight]++;
        }

        walsh_hadamard::fwht_xor(1 << BITS, freq);
        walsh_hadamard::fwht_xor(1 << BITS, check_freq);

        for (int i = 0; i < 1 << BITS; i++) {
            ways[i] *= freq[i];
            check_ways[i] *= check_freq[i];
        }
    }

    walsh_hadamard::fwht_xor(1 << BITS, ways, true);
    walsh_hadamard::fwht_xor(1 << BITS, check_ways, true);

    int best = 1 << BITS;
    mod_int best_count = 0;

    for (int option = 0; option < 1 << BITS; option++)
        if ((ways[option] != 0 || check_ways[option] != 0) && (option ^ all_xor) < best) {
            best = option ^ all_xor;
            best_count = ways[option];
        }

    cout << best << ' ' << best_count << '\n';
}
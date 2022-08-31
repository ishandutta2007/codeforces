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
        return unsigned(x % m);
#endif
        // Optimized mod for Codeforces 32-bit machines.
        // x must be less than 2^32 * m for this to work, so that x / m fits in a 32-bit unsigned int.
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

extern const int MOD = 1e9 + 7;
using mod_int = _m_int<MOD>;

const int64_t INF64 = int64_t(2e18) + 5;

struct point {
    int64_t x, y;

    point() : x(0), y(0) {}

    point(int64_t _x, int64_t _y) : x(_x), y(_y) {}
};

// monotonic_dp_hull enables you to do the following two operations in amortized O(1) time:
// 1. Insert a pair (a_i, b_i) into the structure. a_i must be non-decreasing.
// 2. For any value of x, query the maximum value of a_i * x + b_i. x must be non-decreasing.
// All values a_i, b_i, and x can be positive or negative.
struct monotonic_dp_hull {
    vector<point> points;
    int front = 0;

    int size() const {
        return int(points.size()) - front;
    }

    void clear() {
        points.clear();
        front = 0;
        prev_x = -INF64;
    }

    static int64_t floor_div(int64_t a, int64_t b) {
        return a / b - ((a ^ b) < 0 && a % b != 0);
    }

    static bool bad_middle(const point &a, const point &b, const point &c) {
        // This checks whether the x-value where b beats a comes after the x-value where c beats b. It's fine to round
        // down here if we will only query integer x-values. (Note: plain C++ division rounds toward zero)
        return floor_div(a.y - b.y, b.x - a.x) >= floor_div(b.y - c.y, c.x - b.x);
    }

    void insert(const point &p) {
        assert(size() == 0 || p.x >= points.back().x);

        if (size() > 0 && p.x == points.back().x) {
            if (p.y <= points.back().y)
                return;

            points.pop_back();
        }

        while (size() >= 2 && bad_middle(points[points.size() - 2], points.back(), p))
            points.pop_back();

        points.push_back(p);
    }

    void insert(int64_t a, int64_t b) {
        insert(point(a, b));
    }

    bool first_suboptimal(int64_t x) const {
        return size() >= 2 && x * (points[front + 1].x - points[front].x) >= points[front].y - points[front + 1].y;
    }

    int64_t prev_x = -INF64;

    // Queries the maximum value of ax + b.
    int64_t query(int64_t x) {
        assert(size() > 0);
        assert(x >= prev_x);
        prev_x = x;

        while (first_suboptimal(x))
            front++;

        return points[front].x * x + points[front].y;
    }
};


struct edge {
    int node;
    int64_t weight;

    edge() {}

    edge(int _node, int64_t _weight) : node(_node), weight(_weight) {}
};

int main() {
    ios::sync_with_stdio(false);
#ifndef NEAL_DEBUG
    cin.tie(nullptr);
#endif

    int N, M, Q;
    cin >> N >> M >> Q;
    vector<vector<edge>> adj(N);

    for (int i = 0; i < M; i++) {
        int u, v, weight;
        cin >> u >> v >> weight;
        u--; v--;
        adj[u].emplace_back(v, weight);
        adj[v].emplace_back(u, weight);
    }

    vector<int64_t> longest(N, -INF64);
    longest[0] = 0;
    vector<array<int64_t, 2>> candidates;
    mod_int total = 0;

    for (int iter = 1; iter <= N; iter++) {
        vector<int64_t> next_longest(N, -INF64);

        for (int i = 0; i < N; i++)
            for (edge &e : adj[i])
                next_longest[e.node] = max(next_longest[e.node], longest[i] + e.weight);

        longest = next_longest;

        if (iter <= Q)
            total += *max_element(longest.begin(), longest.end());

        for (int i = 0; i < N; i++)
            for (edge &e : adj[i])
                candidates.push_back({e.weight, longest[i] - iter * e.weight});
    }

    sort(candidates.begin(), candidates.end());
    monotonic_dp_hull hull;

    for (auto &cand : candidates)
        hull.insert(cand[0], cand[1]);

    int64_t current = N + 1;

    while (current <= Q) {
        mod_int base = hull.query(current);
        int64_t low = current, high = Q + 1;

        while (low < high) {
            int64_t mid = (low + high) / 2;

            if (hull.first_suboptimal(mid))
                high = mid;
            else
                low = mid + 1;
        }

        mod_int count = low - current;
        mod_int diff = hull.points[hull.front].x;
        total += base * count + count * (count - 1) / 2 * diff;
        current = low;
    }

    cout << total << '\n';
}
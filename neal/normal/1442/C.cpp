#include <algorithm>
#include <array>
#include <cassert>
#include <iostream>
#include <queue>
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

    static void prepare_save() {
        // Make sure MOD is prime, which is necessary for the inverse algorithm below.
        for (int p = 2; p * p <= MOD; p += p % 2 + 1)
            assert(MOD % p != 0);

        save_inv[0] = 0;
        save_inv[1] = 1;

        for (int i = 2; i < SAVE_INV; i++)
            save_inv[i] = save_inv[MOD % i] * (MOD - MOD / i);
    }

    _m_int inv() const {
        if (save_inv[1] == 0)
            prepare_save();

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


const int64_t TIEBREAK = int64_t(1e9) + 5;
const int LOG = 21;
const int64_t INF64 = int64_t(2e18) + 5;

struct Dijkstra {
    struct state {
        int64_t dist;
        int node;
        int trans;

        state() {}

        state(int64_t _dist, int _node, int _trans) : dist(_dist), node(_node), trans(_trans) {}

        bool operator<(const state &other) const {
            return dist > other.dist;
        }
    };

    int n;
    vector<vector<int>> adj;
    vector<vector<int>> rev_adj;
    vector<int64_t> dist[LOG + 2];

    Dijkstra(int _n = 0) {
        init(_n);
    }

    void init(int _n) {
        n = _n;
        adj.assign(n, {});
        rev_adj.assign(n, {});
    }

    void add_directional_edge(int a, int b) {
        adj[a].push_back(b);
        rev_adj[b].push_back(a);
    }

    void dijkstra_check(priority_queue<state> &pq, int node, int trans, int64_t new_dist) {
        if (new_dist < dist[trans][node]) {
            dist[trans][node] = new_dist;
            pq.emplace(new_dist, node, trans);
        }
    }

    void dijkstra(const vector<int> &source) {
        for (int t = 0; t <= LOG + 1; t++)
            dist[t].assign(n, INF64);

        priority_queue<state> pq;

        for (int src : source)
            dijkstra_check(pq, src, 0, 0);

        auto increment = [&](int trans) {
            return trans <= LOG ? trans + 1 : trans - 1;
        };

        while (!pq.empty()) {
            state top = pq.top();
            pq.pop();

            if (top.dist > dist[top.trans][top.node])
                continue;

            const vector<int> &forward = top.trans % 2 == 0 ? adj[top.node] : rev_adj[top.node];
            const vector<int> &backward = top.trans % 2 == 0 ? rev_adj[top.node] : adj[top.node];

            for (int neigh : forward)
                dijkstra_check(pq, neigh, top.trans, top.dist + 1);

            int64_t additional = 0;

            if (top.trans >= LOG)
                additional = TIEBREAK;
            else if (top.trans == LOG - 1)
                additional = LOG * TIEBREAK;

            for (int neigh : backward)
                dijkstra_check(pq, neigh, increment(top.trans), top.dist + 1 + additional);
        }
    }
};


int main() {
    ios::sync_with_stdio(false);
#ifndef NEAL_DEBUG
    cin.tie(nullptr);
#endif

    int N, M;
    cin >> N >> M;
    Dijkstra dijkstra(N);

    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        dijkstra.add_directional_edge(u, v);
    }

    dijkstra.dijkstra({0});
    int64_t best = INF64;

    for (int t = 0; t < LOG; t++)
        best = min(best, ((1 << t) - 1) + dijkstra.dist[t][N - 1]);

    if (best < INF64 / 2) {
        cout << best % MOD << '\n';
        return 0;
    }

    int64_t encoded = min(dijkstra.dist[LOG][N - 1], dijkstra.dist[LOG + 1][N - 1]);
    int64_t power = encoded / TIEBREAK;
    int64_t moves = encoded % TIEBREAK;
    mod_int answer = mod_int(2).pow(power) - 1;
    answer += moves;
    cout << answer << '\n';
}
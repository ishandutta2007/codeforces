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

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;

// WARNING: functions as a set (doesn't allow duplicates); insert pairs instead if duplicates are needed.
// Consider using splay_tree instead if constant factor is an issue (e.g., log^2 solutions), especially with duplicates.
template<typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

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


auto random_address = [] { char *p = new char; delete p; return uint64_t(p); };

const uint64_t SEED = chrono::steady_clock::now().time_since_epoch().count() * (random_address() | 1);
mt19937_64 rng(SEED);


const int E_MAX = 1000005;

int main() {
    ios::sync_with_stdio(false);

    vector<mod_int> p2(E_MAX + 1, 1);

    for (int i = 1; i <= E_MAX; i++)
        p2[i] = 2 * p2[i - 1];

    int N1, N2, M;
    cin >> N1 >> N2 >> M;
    vector<int> edge_xor;
    vector<int> edge_color;
    vector<array<ordered_set<int>, 2>> adj(N1 + N2);
    vector<int> balance(N1 + N2, 0);
    mod_int hash = 0;

    auto get_other = [&](int index, int v) {
        return edge_xor[index] ^ v;
    };

    auto init_edge = [&](int index, int x, int y, int color) {
        edge_color[index] = color;
        hash += color * p2[index];
        balance[x] += 2 * color - 1;
        balance[y] += 2 * color - 1;
        adj[x][color].insert(index);
        adj[y][color].insert(index);
    };

    auto set_edge = [&](int index, int x, int y, int color) {
        int old_color = edge_color[index];
        hash -= old_color * p2[index];
        balance[x] -= 2 * old_color - 1;
        balance[y] -= 2 * old_color - 1;
        adj[x][old_color].erase(index);
        adj[y][old_color].erase(index);

        edge_color[index] = color;
        hash += color * p2[index];
        balance[x] += 2 * color - 1;
        balance[y] += 2 * color - 1;
        adj[x][color].insert(index);
        adj[y][color].insert(index);
    };

    auto correct_vertex = [&](int v, int avoid) {
        while (abs(balance[v]) > 1) {
            int too_many = balance[v] > 0;
            int index = -1;

            do {
                index = *adj[v][too_many].find_by_order(rng() % adj[v][too_many].size());
            } while (index == avoid);

            int other = get_other(index, v);
            set_edge(index, v, other, !too_many);
            v = other;
            avoid = index;
        }
    };

    auto add_edge = [&](int x, int y) {
        assert(0 <= x && x < N1 && N1 <= y && y < N1 + N2);
        int index = int(edge_xor.size());
        edge_xor.push_back(x ^ y);
        edge_color.push_back(0);

        if (balance[x] == 0 && balance[y] == 0) {
            init_edge(index, x, y, rng() % 2);
            return;
        }

        if (balance[x] <= 0 && balance[y] <= 0) {
            init_edge(index, x, y, 1);
            return;
        }

        if (balance[x] >= 0 && balance[y] >= 0) {
            init_edge(index, x, y, 0);
            return;
        }

        assert(balance[x] * balance[y] == -1);
        init_edge(index, x, y, rng() % 2);
        correct_vertex(abs(balance[x]) > 1 ? x : y, index);
    };

    for (int i = 0; i < M; i++) {
        int x, y;
        cin >> x >> y;
        x--; y--;
        y += N1;
        add_edge(x, y);
    }

    int Q;
    cin >> Q;

    for (int q = 0; q < Q; q++) {
        int type;
        cin >> type;

        if (type == 1) {
            int x, y;
            cin >> x >> y;
            x--; y--;
            y += N1;
            add_edge(x, y);
            cout << 2 * hash << endl;
        } else {
            int red = accumulate(edge_color.begin(), edge_color.end(), 0);
            cout << red;

            for (int i = 0; i < int(edge_color.size()); i++)
                if (edge_color[i] == 1)
                    cout << ' ' << i + 1;

            cout << endl;
        }
    }
}
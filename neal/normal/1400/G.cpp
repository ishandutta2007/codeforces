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


vector<mod_int> inv, factorial, inv_factorial;
int prepared_maximum = -1;

void prepare_factorials(int64_t maximum) {
    static int prepare_calls = 0;

    if (prepare_calls++ == 0) {
        // Make sure MOD is prime, which is necessary for the inverse algorithm below.
        for (int p = 2; p * p <= MOD; p += p % 2 + 1)
            assert(MOD % p != 0);

        inv = {0, 1};
        factorial = inv_factorial = {1, 1};
        prepared_maximum = 1;
    }

    if (maximum > prepared_maximum) {
        inv.resize(maximum + 1);
        factorial.resize(maximum + 1);
        inv_factorial.resize(maximum + 1);

        for (int i = prepared_maximum + 1; i <= maximum; i++) {
            inv[i] = inv[MOD % i] * (MOD - MOD / i);
            factorial[i] = i * factorial[i - 1];
            inv_factorial[i] = inv[i] * inv_factorial[i - 1];
        }

        prepared_maximum = int(maximum);
    }
}

mod_int choose(int64_t n, int64_t r) {
    if (r < 0 || r > n) return 0;
    return factorial[n] * inv_factorial[r] * inv_factorial[n - r];
}

mod_int inv_choose(int64_t n, int64_t r) {
    assert(0 <= r && r <= n);
    return inv_factorial[n] * factorial[r] * factorial[n - r];
}

mod_int permute(int64_t n, int64_t r) {
    if (r < 0 || r > n) return 0;
    return factorial[n] * inv_factorial[n - r];
}

mod_int inv_permute(int64_t n, int64_t r) {
    assert(0 <= r && r <= n);
    return inv_factorial[n] * factorial[n - r];
}

struct union_find {
    // When data[x] < 0, x is a root and -data[x] is its tree size. When data[x] >= 0, data[x] is x's parent.
    vector<int> data;
    int components = 0;

    union_find(int n = -1) {
        if (n >= 0)
            init(n);
    }

    void init(int n) {
        data.assign(n + 1, -1);
        components = n;
    }

    int find(int x) {
        return data[x] < 0 ? x : data[x] = find(data[x]);
    }

    int get_size(int x) {
        return -data[find(x)];
    }

    bool unite(int x, int y) {
        x = find(x);
        y = find(y);

        if (x == y)
            return false;

        if (-data[x] < -data[y])
            swap(x, y);

        data[x] += data[y];
        data[y] = x;
        components--;
        return true;
    }
};


int N, M;
vector<int> L, R;
vector<vector<int>> adj;
vector<vector<int>> components;
vector<vector<vector<int>>> component_dp;
// vector<int> which_component;

bool edge_exists(int a, int b) {
    return binary_search(adj[a].begin(), adj[a].end(), b);
}

int main() {
    ios::sync_with_stdio(false);
#ifndef NEAL_DEBUG
    cin.tie(nullptr);
#endif

    cin >> N >> M;
    prepare_factorials(N);
    L.resize(N);
    R.resize(N);

    for (int i = 0; i < N; i++)
        cin >> L[i] >> R[i];

    adj.assign(N, {});
    union_find UF(N);

    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
        UF.unite(a, b);
    }

    for (int i = 0; i < N; i++)
        sort(adj[i].begin(), adj[i].end());

    for (int root = 0; root < N; root++)
        if (UF.find(root) == root && UF.get_size(root) > 1) {
            vector<int> component;

            for (int i = 0; i < N; i++)
                if (UF.find(i) == root)
                    component.push_back(i);

            components.push_back(component);
        }

    // which_component.assign(N, -1);

    // for (int c = 0; c < int(components.size()); c++)
    //     for (int x : components[c])
    //         which_component[x] = c;

    component_dp.assign(components.size(), {});

    for (int c = 0; c < int(components.size()); c++) {
        auto &component = components[c];
        auto &dp = component_dp[c];
        int C = int(component.size());
        vector<vector<bool>> bad(C, vector<bool>(C, false));

        for (int i = 0; i < C; i++)
            for (int j = i + 1; j < C; j++)
                bad[i][j] = edge_exists(component[i], component[j]);

        dp.assign(1 << C, vector<int>(C + 1, 0));

        for (int mask = 0; mask < 1 << C; mask++) {
            bool works = true;

            for (int i = 0; i < C && works; i++)
                if (mask >> i & 1)
                    for (int j = i + 1; j < C && works; j++)
                        if ((mask >> j & 1) && bad[i][j])
                            works = false;

            if (works)
                dp[mask][__builtin_popcount(mask)] = 1;
        }

        for (int bit = 0; bit < C; bit++)
            for (int mask = 0; mask < 1 << C; mask++)
                if ((mask >> bit & 1) == 0)
                    for (int i = 0; i < C; i++)
                        dp[mask | 1 << bit][i] += dp[mask][i];

        dbg(dp);
    }

    vector<int> freq(N + 2, 0);

    for (int i = 0; i < N; i++) {
        freq[L[i]]++;
        freq[R[i] + 1]--;
    }

    for (int i = 1; i <= N; i++)
        freq[i] += freq[i - 1];

    mod_int answer = 0;

    for (int num = 1; num <= N; num++) {
        int merc = freq[num];
        vector<mod_int> knapsack(2 * M + 1, 0);
        knapsack[0] = 1;
        int in_component = 0;

        for (int c = 0; c < int(components.size()); c++) {
            auto &component = components[c];
            int C = int(component.size());
            int mask = 0;

            for (int i = 0; i < C; i++)
                if (L[component[i]] <= num && num <= R[component[i]])
                    mask |= 1 << i;

            in_component += __builtin_popcount(mask);

            for (int count = M - 1; count >= 0; count--)
                for (int add = 1; add <= C; add++)
                    knapsack[count + add] += knapsack[count] * component_dp[c][mask][add];
        }

        for (int have = 0; have <= M; have++)
            answer += knapsack[have] * choose(merc - in_component, num - have);
    }

    cout << answer << '\n';
}
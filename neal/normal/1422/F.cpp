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

extern const int MOD = 1e9 + 7;
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


struct segment_change {
    mod_int to_multiply;

    segment_change(mod_int _to_multiply = 1) : to_multiply(_to_multiply) {}
};

struct segment {
    mod_int product;

    segment(mod_int _product = 1) : product(_product) {}

    void apply(int length, const segment_change &change) {
        assert(length == 1);

        if (change.to_multiply != 1)
            product *= change.to_multiply;
    }

    void join(const segment &other) {
        product *= other.product;
    }

    void join(const segment &a, const segment &b) {
        *this = a;
        join(b);
    }
};

struct persistent_basic_seg_tree {
    struct node {
        segment seg;
        int left = -1, right = -1;
    };

    int tree_n = 0;
    vector<node> tree;

    persistent_basic_seg_tree(int n = -1, int reserve_size = 0) {
        if (n >= 0)
            init(n, reserve_size);
    }

    void init(int n, int reserve_size = 0) {
        tree_n = 1;

        while (tree_n < n)
            tree_n *= 2;

        if (reserve_size > 0)
            tree.reserve(reserve_size);

        tree.assign(2 * tree_n, node());

        for (int i = 1; i < tree_n; i++) {
            tree[i].left = 2 * i;
            tree[i].right = 2 * i + 1;
        }
    }

    int left(int position) const { return tree[position].left; }
    int right(int position) const { return tree[position].right; }
    segment& seg(int position) { return tree[position].seg; }
    const segment& seg(int position) const { return tree[position].seg; }

    // Builds our tree from an array in O(n).
    void build(const vector<segment> &initial) {
        int n = int(initial.size());
        init(n);
        assert(n <= tree_n);

        for (int i = 0; i < n; i++)
            seg(tree_n + i) = initial[i];

        for (int position = tree_n - 1; position > 0; position--)
            seg(position).join(seg(left(position)), seg(right(position)));
    }

    int make_copy(int position) {
        assert(0 <= position && position < int(tree.size()));
        tree.push_back(tree[position]);
        return int(tree.size()) - 1;
    }

    void _query_tree(int position, int start, int end, int a, int b, segment &answer) const {
        if (a <= start && end <= b) {
            answer.join(seg(position));
            return;
        }

        if (left(position) < 0 || right(position) < 0)
            return;

        int mid = (start + end) / 2;
        if (a < mid) _query_tree(left(position), start, mid, a, b, answer);
        if (b > mid) _query_tree(right(position), mid, end, a, b, answer);
    }

    segment query(int root, int a, int b) const {
        assert(0 <= a && a <= b && b <= tree_n);
        segment answer;
        _query_tree(root, 0, tree_n, a, b, answer);
        return answer;
    }

    // Directly assigning `tree[position].left = make_copy(left(position))` results in segmentation faults, because the
    // address for `tree[position]` can be computed before calling `make_copy`, which may reallocate `tree`.
    void set_left(int position, int result) { tree[position].left = result; }
    void set_right(int position, int result) { tree[position].right = result; }

    int _update_tree(int position, int start, int end, int index, const segment_change &change) {
        position = make_copy(position);

        if (end - start == 1 && start == index) {
            seg(position).apply(end - start, change);
            return position;
        }

        if (left(position) < 0 || right(position) < 0)
            return position;

        int mid = (start + end) / 2;

        if (index < mid)
            set_left(position, _update_tree(left(position), start, mid, index, change));
        else
            set_right(position, _update_tree(right(position), mid, end, index, change));

        seg(position).join(seg(left(position)), seg(right(position)));
        return position;
    }

    int update(int root, int index, const segment_change &change) {
        assert(0 <= index && index < tree_n);
        return _update_tree(root, 0, tree_n, index, change);
    }

    vector<segment> to_array(int root) const {
        vector<int> level = {root};

        while (left(level.front()) >= 0) {
            vector<int> new_level;
            new_level.reserve(2 * level.size());

            for (int x : level) {
                new_level.push_back(left(x));
                new_level.push_back(right(x));
            }

            swap(level, new_level);
        }

        vector<segment> segs(level.size());

        for (int i = 0; i < int(level.size()); i++)
            segs[i] = seg(level[i]);

        return segs;
    }
};

vector<int> smallest_factor;
vector<bool> prime;
vector<int> primes;

void sieve(int maximum) {
    maximum = max(maximum, 1);
    smallest_factor.assign(maximum + 1, 0);
    prime.assign(maximum + 1, true);
    prime[0] = prime[1] = false;
    primes = {};

    for (int p = 2; p <= maximum; p++)
        if (prime[p]) {
            smallest_factor[p] = p;
            primes.push_back(p);

            for (int64_t i = int64_t(p) * p; i <= maximum; i += p)
                if (prime[i]) {
                    prime[i] = false;
                    smallest_factor[i] = p;
                }
        }
}

// Prime factorizes n in worst case O(sqrt n / log n). Requires having run `sieve` up to at least sqrt(n).
// If we've run `sieve` up to at least n, takes O(log n) time.
vector<pair<int64_t, int>> prime_factorize(int64_t n) {
    int64_t sieve_max = int64_t(smallest_factor.size()) - 1;
    assert(1 <= n && n <= sieve_max * sieve_max);
    vector<pair<int64_t, int>> result;

    if (n <= sieve_max) {
        while (n != 1) {
            int64_t p = smallest_factor[n];
            int exponent = 0;

            do {
                n /= p;
                exponent++;
            } while (n % p == 0);

            result.emplace_back(p, exponent);
        }

        return result;
    }

    for (int64_t p : primes) {
        if (p * p > n)
            break;

        if (n % p == 0) {
            result.emplace_back(p, 0);

            do {
                n /= p;
                result.back().second++;
            } while (n % p == 0);
        }
    }

    if (n > 1)
        result.emplace_back(n, 1);

    return result;
}


const int N_MAX = 1e5 + 5;
const int TREE_HEIGHT = 32 - __builtin_clz(N_MAX);
const int A_MAX = 2e5 + 5;
const int MAX_PRIMES = 6;
const int RESERVE_SIZE = N_MAX * MAX_PRIMES * 3 * (TREE_HEIGHT + 1) + (2 << TREE_HEIGHT);

int main() {
    ios::sync_with_stdio(false);
#ifndef NEAL_DEBUG
    cin.tie(nullptr);
#endif

    sieve(A_MAX);
    prepare_factorials(A_MAX);

    int N;
    cin >> N;
    vector<int> A(N);

    for (auto &a : A)
        cin >> a;

    vector<vector<pair<int, int>>> prime_stack(A_MAX);
    persistent_basic_seg_tree tree(N, RESERVE_SIZE);
    int root = 1;
    vector<int> roots(N + 1, -1);
    roots[0] = root;

    for (int end = 1; end <= N; end++) {
        int index = end - 1;
        auto prime_factors = prime_factorize(A[index]);

        for (auto &pr : prime_factors) {
            int p = int(pr.first);
            int e = pr.second;
            int previous = 0;

            while (!prime_stack[p].empty() && e >= prime_stack[p].back().first) {
                int back_e = prime_stack[p].back().first;
                int back_index = prime_stack[p].back().second;
                root = tree.update(root, back_index, segment_change(inv[p].pow(back_e - previous)));
                previous = back_e;
                prime_stack[p].pop_back();
            }

            if (!prime_stack[p].empty()) {
                int back_index = prime_stack[p].back().second;
                root = tree.update(root, back_index, segment_change(inv[p].pow(e - previous)));
            }

            prime_stack[p].emplace_back(e, index);
            root = tree.update(root, index, segment_change(mod_int(p).pow(e)));
        }

        roots[end] = root;
    }

    int Q;
    cin >> Q;
    int answer = 0;

    for (int q = 0; q < Q; q++) {
        int x, y;
        cin >> x >> y;
        int L = (answer + x) % N + 1;
        int R = (answer + y) % N + 1;

        if (L > R)
            swap(L, R);

        L--;
        answer = int(tree.query(roots[R], L, R).product);
        cout << answer << '\n';
    }
}
#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;


template<typename T>
struct fenwick_tree {
    int tree_n = 0;
    vector<T> tree;

    fenwick_tree(int n = 0) {
        if (n > 0)
            init(n);
    }

    void init(int n) {
        tree_n = n;
        tree.assign(tree_n + 1, 0);
    }

    // O(n) initialization of the Fenwick tree.
    void build(const auto &initial) {
        assert((int) initial.size() == tree_n);

        for (int i = 1; i <= tree_n; i++) {
            tree[i] = initial[i - 1];

            for (int k = (i & -i) >> 1; k > 0; k >>= 1)
                tree[i] += tree[i - k];
        }
    }

    // index is in [0, tree_n).
    void update(int index, const T &change) {
        assert(0 <= index && index < tree_n);

        for (int i = index + 1; i <= tree_n; i += i & -i)
            tree[i] += change;
    }

    // Returns the sum of the range [0, count).
    T query(int count) const {
        assert(count <= tree_n);
        T sum = 0;

        for (int i = count; i > 0; i -= i & -i)
            sum += tree[i];

        return sum;
    }

    // Returns the sum of the range [a, b).
    T query(int a, int b) const {
        return query(b) - query(a);
    }

    // Returns the element at index a in O(1) amortized across every index. Equivalent to query(a, a + 1).
    T get(int a) const {
        assert(0 <= a && a < tree_n);
        int above = a + 1;
        T sum = tree[above];
        above -= above & -above;

        while (a != above) {
            sum -= tree[a];
            a -= a & -a;
        }

        return sum;
    }

    // Returns the last i in [0, N] such that tree_query(i) <= sum, or -1 if no such i exists.
    int find_last_prefix(T sum) const {
        if (sum < 0)
            return -1;

        int prefix = 0;

        for (int k = 31 - __builtin_clz(tree_n); k >= 0; k--)
            if (prefix + (1 << k) <= tree_n && tree[prefix + (1 << k)] <= sum) {
                prefix += 1 << k;
                sum -= tree[prefix];
            }

        return prefix;
    }
};


const int MOD = 998244353;

int mod_add(int a, int b, int m = MOD) {
    int sum = a + b;
    return sum >= m ? sum - m : sum;
}

int mod_sub(int a, int b, int m = MOD) {
    int diff = a - b;
    return diff < 0 ? diff + m : diff;
}

int mod_mul(int a, int b, int m = MOD) {
#if !defined(_WIN32) || defined(_WIN64)
    return (uint64_t) a * b % m;
#endif
    // Mod multiplication optimized for Codeforces 32-bit machines.
    uint64_t x = (uint64_t) a * b;
    unsigned x_high = x >> 32, x_low = (unsigned) x;
    unsigned quot, rem;
    asm(
        "divl %4; \n\t"
        : "=a" (quot), "=d" (rem)
        : "d" (x_high), "a" (x_low), "r" (m)
    );
    return rem;
}

int mod_inv(int a, int m = MOD) {
    return a == 1 ? 1 : m - (uint64_t) mod_inv(m % a, a) * m / a;
}

int mod_pow(int a, long long p, int m = MOD) {
    assert(p >= 0);
    int result = 1;

    while (p > 0) {
        if (p & 1)
            result = mod_mul(result, a, m);

        a = mod_mul(a, a, m);
        p >>= 1;
    }

    return result;
}

struct mod_value {
    int value;

    mod_value() {
        value = 0;
    }

    mod_value(long long v, bool skip_checks = false) {
        if (!skip_checks) {
            if (v < 0)
                v = v % MOD + MOD;

            if (v >= MOD)
                v %= MOD;
        }

        value = v;
    }

    explicit operator int() const {
        return value;
    }

    mod_value& operator+=(const mod_value &other) {
        value = mod_add(value, other.value);
        return *this;
    }

    mod_value& operator-=(const mod_value &other) {
        value = mod_sub(value, other.value);
        return *this;
    }

    mod_value& operator*=(const mod_value &other) {
        value = mod_mul(value, other.value);
        return *this;
    }

    mod_value operator+(const mod_value &other) const {
        return mod_value(*this) += other;
    }

    mod_value operator-(const mod_value &other) const {
        return mod_value(*this) -= other;
    }

    mod_value operator*(const mod_value &other) const {
        return mod_value(*this) *= other;
    }

    mod_value& operator++() {
        value = value == MOD - 1 ? 0 : value + 1;
        return *this;
    }

    mod_value operator++(int) {
        mod_value before = *this;
        ++*this;
        return before;
    }

    mod_value& operator--() {
        value = value == 0 ? MOD - 1 : value - 1;
        return *this;
    }

    mod_value operator--(int) {
        mod_value before = *this;
        --*this;
        return before;
    }

    mod_value operator-() const {
        return mod_value(value == 0 ? 0 : MOD - value, true);
    }

    mod_value inv() const {
        return mod_value(mod_inv(value), true);
    }

    bool operator<(const mod_value &other) const {
        return value < other.value;
    }

    bool operator>(const mod_value &other) const {
        return value > other.value;
    }

    bool operator<=(const mod_value &other) const {
        return value <= other.value;
    }

    bool operator>=(const mod_value &other) const {
        return value >= other.value;
    }

    bool operator==(const mod_value &other) const {
        return value == other.value;
    }

    bool operator!=(const mod_value &other) const {
        return value != other.value;
    }
};

ostream& operator<<(ostream& out, const mod_value &mv) {
    return out << (int) mv;
}

istream& operator>>(istream& in, mod_value &mv) {
    int x;
    in >> x;
    mv = x;
    return in;
}


int main() {
    int N;
    scanf("%d", &N);
    vector<int> P(N);
    vector<bool> seen(N + 1, false);
    mod_value M = 0;

    for (int &p : P) {
        scanf("%d", &p);

        if (p < 0) {
            M++;
            p = 0;
        }

        seen[p] = true;
    }

    vector<int> missing_values;

    for (int i = 1; i <= N; i++)
        if (!seen[i])
            missing_values.push_back(i);

    assert((int) missing_values.size() == (int) M);
    mod_value answer = mod_value(M) * mod_value(M - 1) * mod_value(4).inv();
    fenwick_tree<int> tree(N + 1);
    mod_value inversions = 0;

    for (int i = N - 1; i >= 0; i--)
        if (P[i] > 0) {
            inversions += tree.query(P[i]);
            tree.update(P[i], +1);
        }

    answer += inversions;
    mod_value sum = 0, running_count = 0;

    for (int i = 0; i < N; i++)
        if (P[i] > 0) {
            int location = lower_bound(missing_values.begin(), missing_values.end(), P[i]) - missing_values.begin();
            sum += running_count * (M - location) + (M - running_count) * location;
        } else {
            running_count++;
        }

    if (M > 0)
        sum *= mod_value(M).inv();

    answer += sum;
    cout << answer << '\n';
}
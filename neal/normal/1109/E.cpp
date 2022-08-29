#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int MOD = 0;

inline int mod_add(int a, int b, int m = MOD) {
    int sum = a + b;
    return sum >= m ? sum - m : sum;
}

inline int mod_sub(int a, int b, int m = MOD) {
    int diff = a - b;
    return diff < 0 ? diff + m : diff;
}

inline unsigned fast_mod(uint64_t x, unsigned m = MOD) {
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

inline int fast_mod_mul(int a, int b, int m = MOD) {
    assert(a < m && b < m);
    return fast_mod((uint64_t) a * b, m);
}

inline int mod_mul(int a, int b, int m = MOD) {
    return (uint64_t) a * b % m;
}

inline int mod_pow(int a, long long p, int m = MOD) {
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

inline int mod_inv(int a, int m = MOD) {
    // https://en.wikipedia.org/wiki/Extended_Euclidean_algorithm#Example
    int g = m, r = a, x = 0, y = 1;

    while (r != 0) {
        int q = g / r;
        g %= r; swap(g, r);
        x -= q * y; swap(x, y);
    }

    assert(g == 1);
    assert(y == m || y == -m);
    return x < 0 ? x + m : x;
}

const int P_MAX = 10;

int P;
int primes[P_MAX];

struct segment_change {
    int original_mul, relatively_prime;
    int powers[P_MAX];

    segment_change(int _mul = 1, int _div = 1) {
        fill_n(powers, P_MAX, 0);
        original_mul = _mul % MOD;

        for (int i = 0; i < P; i++) {
            while (_mul % primes[i] == 0) {
                _mul /= primes[i];
                powers[i]++;
            }

            while (_div % primes[i] == 0) {
                _div /= primes[i];
                powers[i]--;
            }
        }

        relatively_prime = mod_mul(_mul, mod_inv(_div));
    }

    void reset() {
        original_mul = relatively_prime = 1;
        fill_n(powers, P_MAX, 0);
    }

    // Return the combined result of applying this segment change followed by `other`.
    segment_change combine(const segment_change &other) const {
        segment_change combined;
        combined.relatively_prime = mod_mul(relatively_prime, other.relatively_prime);
        combined.original_mul = mod_mul(original_mul, other.original_mul);

        for (int i = 0; i < P; i++)
            combined.powers[i] = powers[i] + other.powers[i];

        return combined;
    }
};

struct segment {
    int sum, relatively_prime;
    int powers[P_MAX];

    segment(int _sum = 0) : sum(_sum) {
        fill_n(powers, P_MAX, 0);

        if (sum == 0)
            return;

        relatively_prime = sum;

        for (int i = 0; i < P; i++)
            while (relatively_prime % primes[i] == 0) {
                relatively_prime /= primes[i];
                powers[i]++;
            }

        sum %= MOD;
        relatively_prime %= MOD;
    }

    void apply(int length, const segment_change &change) {
        sum = mod_mul(sum, change.original_mul);
        relatively_prime = mod_mul(relatively_prime, change.relatively_prime);

        for (int i = 0; i < P; i++)
            powers[i] += change.powers[i];

        if (length == 1) {
            sum = relatively_prime;

            for (int i = 0; i < P; i++)
                sum = mod_mul(sum, mod_pow(primes[i], powers[i]));
        }
    }

    void join(const segment &other) {
        for (int i = 0; i < P; i++)
            powers[i] = min(powers[i], other.powers[i]);

        sum = mod_add(sum, other.sum);
    }

    // TODO: decide whether to re-implement this for better performance. Mainly relevant when segments contain arrays.
    void join(const segment &a, const segment &b) {
        *this = a;
        join(b);
    }
};

struct seg_tree {
    int tree_n = 0;
    vector<segment> tree;
    vector<segment_change> changes;

    seg_tree(int n = 0) {
        if (n > 0)
            init(n);
    }

    void init(int n) {
        tree_n = 1;

        while (tree_n < n)
            tree_n *= 2;

        tree.assign(2 * tree_n, segment());
        changes.assign(tree_n, segment_change());
    }

    // O(n) initialization of our tree.
    void build(const vector<segment> &initial) {
        int n = initial.size();
        assert(n <= tree_n);

        for (int i = 0; i < n; i++)
            tree[tree_n + i] = initial[i];

        for (int position = tree_n - 1; position > 0; position--)
            tree[position].join(tree[2 * position], tree[2 * position + 1]);
    }

    void push_down(int position, int length) {
        if (2 * position < tree_n) {
            changes[2 * position] = changes[2 * position].combine(changes[position]);
            changes[2 * position + 1] = changes[2 * position + 1].combine(changes[position]);
        }

        tree[2 * position].apply(length / 2, changes[position]);
        tree[2 * position + 1].apply(length / 2, changes[position]);
        changes[position].reset();
    }

    template<typename T_range_op>
    void process_range(int position, int start, int end, int a, int b, bool needs_join, T_range_op &&range_op) {
        if (a <= start && end <= b) {
            range_op(position, end - start);
            return;
        }

        if (position >= tree_n)
            return;

        push_down(position, end - start);
        int mid = (start + end) / 2;
        if (a < mid) process_range(2 * position, start, mid, a, b, needs_join, range_op);
        if (b > mid) process_range(2 * position + 1, mid, end, a, b, needs_join, range_op);
        if (needs_join) tree[position].join(tree[2 * position], tree[2 * position + 1]);
    }

    segment query(int a, int b) {
        segment answer;

        process_range(1, 0, tree_n, a, b, false, [&](int position, int) {
            answer.join(tree[position]);
        });

        return answer;
    }

    void update(int a, int b, const segment_change &change) {
        process_range(1, 0, tree_n, a, b, true, [&](int position, int length) {
            tree[position].apply(length, change);
            if (position < tree_n) changes[position] = changes[position].combine(change);
        });
    }
};

void compute_primes(int mod) {
    P = 0;

    for (int p = 2; p * p <= mod; p++)
        if (mod % p == 0) {
            primes[P++] = p;

            do {
                mod /= p;
            } while (mod % p == 0);
        }

    if (mod > 1)
        primes[P++] = mod;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, Q;
    cin >> N >> MOD;
    compute_primes(MOD);
    vector<segment> initial(N);

    for (int i = 0; i < N; i++) {
        int a;
        cin >> a;
        initial[i] = segment(a);
    }

    seg_tree tree(N);
    tree.build(initial);
    cin >> Q;

    for (int q = 0; q < Q; q++) {
        int type, L, R, X;
        cin >> type;

        if (type == 1) {
            cin >> L >> R >> X;
            L--;
            tree.update(L, R, segment_change(X));
        } else if (type == 2) {
            cin >> L >> X;
            L--;
            tree.update(L, L + 1, segment_change(1, X));
        } else if (type == 3) {
            cin >> L >> R;
            L--;
            cout << tree.query(L, R).sum << '\n';
        } else {
            assert(false);
        }
    }
}
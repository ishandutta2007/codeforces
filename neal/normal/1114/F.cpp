#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

namespace IO {
    const int BUFFER_SIZE = 1 << 15;

    char input_buffer[BUFFER_SIZE];
    int input_pos = 0, input_len = 0;

    char output_buffer[BUFFER_SIZE];
    int output_pos = 0;

    char number_buffer[100];
    uint8_t lookup[100];

    void _update_input_buffer() {
        input_len = fread(input_buffer, sizeof(char), BUFFER_SIZE, stdin);
        input_pos = 0;

        if (input_len == 0)
            input_buffer[0] = EOF;
    }

    inline char next_char(bool advance = true) {
        if (input_pos >= input_len)
            _update_input_buffer();

        return input_buffer[advance ? input_pos++ : input_pos];
    }

    template<typename T>
    inline void read_int(T &number) {
        bool negative = false;
        number = 0;

        while (!isdigit(next_char(false)))
            if (next_char() == '-')
                negative = true;

        do {
            number = 10 * number + (next_char() - '0');
        } while (isdigit(next_char(false)));

        if (negative)
            number = -number;
    }

    template<typename T, typename... Args>
    inline void read_int(T &number, Args &... args) {
        read_int(number);
        read_int(args...);
    }

    inline void read_str(string &str) {
        while (isspace(next_char(false)))
            next_char();

        str.clear();

        do {
            str += next_char();
        } while (!isspace(next_char(false)));
    }

    void _flush_output() {
        fwrite(output_buffer, sizeof(char), output_pos, stdout);
        output_pos = 0;
    }

    inline void write_char(char c) {
        if (output_pos == BUFFER_SIZE)
            _flush_output();

        output_buffer[output_pos++] = c;
    }

    template<typename T>
    inline void write_int(T number, char after = '\0') {
        if (number < 0) {
            write_char('-');
            number = -number;
        }

        int length = 0;

        while (number >= 10) {
            uint8_t lookup_value = lookup[number % 100];
            number /= 100;
            number_buffer[length++] = (lookup_value & 15) + '0';
            number_buffer[length++] = (lookup_value >> 4) + '0';
        }

        if (number != 0 || length == 0)
            write_char(number + '0');

        for (int i = length - 1; i >= 0; i--)
            write_char(number_buffer[i]);

        if (after)
            write_char(after);
    }

    void init() {
        // Make sure _flush_output() is called at the end of the program.
        bool exit_success = atexit(_flush_output) == 0;
        assert(exit_success);

        for (int i = 0; i < 100; i++)
            lookup[i] = (i / 10 << 4) + i % 10;
    }
}

const int MOD = 1e9 + 7;

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
    assert(x_high < m);
    asm("divl %4\n"
        : "=a" (quot), "=d" (rem)
        : "d" (x_high), "a" (x_low), "r" (m));
    return rem;
}

inline int mod_mul(int a, int b, int m = MOD) {
    return fast_mod((uint64_t) a * b, m);
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

vector<int> smallest_factor;
vector<bool> prime;
vector<int> primes;
vector<int> prime_index;

void sieve(int maximum) {
    maximum = max(maximum, 2);
    smallest_factor.assign(maximum + 1, 0);
    prime.assign(maximum + 1, true);
    prime_index.assign(maximum + 1, -1);
    prime[0] = prime[1] = false;
    primes = {};

    for (long long p = 2; p <= maximum; p++)
        if (prime[p]) {
            smallest_factor[p] = p;
            prime_index[p] = primes.size();
            primes.push_back(p);

            for (long long i = p * p; i <= maximum; i += p)
                if (prime[i]) {
                    prime[i] = false;
                    smallest_factor[i] = p;
                }
        }
}

const int A_MAX = 300;
const int P = 62;

uint64_t number_to_mask(int x) {
    uint64_t prime_mask = 0;

    while (x != 1) {
        int p = smallest_factor[x];
        prime_mask |= 1LLU << prime_index[p];

        do {
            x /= p;
        } while (x % p == 0);
    }

    return prime_mask;
}

struct segment_change {
    int x;
    uint64_t prime_mask;

    segment_change(int _x = 1, uint64_t _prime_mask = 0) : x(_x), prime_mask(_prime_mask) {
        if (prime_mask == 0)
            prime_mask = number_to_mask(x);
    }

    void reset() {
        x = 1;
        prime_mask = 0;
    }

    bool has_change() const {
        return x != 1;
    }

    // Return the combined result of applying this segment change followed by `other`.
    segment_change combine(const segment_change &other) const {
        return segment_change(mod_mul(x, other.x), prime_mask | other.prime_mask);
    }
};

struct segment {
    int product;
    uint64_t prime_mask;

    segment(int _product = 1, uint64_t _prime_mask = 0) : product(_product), prime_mask(_prime_mask) {
        if (prime_mask == 0)
            prime_mask = number_to_mask(product);
    }

    void apply(int length, const segment_change &change) {
        if (change.has_change()) {
            product = mod_mul(product, mod_pow(change.x, length));
            prime_mask |= change.prime_mask;
        }
    }

    void join(const segment &other) {
        product = mod_mul(product, other.product);
        prime_mask |= other.prime_mask;
    }

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
        if (!changes[position].has_change())
            return;

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

int N, Q;
vector<int> A;

int main() {
    IO::init();
    sieve(A_MAX);
    vector<int> prime_fractions(P);

    for (int i = 0; i < P; i++)
        prime_fractions[i] = mod_mul(primes[i] - 1, mod_inv(primes[i]));

    IO::read_int(N, Q);
    A.resize(N);
    vector<segment> initial(N);

    for (int i = 0; i < N; i++) {
        IO::read_int(A[i]);
        initial[i] = segment(A[i]);
    }

    seg_tree tree(N);
    tree.build(initial);

    for (int q = 0; q < Q; q++) {
        string operation;
        int L, R, X;
        IO::read_str(operation);
        IO::read_int(L, R);
        L--;

        if (operation == "MULTIPLY") {
            IO::read_int(X);
            tree.update(L, R, segment_change(X));
        } else if (operation == "TOTIENT") {
            segment seg = tree.query(L, R);
            int product = seg.product;

            for (int i = 0; i < P; i++)
                if (seg.prime_mask >> i & 1)
                    product = mod_mul(product, prime_fractions[i]);

            IO::write_int(product, '\n');
        } else {
            assert(false);
        }
    }
}
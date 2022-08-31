#include <algorithm>
#include <cassert>
#include <iostream>
#include <limits>
#include <vector>
using namespace std;

namespace IO {
    const int BUFFER_SIZE = 1 << 15;

    char input_buffer[BUFFER_SIZE];
    int input_pos = 0, input_len = 0;

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
}

const int MOD = 998244353;

struct mod_int {
    int val;

    mod_int(long long v = 0) {
        if (v < 0) v = v % MOD + MOD;
        if (v >= MOD) v %= MOD;
        val = v;
    }

    static int mod_inv(int a, int m = MOD) {
        // https://en.wikipedia.org/wiki/Extended_Euclidean_algorithm#Example
        int g = m, r = a, x = 0, y = 1;

        while (r != 0) {
            int q = g / r;
            g %= r; swap(g, r);
            x -= q * y; swap(x, y);
        }

        return x < 0 ? x + m : x;
    }

    explicit operator int() const {
        return val;
    }

    mod_int& operator+=(const mod_int &other) {
        val += other.val;
        if (val >= MOD) val -= MOD;
        return *this;
    }

    mod_int& operator-=(const mod_int &other) {
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

    mod_int& operator*=(const mod_int &other) {
        val = fast_mod((uint64_t) val * other.val);
        return *this;
    }

    mod_int& operator/=(const mod_int &other) {
        return *this *= other.inv();
    }

    friend mod_int operator+(const mod_int &a, const mod_int &b) { return mod_int(a) += b; }
    friend mod_int operator-(const mod_int &a, const mod_int &b) { return mod_int(a) -= b; }
    friend mod_int operator*(const mod_int &a, const mod_int &b) { return mod_int(a) *= b; }
    friend mod_int operator/(const mod_int &a, const mod_int &b) { return mod_int(a) /= b; }

    mod_int& operator++() {
        val = val == MOD - 1 ? 0 : val + 1;
        return *this;
    }

    mod_int& operator--() {
        val = val == 0 ? MOD - 1 : val - 1;
        return *this;
    }

    mod_int operator++(int) { mod_int before = *this; ++*this; return before; }
    mod_int operator--(int) { mod_int before = *this; --*this; return before; }

    mod_int operator-() const {
        return val == 0 ? 0 : MOD - val;
    }

    bool operator==(const mod_int &other) const { return val == other.val; }
    bool operator!=(const mod_int &other) const { return val != other.val; }

    mod_int inv() const {
        return mod_inv(val);
    }

    mod_int pow(long long p) const {
        assert(p >= 0);
        mod_int a = *this, result = 1;

        while (p > 0) {
            if (p & 1)
                result *= a;

            a *= a;
            p >>= 1;
        }

        return result;
    }

    friend ostream& operator<<(ostream &stream, const mod_int &m) {
        return stream << m.val;
    }
};

struct mod_matrix_fixed_size {
    static const int SIZE = 2;

    mod_int values[SIZE][SIZE];

    mod_matrix_fixed_size() {
        for (int i = 0; i < SIZE; i++)
            for (int j = 0; j < SIZE; j++)
                values[i][j] = 0;
    }

    mod_matrix_fixed_size(const vector<vector<mod_int>> &v) {
        for (int i = 0; i < SIZE; i++)
            for (int j = 0; j < SIZE; j++)
                values[i][j] = v[i][j];
    }

    mod_int *operator[](int index) { return values[index]; }
    const mod_int *operator[](int index) const { return values[index]; }

    void make_identity() {
        for (int i = 0; i < SIZE; i++)
            for (int j = 0; j < SIZE; j++)
                values[i][j] = i == j ? 1 : 0;
    }

    mod_matrix_fixed_size operator*(const mod_matrix_fixed_size &other) const {
        mod_matrix_fixed_size product;
        static uint64_t row[SIZE];

        for (int i = 0; i < SIZE; i++) {
            for (int k = 0; k < SIZE; k++)
                row[k] = 0;

            for (int j = 0; j < SIZE; j++)
                if (values[i][j] != 0)
                    for (int k = 0; k < SIZE; k++)
                        row[k] += (uint64_t) (int) values[i][j] * (int) other[j][k];

            for (int k = 0; k < SIZE; k++)
                product[i][k] = mod_int::fast_mod(row[k]);
        }

        return product;
    }

    mod_matrix_fixed_size& operator*=(const mod_matrix_fixed_size &other) {
        return *this = *this * other;
    }

    mod_matrix_fixed_size power(long long p) const {
        assert(p >= 0);

        mod_matrix_fixed_size m = *this;
        mod_matrix_fixed_size result;
        result.make_identity();

        while (p > 0) {
            if (p & 1)
                result *= m;

            p >>= 1;

            if (p > 0)
                m *= m;
        }

        return result;
    }

    void print() const {
        for (int i = 0; i < SIZE; i++)
            for (int j = 0; j < SIZE; j++)
                cout << values[i][j] << (j < SIZE - 1 ? ' ' : '\n');
    }
};

struct segment {
    mod_matrix_fixed_size m;

    segment(mod_int m00 = 1, mod_int m01 = 0, mod_int m10 = 0, mod_int m11 = 1) {
        m = mod_matrix_fixed_size({{m00, m01}, {m10, m11}});
    }

    void join(const segment &other) {
        m *= other.m;
    }

    void join(const segment &a, const segment &b) {
        m = a.m * b.m;
    }
};

int right_half[32];

struct basic_seg_tree {
    static const bool POWER_OF_TWO_MODE = true;

    int tree_n = 0;
    vector<segment> tree;

    basic_seg_tree(int n = -1) {
        if (n >= 0)
            init(n);
    }

    void init(int n) {
        if (POWER_OF_TWO_MODE) {
            tree_n = 1;

            while (tree_n < n)
                tree_n *= 2;
        } else {
            tree_n = n;
        }

        tree.assign(2 * tree_n, segment());
    }

    // Builds our tree from an array in O(n).
    void build(const vector<segment> &initial) {
        int n = initial.size();
        init(n);
        assert(n <= tree_n);

        for (int i = 0; i < n; i++)
            tree[tree_n + i] = initial[i];

        for (int position = tree_n - 1; position > 0; position--)
            tree[position].join(tree[2 * position], tree[2 * position + 1]);
    }

    segment query(int a, int b) {
        assert(0 <= a && a <= b && b <= tree_n);
        segment answer;
        int r_size = 0;

        for (a += tree_n, b += tree_n; a < b; a /= 2, b /= 2) {
            if (a & 1)
                answer.join(tree[a++]);

            if (b & 1)
                right_half[r_size++] = --b;
        }

        for (int i = r_size - 1; i >= 0; i--)
            answer.join(tree[right_half[i]]);

        return answer;
    }

    segment query_single(int index) {
        assert(0 <= index && index < tree_n);
        return tree[tree_n + index];
    }

    void join_up(int position) {
        while (position > 1) {
            position /= 2;
            tree[position].join(tree[2 * position], tree[2 * position + 1]);
        }
    }

    void update(int index, const segment &seg) {
        assert(0 <= index && index < tree_n);
        int position = tree_n + index;
        tree[position] = seg;
        join_up(position);
    }
};


struct event {
    long long distance = 0, velocity = 1;
    int index, row, col;

    event() {}

    event(long long _distance, long long _velocity, int _index, int _row, int _col)
        : distance(_distance), velocity(_velocity), index(_index), row(_row), col(_col) {
        assert(distance >= 0 && velocity > 0);
    }

    mod_int get_time() const {
        return mod_int(distance) / velocity;
    }

    bool operator<(const event &other) const {
        return distance * other.velocity < other.distance * velocity;
    }
};

int main() {
    int N;
    IO::read_int(N);
    vector<int> X(N), V(N);
    vector<mod_int> L(N), R(N);
    const mod_int INV100 = mod_int(100).inv();

    for (int i = 0; i < N; i++) {
        int P;
        IO::read_int(X[i], V[i], P);
        R[i] = P * INV100;
        L[i] = 1 - R[i];
    }

    basic_seg_tree tree(N);
    vector<segment> transitions(N);

    for (int i = 0; i < N; i++)
        transitions[i].m = mod_matrix_fixed_size({{L[i], R[i]}, {L[i], R[i]}});

    tree.build(transitions);

    auto &&get_probability = [&]() {
        return tree.tree[1].m[0][0] + tree.tree[1].m[0][1];
    };

    vector<event> events;

    for (int i = 1; i < N; i++) {
        long long distance = X[i] - X[i - 1];
        events.emplace_back(distance, V[i] + V[i - 1], i, 1, 0);

        if (V[i] > V[i - 1])
            events.emplace_back(distance, V[i] - V[i - 1], i, 0, 0);
        else if (V[i - 1] > V[i])
            events.emplace_back(distance, V[i - 1] - V[i], i, 1, 1);
    }

    sort(events.begin(), events.end());
    mod_int total = 0, previous_probability = 1;

    for (event &ev : events) {
        transitions[ev.index].m[ev.row][ev.col] = 0;
        tree.update(ev.index, transitions[ev.index]);

        mod_int time = ev.get_time();
        mod_int current_probability = get_probability();
        total += (previous_probability - current_probability) * time;
        previous_probability = current_probability;
    }

    cout << total << '\n';
}
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

template<typename T>
struct fenwick_tree {
    int tree_n = 0;
    T tree_sum = 0;
    vector<T> tree;

    fenwick_tree(int n = -1) {
        if (n >= 0)
            init(n);
    }

    void init(int n) {
        tree_n = n;
        tree_sum = 0;
        tree.assign(tree_n + 1, 0);
    }

    // O(n) initialization of the Fenwick tree.
    template<typename T_array>
    void build(const T_array &initial) {
        assert((int) initial.size() == tree_n);
        tree_sum = 0;

        for (int i = 1; i <= tree_n; i++) {
            tree[i] = initial[i - 1];
            tree_sum += initial[i - 1];

            for (int k = (i & -i) >> 1; k > 0; k >>= 1)
                tree[i] += tree[i - k];
        }
    }

    // index is in [0, tree_n).
    void update(int index, const T &change) {
        assert(0 <= index && index < tree_n);
        tree_sum += change;

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

    // Returns the sum of the range [start, tree_n).
    T query_suffix(int start) const {
        return tree_sum - query(start);
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

    // Returns the largest i in [0, tree_n] such that query(i) <= sum. Returns -1 if no such i exists (sum < 0).
    // Can be used as an ordered set on indices in [0, tree_n) by using the tree as a 0/1 array:
    // update(index, +1) is equivalent to insert(index); be careful not to double insert.
    // update(index, -1) is equivalent to erase(index); again, be careful not to double erase.
    // get(index) provides whether index is present or not.
    // query(index) provides the count of elements < index.
    // find_last_prefix(k) finds the k-th smallest element (0-indexed).
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


int main() {
    IO::init();

    int N, M;
    IO::read_int(N, M);
    vector<int> earliest(N), latest(N);

    for (int i = 0; i < N; i++)
        earliest[i] = latest[i] = i;

    vector<int> last_seen(N);

    for (int i = 0; i < N; i++)
        last_seen[i] = N - 1 - i;

    fenwick_tree<int> tree(N + M);
    vector<int8_t> initial(N + M, 0);

    for (int i = 0; i < N; i++)
        initial[i] = 1;

    tree.build(initial);

    for (int i = 0; i < M; i++) {
        int a;
        IO::read_int(a);
        a--;
        earliest[a] = 0;
        latest[a] = max(latest[a], tree.query_suffix(last_seen[a] + 1));
        tree.update(last_seen[a], -1);
        last_seen[a] = N + i;
        tree.update(last_seen[a], +1);
    }

    for (int i = 0; i < N; i++) {
        latest[i] = max(latest[i], tree.query_suffix(last_seen[i] + 1));
        IO::write_int(earliest[i] + 1, ' ');
        IO::write_int(latest[i] + 1, '\n');
    }
}
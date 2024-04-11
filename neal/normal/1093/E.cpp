#include <algorithm>
#include <cassert>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;


namespace IO {
    const int BUFFER_SIZE = 1 << 15;

    char input_buffer[BUFFER_SIZE];
    int input_pos = 0, input_len = 0;

    char output_buffer[BUFFER_SIZE];
    int output_pos = 0;

    uint8_t lookup[100];

    void _update_input_buffer() {
        input_len = fread(input_buffer, sizeof(char), BUFFER_SIZE, stdin);
        input_pos = 0;
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

        static char number_buffer[100];
        int length = 0;

        do {
            if (number < 10) {
                number_buffer[length++] = number + '0';
                number = 0;
            } else {
                uint8_t lookup_value = lookup[number % 100];
                number /= 100;
                number_buffer[length++] = (lookup_value & 15) + '0';
                number_buffer[length++] = (lookup_value >> 4) + '0';
            }
        } while (number != 0);

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
    vector<T> tree;

    fenwick_tree(int n = 0) {
        if (n > 0)
            init(n);
    }

    void init(int n) {
        tree_n = n;
        tree.assign(tree_n + 1, 0);
    }

    void reset() {
        memset(&tree[0], 0, tree.size() * sizeof(T));
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
        for (int i = index + 1; i <= tree_n; i += i & -i)
            tree[i] += change;
    }

    // Returns the sum of the range [0, count).
    T query(int count) const {
        T sum = 0;

        for (int i = count; i > 0; i -= i & -i)
            sum += tree[i];

        return sum;
    }

    // Returns the sum of the range [a, b).
    T query(int a, int b) const {
        return query(b) - query(a);
    }

    // Returns the last i in [0, N] such that tree_query(i) <= sum, or -1 if no such i exists.
    int find_last_prefix(T sum) const {
        if (sum < 0)
            return -1;

        int log = 32 - __builtin_clz(tree_n);
        int prefix = 0;

        for (int k = log - 1; k >= 0; k--)
            if (prefix + (1 << k) <= tree_n && tree[prefix + (1 << k)] <= sum) {
                prefix += 1 << k;
                sum -= tree[prefix];
            }

        return prefix;
    }
};


// div_conquer_2D provides the following operations in a 2D grid:
// 1) add k at the point (x, y).
// 2) query the sum of k's where x is in the range [start, end) and y < y_query.
// The queries must be done offline. The x-values must be limited in range, but the y-values can be very large.
// To support large x-values, coordinate compression can be added along with binary search for queries.
// Note that operation 2 can be used to get the sum of k's in any rectangle.
// The algorithm takes (log n)^2 time per operation with good cache efficiency.
template<typename T>
struct div_conquer_2D {
    struct event {
        int start, end;
        T y, value;
        int index;

        bool is_update() const {
            return index < 0;
        }

        bool is_query() const {
            return !is_update();
        }

        event(int _start = 0, int _end = 0, T _y = 0, T _value = 0, int _index = 0)
            : start(_start), end(_end), y(_y), value(_value), index(_index) {}

        bool operator<(const event &other) const {
            return y < other.y;
        }
    };

    vector<event> events, buffer;
    vector<T> answers;
    fenwick_tree<T> tree;
    int max_x = -1, max_index = -1;

    void add_update(int x, T y, T k) {
        events.emplace_back(x, -1, y, k, -1);
        max_x = max(max_x, x);
    }

    void add_query(int start, int end, T y, T value, int index) {
        events.emplace_back(start, end, y, value, index);
        max_x = max(max_x, end - 1);
        max_index = max(max_index, index);
    }

    void solve(int start, int end) {
        if (end - start <= 100) {
            // Brute force the quadratic for small ranges.
            for (int i = start; i < end; i++)
                if (events[i].is_query())
                    for (int j = start; j < i; j++)
                        if (events[j].is_update() && events[j].y < events[i].y && events[i].start <= events[j].start && events[j].start < events[i].end)
                            answers[events[i].index] += events[i].value * events[j].value;

            sort(events.begin() + start, events.begin() + end);
            return;
        }

        int mid = (start + end) / 2;
        solve(start, mid);
        solve(mid, end);
        int left = start, right = mid, n = 0;

        // This applies the updates in the left half to the queries in the right half, as well as merge sorting.
        while (left < mid || right < end)
            if (right == end || (left < mid && events[left].y < events[right].y)) {
                if (events[left].is_update())
                    tree.update(events[left].start, events[left].value);

                buffer[n++] = events[left++];
            } else {
                if (events[right].is_query()) {
                    T range_sum = tree.query(events[right].end) - tree.query(events[right].start);
                    answers[events[right].index] += events[right].value * range_sum;
                }

                buffer[n++] = events[right++];
            }

        // Undo all the tree updates.
        if (mid - start > tree.tree_n / 64) {
            tree.reset();
        } else {
            for (int i = start; i < mid; i++)
                if (events[i].is_update())
                    tree.update(events[i].start, -events[i].value);
        }

        copy(buffer.begin(), buffer.begin() + n, events.begin() + start);
    }

    vector<T> solve() {
        answers.assign(max_index + 1, 0);
        tree.init(max_x + 1);
        buffer.resize(events.size());
        solve(0, events.size());
        return answers;
    }
};


int main() {
    IO::init();
    int N, M;
    IO::read_int(N, M);
    vector<int> location(N + 1), B(N);
    div_conquer_2D<int> solver;

    for (int i = 0; i < N; i++) {
        int a;
        IO::read_int(a);
        location[a] = i;
    }

    for (int &b : B) {
        IO::read_int(b);
        b = location[b];
    }

    for (int i = 0; i < N; i++)
        solver.add_update(i, B[i], +1);

    int queries = 0;

    for (int i = 0; i < M; i++) {
        int type;
        IO::read_int(type);

        if (type == 1) {
            int LA, RA, LB, RB;
            IO::read_int(LA, RA, LB, RB);
            LA--; LB--;
            solver.add_query(LB, RB, RA, +1, queries);
            solver.add_query(LB, RB, LA, -1, queries++);
        } else if (type == 2) {
            int x, y;
            IO::read_int(x, y);
            x--; y--;
            solver.add_update(x, B[x], -1);
            solver.add_update(y, B[y], -1);
            swap(B[x], B[y]);
            solver.add_update(x, B[x], +1);
            solver.add_update(y, B[y], +1);
        } else {
            assert(false);
        }
    }

    vector<int> answers = solver.solve();
    assert((int) answers.size() == queries);

    for (int i = 0; i < queries; i++)
        IO::write_int(answers[i], '\n');
}
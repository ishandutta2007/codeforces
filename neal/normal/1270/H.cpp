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

const int INF = 1e9 + 5;

struct segment_change {
    int to_add;
    bool toggle_active;

    segment_change(int _to_add = 0, bool _toggle_active = false) : to_add(_to_add), toggle_active(_toggle_active) {}

    void reset() {
        to_add = 0;
        toggle_active = false;
    }

    bool has_change() const {
        return to_add != 0 || toggle_active;
    }

    // Return the combined result of applying this segment change followed by `other`.
    segment_change combine(const segment_change &other) const {
        return segment_change(to_add + other.to_add, toggle_active ^ other.toggle_active);
    }
};

struct segment {
    int minimum, count_of_min;
    bool active;

    segment(int _minimum = INF, int _count_of_min = 0, bool _active = false)
        : minimum(_minimum), count_of_min(_count_of_min), active(_active) {}

    void apply(int, const segment_change &change) {
        minimum += change.to_add;
        active ^= change.toggle_active;
    }

    void join(const segment &other) {
        if (other.active) {
            if (!active || other.minimum < minimum)
                *this = other;
            else if (other.minimum == minimum)
                count_of_min += other.count_of_min;
        }
    }

    void join(const segment &a, const segment &b) {
        *this = a;
        join(b);
    }

    int get_goal_count(int goal) const {
        return (active && minimum == goal) ? count_of_min : 0;
    }
};

pair<int, int> right_half[32];

struct min_count_seg_tree {
    int tree_n = 0;
    vector<segment> tree;
    vector<segment_change> changes;

    min_count_seg_tree(int n = -1) {
        if (n >= 0)
            init(n);
    }

    void init(int n) {
        tree_n = 1;

        while (tree_n < n)
            tree_n *= 2;

        tree.assign(2 * tree_n, segment());
        changes.assign(tree_n, segment_change());
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

    // Calls push_down for all necessary nodes in order to query the range [a, b).
    void push_all(int a, int b) {
        assert(0 <= a && a < b && b <= tree_n);
        a += tree_n;
        b += tree_n - 1;

        for (int up = 31 - __builtin_clz(tree_n); up > 0; up--) {
            int x = a >> up, y = b >> up;
            push_down(x, 1 << up);
            if (x != y) push_down(y, 1 << up);
        }
    }

    void join_and_apply(int position, int length) {
        tree[position].join(tree[2 * position], tree[2 * position + 1]);
        tree[position].apply(length, changes[position]);
    }

    // Calls join for all necessary nodes after updating the range [a, b).
    void join_all(int a, int b) {
        assert(0 <= a && a < b && b <= tree_n);
        a += tree_n;
        b += tree_n - 1;
        int length = 1;

        while (a > 1) {
            a /= 2;
            b /= 2;
            length *= 2;
            join_and_apply(a, length);
            if (a != b) join_and_apply(b, length);
        }
    }

    template<typename T_range_op>
    void process_range(int a, int b, bool needs_join, T_range_op &&range_op) {
        if (a == b) return;
        push_all(a, b);
        int original_a = a, original_b = b;
        int length = 1, r_size = 0;

        for (a += tree_n, b += tree_n; a < b; a /= 2, b /= 2, length *= 2) {
            if (a & 1)
                range_op(a++, length);

            if (b & 1)
                right_half[r_size++] = {--b, length};
        }

        for (int i = r_size - 1; i >= 0; i--)
            range_op(right_half[i].first, right_half[i].second);

        if (needs_join)
            join_all(original_a, original_b);
    }

    segment query(int a, int b) {
        assert(0 <= a && a <= b && b <= tree_n);
        segment answer;

        process_range(a, b, false, [&](int position, int) {
            answer.join(tree[position]);
        });

        return answer;
    }

    void update(int a, int b, const segment_change &change) {
        assert(0 <= a && a <= b && b <= tree_n);

        process_range(a, b, true, [&](int position, int length) {
            tree[position].apply(length, change);

            if (position < tree_n)
                changes[position] = changes[position].combine(change);
        });
    }
};


const int MAX = 1e6 + 5;

int main() {
    IO::init();

    int N, Q;
    IO::read_int(N, Q);
    vector<int> A(N);

    for (int &a : A)
        IO::read_int(a);

    min_count_seg_tree tree(MAX);
    vector<segment> initial(MAX, segment(0, 1, false));

    for (int i = 0; i < N; i++)
        initial[A[i]].active = true;

    vector<int> delta(MAX, 0);

    for (int i = 0; i < N - 1; i++)
        if (A[i] < A[i + 1]) {
            delta[A[i]]++;
            delta[A[i + 1]]--;
        }

    int sum = 0;

    for (int i = 0; i < MAX; i++) {
        sum += delta[i];
        initial[i].minimum = sum;
    }

    tree.build(initial);

    for (int q = 0; q < Q; q++) {
        int position, x;
        IO::read_int(position, x);
        position--;

        tree.update(A[position], A[position] + 1, segment_change(0, true));

        if (0 < position && position < N - 1 && A[position - 1] < A[position] && A[position] < A[position + 1]) {
            tree.update(A[position - 1], A[position + 1], segment_change(-1));
        } else {
            if (position > 0 && A[position - 1] < A[position]) tree.update(A[position - 1], A[position], segment_change(-1));
            if (position < N - 1 && A[position] < A[position + 1]) tree.update(A[position], A[position + 1], segment_change(-1));
        }

        A[position] = x;

        tree.update(A[position], A[position] + 1, segment_change(0, true));

        if (0 < position && position < N - 1 && A[position - 1] < A[position] && A[position] < A[position + 1]) {
            tree.update(A[position - 1], A[position + 1], segment_change(+1));
        } else {
            if (position > 0 && A[position - 1] < A[position]) tree.update(A[position - 1], A[position], segment_change(+1));
            if (position < N - 1 && A[position] < A[position + 1]) tree.update(A[position], A[position + 1], segment_change(+1));
        }

        IO::write_int(tree.tree[1].get_goal_count(0), '\n');
    }
}
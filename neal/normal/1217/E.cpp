#include <algorithm>
#include <cassert>
#include <limits>
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

const int DIGITS = 9;
const unsigned U_INF = 2e9 + 5;

struct segment {
    unsigned minimum[DIGITS][2];

    segment(unsigned value = U_INF) {
        unsigned current = value;

        for (int d = 0; d < DIGITS; d++) {
            minimum[d][0] = current % 10 == 0 ? U_INF : value;
            minimum[d][1] = U_INF;
            current /= 10;
        }
    }

    int get_min_sum() const {
        unsigned best = U_INF;

        for (int d = 0; d < DIGITS; d++)
            best = min(best, minimum[d][0] + minimum[d][1]);

        return best < U_INF ? best : -1;
    }

    void join(const segment &other) {
        for (int d = 0; d < DIGITS; d++)
            if (minimum[d][0] < other.minimum[d][0]) {
                minimum[d][1] = min(minimum[d][1], other.minimum[d][0]);
            } else {
                minimum[d][1] = min(minimum[d][0], other.minimum[d][1]);
                minimum[d][0] = other.minimum[d][0];
            }
    }

    void join(const segment &a, const segment &b) {
        for (int d = 0; d < DIGITS; d++)
            if (a.minimum[d][0] < b.minimum[d][0]) {
                minimum[d][0] = a.minimum[d][0];
                minimum[d][1] = min(a.minimum[d][1], b.minimum[d][0]);
            } else {
                minimum[d][0] = b.minimum[d][0];
                minimum[d][1] = min(a.minimum[d][0], b.minimum[d][1]);
            }
    }
};

int right_half[32];

struct basic_seg_tree {
    static const bool POWER_OF_TWO_MODE = false;

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


int main() {
    IO::init();
    int N, Q;
    IO::read_int(N, Q);
    basic_seg_tree tree;
    vector<segment> initial(N);

    for (int i = 0; i < N; i++) {
        int a;
        IO::read_int(a);
        initial[i] = segment(a);
    }

    tree.build(initial);

    for (int q = 0; q < Q; q++) {
        int type, I, X, L, R;
        IO::read_int(type);

        if (type == 1) {
            IO::read_int(I, X);
            I--;
            tree.update(I, segment(X));
        } else {
            IO::read_int(L, R);
            L--;
            IO::write_int(tree.query(L, R).get_min_sum(), '\n');
        }
    }
}
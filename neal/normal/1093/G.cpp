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


const int INF = 1e9 + 5;
const int K_MAX = 5, MASK_MAX = 32;

int K, FULL_MASK;
int to_set[K_MAX];

struct segment {
    int maximum[MASK_MAX];

    segment() {
        for (int i = 0; i < MASK_MAX; i++)
            maximum[i] = -INF;
    }

    bool empty() const {
        return maximum[0] <= -INF;
    }

    void apply() {
        for (int mask = 0; mask < MASK_MAX; mask++) {
            maximum[mask] = 0;

            for (int i = 0; i < K; i++)
                maximum[mask] += mask >> i & 1 ? to_set[i] : -to_set[i];
        }
    }

    int get_answer() const {
        int most = 0;

        for (int i = 0; i < MASK_MAX / 2; i++)
            most = max(most, maximum[i] + maximum[i ^ FULL_MASK]);

        return most;
    }

    void join(const segment &other) {
        for (int i = 0; i < MASK_MAX; i++)
            maximum[i] = max(maximum[i], other.maximum[i]);
            // maximize(maximum[i], other.maximum[i]);
    }

    // TODO: decide whether to re-implement this for better performance. Mainly relevant when segments contain arrays.
    void join(const segment &a, const segment &b) {
        for (int i = 0; i < MASK_MAX; i++)
            maximum[i] = max(a.maximum[i], b.maximum[i]);
    }
};

struct basic_seg_tree {
    // Note: POWER_OF_TWO_MODE is only necessary in order to binary search the tree.
    static const bool POWER_OF_TWO_MODE = false;

    int tree_n = 0;
    vector<segment> tree;

    basic_seg_tree(int n = 0) {
        if (n > 0)
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

    // O(n) initialization of our tree.
    void build(const vector<segment> &initial) {
        int n = initial.size();
        assert(n <= tree_n);

        for (int i = 0; i < n; i++)
            tree[tree_n + i] = initial[i];

        for (int position = tree_n - 1; position > 0; position--)
            tree[position].join(tree[2 * position], tree[2 * position + 1]);
    }

    static int right_half[];

    segment query(int a, int b) {
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

    void join_up(int position) {
        while (position > 1) {
            position /= 2;
            tree[position].join(tree[2 * position], tree[2 * position + 1]);
        }
    }

    void update(int position) {
        position += tree_n;
        tree[position].apply();
        join_up(position);
    }

    template<typename T_bool>
    int find_last_prefix(int n, T_bool &&should_join) {
        assert(POWER_OF_TWO_MODE);
        segment current;

        // Check edge cases.
        if (!should_join(current, current))
            return -1;

        if (should_join(current, tree[1]))
            return n;

        int position = 1;
        int start = 0, end = tree_n;

        while (position < tree_n) {
            int mid = (start + end) / 2;

            if (should_join(current, tree[2 * position])) {
                current.join(tree[2 * position]);
                position = 2 * position + 1;
                start = mid;
            } else {
                position = 2 * position;
                end = mid;
            }
        }

        assert(position == tree_n + start);
        assert(0 <= start && start < n);
        assert(end - start == 1);
        return start;
    }
};

int basic_seg_tree::right_half[100];


int main() {
    IO::init();
    int N, Q;
    IO::read_int(N, K);
    FULL_MASK = (1 << K) - 1;
    vector<segment> initial(N);

    for (int i = 0; i < N; i++) {
        for (int k = 0; k < K; k++)
            IO::read_int(to_set[k]);

        initial[i].apply();
    }

    basic_seg_tree tree(N);
    tree.build(initial);
    IO::read_int(Q);

    for (int q = 0; q < Q; q++) {
        int type;
        IO::read_int(type);

        if (type == 1) {
            int index;
            IO::read_int(index);
            index--;

            for (int k = 0; k < K; k++)
                IO::read_int(to_set[k]);

            tree.update(index);
        } else if (type == 2) {
            int L, R;
            IO::read_int(L, R);
            L--;

            IO::write_int(tree.query(L, R).get_answer(), '\n');
        } else {
            assert(false);
        }
    }
}
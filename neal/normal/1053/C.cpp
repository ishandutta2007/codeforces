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

    inline bool isspace(char c) {
        return (unsigned char) (c - '\t') < 5 || c == ' ';
    }

    template<typename T>
    inline void read_int(T &number) {
        while (isspace(next_char(false)))
            next_char();

        bool negative = next_char(false) == '-';

        if (negative)
            next_char();

        number = 0;

        while (isdigit(next_char(false)))
            number = 10 * number + (next_char() - '0');

        if (negative)
            number = -number;
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
    inline void write_int(T number, char after = 0) {
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


const int MOD = 1e9 + 7;

struct tree_node {
    long long w_sum, aw_sum;

    tree_node() : w_sum(0), aw_sum(0) {}

    void join(const tree_node &other) {
        w_sum += other.w_sum;
        aw_sum += other.aw_sum;
    }
};

int N, LOG, Q;
vector<int> A, W;
vector<tree_node> tree;

// O(N) initialization of our BIT.
void build_tree() {
    for (int i = 1; i <= N; i++) {
        for (int k = (i & -i) >> 1; k > 0; k >>= 1)
            tree[i].join(tree[i - k]);

        tree[i].w_sum += W[i - 1];
        tree[i].aw_sum = (tree[i].aw_sum + (long long) W[i - 1] * A[i - 1]) % MOD;
    }
}

void tree_update(int index, long long w_change, int a) {
    int aw_change = (MOD + w_change) * a % MOD;

    for (int i = index + 1; i <= N; i += i & -i) {
        tree[i].w_sum += w_change;
        tree[i].aw_sum += aw_change;
    }
}

tree_node tree_query(int count) {
    tree_node answer;

    for (int i = count; i > 0; i -= i & -i)
        answer.join(tree[i]);

    return answer;
}

int solve(int start, int end) {
    tree_node end_range = tree_query(end);
    tree_node start_range = tree_query(start);
    long long search = (start_range.w_sum + end_range.w_sum + 1) / 2;
    int goal = 0;
    tree_node goal_range;

    for (int k = LOG - 1; k >= 0; k--)
        if (goal + (1 << k) <= N && goal_range.w_sum + tree[goal + (1 << k)].w_sum < search) {
            goal += 1 << k;
            goal_range.join(tree[goal]);
        }

    // goal is the last point such that the w_sum of [start, goal) < the w_sum of [goal, end)
    assert(start <= goal && goal < end);
    long long left_w_sum = goal_range.w_sum - start_range.w_sum;
    long long right_w_sum = end_range.w_sum - goal_range.w_sum;
    assert(left_w_sum < right_w_sum);
    long long left_aw_sum = goal_range.aw_sum - start_range.aw_sum;
    long long right_aw_sum = end_range.aw_sum - goal_range.aw_sum;

    // result = sum W[i] * |A[i] - A[goal]|
    long long result = ((left_w_sum - right_w_sum) % MOD * A[goal] + right_aw_sum - left_aw_sum) % MOD;
    if (result < 0) result += MOD;
    return result;
}

int main() {
    IO::init();
    IO::read_int(N);
    IO::read_int(Q);
    A.resize(N);
    W.resize(N);
    LOG = 32 - __builtin_clz(N);
    assert(1 << LOG > N);
    tree.resize(N + 1);

    for (int i = 0; i < N; i++) {
        IO::read_int(A[i]);
        A[i] -= i;
    }

    for (int i = 0; i < N; i++)
        IO::read_int(W[i]);

    build_tree();

    for (int q = 0; q < Q; q++) {
        int x, y;
        IO::read_int(x);
        IO::read_int(y);

        if (x < 0) {
            x = -x - 1;
            tree_update(x, y - W[x], A[x]);
            W[x] = y;
        } else {
            IO::write_int(solve(x - 1, y), '\n');
        }
    }
}
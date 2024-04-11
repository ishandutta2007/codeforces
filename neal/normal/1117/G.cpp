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

    fenwick_tree(int n = 0) {
        if (n > 0)
            init(n);
    }

    void init(int n) {
        tree_n = n;
        tree_sum = 0;
        tree.assign(tree_n + 1, 0);
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
};

struct query {
    int L, R, index;

    query(int _L = -1, int _R = -1, int _index = -1) : L(_L), R(_R), index(_index) {}
};

int N, Q;
vector<int> P;
vector<query> queries;
vector<vector<query>> queries_at_point;
vector<long long> answers;

void solve_right_half() {
    vector<int> stack(N);
    vector<int> stack_P(N);
    vector<long long> stack_sum(N + 1, 0);
    int S = 0;
    fenwick_tree<long long> done_tree(N);

    for (int i = 0; i < N; i++) {
        while (S > 0 && P[i] > stack_P[S - 1]) {
            done_tree.update(stack[S - 1], i - stack[S - 1] - 1);
            S--;
        }

        // Add to the end of the stack.
        stack[S] = i;
        stack_P[S] = P[i];
        stack_sum[S + 1] = stack_sum[S] + i;
        S++;

        for (query &q : queries_at_point[i]) {
            answers[q.index] += done_tree.query_suffix(q.L);

            int index = lower_bound(stack.begin(), stack.begin() + S, q.L) - stack.begin();
            answers[q.index] += (long long) i * (S - index) - (stack_sum[S] - stack_sum[index]);
        }
    }
}

int main() {
    IO::init();
    IO::read_int(N, Q);
    P.resize(N);
    queries.resize(Q);

    for (int i = 0; i < N; i++)
        IO::read_int(P[i]);

    for (int q = 0; q < Q; q++)
        queries[q].index = q;

    for (int q = 0; q < Q; q++) {
        IO::read_int(queries[q].L);
        queries[q].L--;
    }

    for (int q = 0; q < Q; q++) {
        IO::read_int(queries[q].R);
        queries[q].R--;
    }

    answers.assign(Q, 0);

    for (query &q : queries)
        answers[q.index] = q.R - q.L + 1;

    queries_at_point.assign(N, {});

    for (query &q : queries)
        queries_at_point[q.R].push_back(q);

    solve_right_half();

    for (query &q : queries) {
        q.L = N - 1 - q.L;
        q.R = N - 1 - q.R;
        swap(q.L, q.R);
    }

    reverse(P.begin(), P.end());
    queries_at_point.assign(N, {});

    for (query &q : queries)
        queries_at_point[q.R].push_back(q);

    solve_right_half();

    for (int q = 0; q < Q; q++)
        IO::write_int(answers[q], q < Q - 1 ? ' ' : '\n');
}
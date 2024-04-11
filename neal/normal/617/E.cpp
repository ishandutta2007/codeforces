// Solution to https://codeforces.com/contest/617/problem/E
#include <algorithm>
#include <cassert>
#include <cmath>
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


typedef int mo_value;
typedef long long mo_answer;

int K;

struct mo_state {
    static const int A_MAX = 1 << 20;

    int freq[A_MAX];
    long long total;

    mo_state() {
        memset(freq, 0, sizeof(freq));
        total = 0;
    }

    void add_left(const mo_value &x) {
        total += freq[x ^ K];
        freq[x]++;
    }

    void add_right(const mo_value &x) {
        add_left(x);
    }

    void remove_left(const mo_value &x) {
        freq[x]--;
        total -= freq[x ^ K];
    }

    void remove_right(const mo_value &x) {
        remove_left(x);
    }

    mo_answer get_answer() const {
        return total;
    }
};

struct mo_query {
    int start, end, block, index;

    mo_query(int _start = 0, int _end = 0) : start(_start), end(_end) {}

    bool operator<(const mo_query &other) const {
        if (block != other.block)
            return block < other.block;

        return block % 2 == 0 ? end < other.end : end > other.end;
    }
};

struct mo {
    int n, block_size;
    vector<mo_value> values;

    mo(vector<mo_value> initial = {}) {
        if (!initial.empty())
            init(initial);
    }

    void init(const vector<mo_value> &initial) {
        values = initial;
        n = values.size();
        block_size = 1.6 * sqrt(n) + 1;
    }

    void update_state(mo_state &state, const mo_query &first, const mo_query &second) const {
        if (max(first.start, second.start) >= min(first.end, second.end)) {
            for (int i = first.start; i < first.end; i++)
                state.remove_left(values[i]);

            for (int i = second.start; i < second.end; i++)
                state.add_right(values[i]);

            return;
        }

        for (int i = first.start - 1; i >= second.start; i--)
            state.add_left(values[i]);

        for (int i = first.end; i < second.end; i++)
            state.add_right(values[i]);

        for (int i = first.start; i < second.start; i++)
            state.remove_left(values[i]);

        for (int i = first.end - 1; i >= second.end; i--)
            state.remove_right(values[i]);
    }

    vector<mo_answer> solve(vector<mo_query> queries) const {
        for (int i = 0; i < (int) queries.size(); i++) {
            queries[i].index = i;
            queries[i].block = queries[i].start / block_size;
        }

        sort(queries.begin(), queries.end());
        mo_state state;
        mo_query last_query;
        vector<mo_answer> answers(queries.size());

        for (mo_query &q : queries) {
            update_state(state, last_query, q);
            answers[q.index] = state.get_answer();
            last_query = q;
        }

        return answers;
    }
};


int main() {
    IO::init();

    int N, Q;
    IO::read_int(N);
    IO::read_int(Q);
    IO::read_int(K);
    vector<int> A(N + 1);
    A[0] = 0;

    for (int i = 1; i <= N; i++)
        IO::read_int(A[i]);

    for (int i = 1; i <= N; i++)
        A[i] ^= A[i - 1];

    mo solver(A);
    vector<mo_query> queries(Q);

    for (mo_query &q : queries) {
        IO::read_int(q.start);
        IO::read_int(q.end);
        q.start--;
        q.end++;
    }

    vector<mo_answer> answers = solver.solve(queries);

    for (mo_answer &answer : answers)
        IO::write_int(answer, '\n');
}
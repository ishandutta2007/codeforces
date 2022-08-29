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

struct union_find {
    // When data[x] < 0, x is a root and -data[x] is its tree size. When data[x] >= 0, data[x] is x's parent.
    vector<int> data;
    int components = 0;

    union_find(int n = -1) {
        if (n >= 0)
            init(n);
    }

    void init(int n) {
        data.assign(n + 1, -1);
        components = n;
    }

    int find(int x) {
        return data[x] < 0 ? x : data[x] = find(data[x]);
    }

    int get_size(int x) {
        return -data[find(x)];
    }

    bool unite(int x, int y) {
        x = find(x);
        y = find(y);

        if (x == y)
            return false;

        if (get_size(x) < get_size(y))
            swap(x, y);

        data[x] += data[y];
        data[y] = x;
        components--;
        return true;
    }
};


struct query {
    int16_t x, y;
    int c, lost;
};

int main() {
    IO::init();

    int N, M, Q;
    IO::read_int(N, M, Q);
    vector<vector<int>> grid(N, vector<int>(M, 0));
    vector<query> queries(Q);

    for (query &qry : queries) {
        IO::read_int(qry.x, qry.y, qry.c);
        qry.x--; qry.y--;
    }

    int C = queries.back().c;
    vector<int> counts(C + 1, 0);
    counts[0] = N * M;

    for (query &qry : queries) {
        qry.lost = grid[qry.x][qry.y];
        grid[qry.x][qry.y] = qry.c;
        counts[qry.c]++;
    }

    grid.assign(N, vector<int>(M, 0));
    vector<int> answers(Q, 1);
    vector<int> components(C + 1);
    components[0] = 1;

    auto &&to_index = [&](int row, int col) {
        return row * M + col;
    };

    vector<int> previous_query(Q, -1);
    vector<int> last_query(C + 1, -1);

    for (int q = Q - 1; q >= 0; q--) {
        query &qry = queries[q];
        previous_query[q] = last_query[qry.c];
        last_query[qry.c] = q;
    }

    vector<int> forward_delta(Q, 0);

    for (int c = 1; c <= C; c++) {
        union_find UF(N * M);
        int add_components = 0, previous = 0;

        for (int q = last_query[c]; q >= 0; q = previous_query[q]) {
            add_components++;
            query &qry = queries[q];
            assert(qry.c == c);

            if (qry.x > 0 && grid[qry.x - 1][qry.y] == c) add_components -= UF.unite(to_index(qry.x - 1, qry.y), to_index(qry.x, qry.y));
            if (qry.y > 0 && grid[qry.x][qry.y - 1] == c) add_components -= UF.unite(to_index(qry.x, qry.y - 1), to_index(qry.x, qry.y));
            if (qry.x < N - 1 && grid[qry.x + 1][qry.y] == c) add_components -= UF.unite(to_index(qry.x + 1, qry.y), to_index(qry.x, qry.y));
            if (qry.y < M - 1 && grid[qry.x][qry.y + 1] == c) add_components -= UF.unite(to_index(qry.x, qry.y + 1), to_index(qry.x, qry.y));

            grid[qry.x][qry.y] = c;
            forward_delta[q] += add_components - previous;
            previous = add_components;
        }

        components[c] = UF.components - (N * M - counts[c]);
    }

    for (int q = 0, delta = 0; q < Q; q++) {
        delta += forward_delta[q];
        answers[q] += delta;
    }

    vector<vector<int>> final_grid = grid;
    vector<int> final_counts(C + 1, 0);

    for (int row = 0; row < N; row++)
        for (int col = 0; col < M; col++)
            final_counts[grid[row][col]]++;

    previous_query.assign(Q, -1);
    last_query.assign(C + 1, -1);

    for (int q = 0; q < Q; q++) {
        query &qry = queries[q];
        previous_query[q] = last_query[qry.lost];
        last_query[qry.lost] = q;
    }

    vector<int> backward_delta(Q + 1, 0);

    for (int c = 0; c <= C; c++) {
        union_find UF(N * M);
        grid = final_grid;

        for (int row = 0; row < N; row++)
            for (int col = 0; col < M; col++)
                if (grid[row][col] == c) {
                    if (row < N - 1 && grid[row + 1][col] == c) UF.unite(to_index(row + 1, col), to_index(row, col));
                    if (col < M - 1 && grid[row][col + 1] == c) UF.unite(to_index(row, col + 1), to_index(row, col));
                }

        int delta = (UF.components - (N * M - final_counts[c])) - components[c];
        backward_delta[Q] += delta;
        int previous = delta;

        for (int q = last_query[c]; q >= 0; q = previous_query[q]) {
            query &qry = queries[q];
            assert(qry.lost == c);
            delta -= UF.components;

            if (qry.x > 0 && grid[qry.x - 1][qry.y] == c) UF.unite(to_index(qry.x - 1, qry.y), to_index(qry.x, qry.y));
            if (qry.y > 0 && grid[qry.x][qry.y - 1] == c) UF.unite(to_index(qry.x, qry.y - 1), to_index(qry.x, qry.y));
            if (qry.x < N - 1 && grid[qry.x + 1][qry.y] == c) UF.unite(to_index(qry.x + 1, qry.y), to_index(qry.x, qry.y));
            if (qry.y < M - 1 && grid[qry.x][qry.y + 1] == c) UF.unite(to_index(qry.x, qry.y + 1), to_index(qry.x, qry.y));

            delta += UF.components;
            delta++;
            grid[qry.x][qry.y] = c;

            backward_delta[q] += delta - previous;
            previous = delta;
        }
    }

    for (int q = Q - 1, delta = 0; q >= 0; q--) {
        delta += backward_delta[q + 1];
        answers[q] += delta;
    }

    for (int q = 0; q < Q; q++)
        IO::write_int(answers[q], '\n');
}
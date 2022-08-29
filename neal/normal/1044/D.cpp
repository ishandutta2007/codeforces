#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;


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


gp_hash_table<int, int> parent, value;
gp_hash_table<int, uint8_t> uf_rank;

int find(int x) {
    if (parent.find(x) == parent.end()) {
        parent[x] = x;
        uf_rank[x] = value[x] = 0;
    }

    if (x == parent[x])
        return x;

    int root = find(parent[x]);
    value[x] ^= value[parent[x]];
    return parent[x] = root;
}

void unite(int x, int y, int val) {
    int x_root = find(x), y_root = find(y);
    val ^= value[x] ^ value[y];

    if (uf_rank[x_root] < uf_rank[y_root])
        swap(x_root, y_root);
    else if (uf_rank[x_root] == uf_rank[y_root])
        uf_rank[x_root]++;

    parent[y_root] = x_root;
    value[y_root] = val;
}

void update(int start, int end, int val) {
    if (find(start) == find(end))
        return;

    unite(start, end, val);
}

int query(int start, int end) {
    if (find(start) != find(end))
        return -1;

    return value[start] ^ value[end];
}

int main() {
    IO::init();

    int Q;
    IO::read_int(Q);
    int last = 0;

    for (int q = 0; q < Q; q++) {
        int t, l, r, x;
        IO::read_int(t);
        IO::read_int(l);
        IO::read_int(r);
        l ^= last;
        r ^= last;

        if (l > r)
            swap(l, r);

        r++;

        if (t == 1) {
            IO::read_int(x);
            x ^= last;
            update(l, r, x);
        } else if (t == 2) {
            int answer = query(l, r);
            IO::write_int(answer, '\n');
            last = abs(answer);
        } else {
            assert(false);
        }
    }
}
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


struct voter {
    int M, P;

    bool operator<(const voter &other) const {
        return M < other.M;
    }
};

void solve_case() {
    int N;
    IO::read_int(N);
    vector<voter> voters(N);
    vector<int> counts(N, 0);

    for (voter &v : voters) {
        IO::read_int(v.M, v.P);
        counts[v.M]++;
    }

    for (int i = 1; i < N; i++)
        counts[i] += counts[i - 1];

    vector<voter> sorted_voters(N);

    for (int i = 0; i < N; i++)
        sorted_voters[--counts[voters[i].M]] = voters[i];

    swap(voters, sorted_voters);
    sorted_voters.clear();
    vector<int> heap(N);
    vector<int>::iterator heap_end = heap.begin();
    int bought = 0;
    long long total = 0;

    for (int i = N - 1; i >= 0; i--) {
        *heap_end++ = voters[i].P;
        push_heap(heap.begin(), heap_end, greater<int>());

        if (voters[i].M - bought > i) {
            total += heap.front();
            pop_heap(heap.begin(), heap_end--, greater<int>());
            bought++;
        }
    }

    IO::write_int(total, '\n');
}

int main() {
    IO::init();

    int T;
    IO::read_int(T);

    while (T-- > 0)
        solve_case();
}
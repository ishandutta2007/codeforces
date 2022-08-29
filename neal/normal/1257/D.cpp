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


void solve_case() {
    int N, M;
    IO::read_int(N);
    vector<int> A(N);
    vector<int> best_power(N + 1, 0);

    for (auto &a : A)
        IO::read_int(a);

    IO::read_int(M);

    for (int i = 0; i < M; i++) {
        int p, s;
        IO::read_int(p, s);
        best_power[s] = max(best_power[s], p);
    }

    for (int s = N - 1; s >= 0; s--)
        best_power[s] = max(best_power[s], best_power[s + 1]);

    if (*max_element(A.begin(), A.end()) > best_power[0]) {
        IO::write_int(-1, '\n');
        return;
    }

    int start = 0, days = 0;

    while (start < N) {
        int monsters = 0, maximum = 0;

        while (start + monsters < N) {
            maximum = max(maximum, A[start + monsters]);

            if (best_power[monsters + 1] >= maximum)
                monsters++;
            else
                break;
        }

        start += monsters;
        days++;
    }

    IO::write_int(days, '\n');
}

int main() {
    IO::init();

    int T;
    IO::read_int(T);

    while (T-- > 0)
        solve_case();
}
#pragma GCC optimize ("O3")
#include <cassert>
#include <cmath>
#include <iostream>
using namespace std;


namespace IO {
    const int BUFFER_SIZE = 1 << 15;

    FILE *input_stream = stdin;
    FILE *output_stream = stdout;

    char input_buffer[BUFFER_SIZE];
    int input_pos = 0, input_len = 0;

    char output_buffer[BUFFER_SIZE];
    int output_pos = 0;

    char number_buffer[100];
    uint8_t lookup[100];

    void redirect(const char *input_file, const char *output_file) {
        input_stream = fopen(input_file, "r");
        output_stream = fopen(output_file, "w");
    }

    void _update_input_buffer() {
        input_len = fread(input_buffer, sizeof(char), BUFFER_SIZE, input_stream);
        input_pos = 0;
    }

    char next_char(bool advance = true) {
        if (input_pos >= input_len)
            _update_input_buffer();

        return input_buffer[advance ? input_pos++ : input_pos];
    }

    bool isspace(char c) {
        return (unsigned char) (c - '\t') < 5 || c == ' ';
    }

    bool on_whitespace() {
        return isspace(next_char(false));
    }

    bool on_digit() {
        return isdigit(next_char(false));
    }

    void skip_whitespace() {
        while (on_whitespace())
            next_char();
    }

    bool input_finished() {
        while (on_whitespace() && input_len > 0)
            next_char();

        return input_len < BUFFER_SIZE && input_pos >= input_len;
    }

    template<typename T>
    void read_int(T &number) {
        skip_whitespace();
        bool negative = next_char(false) == '-';

        if (negative)
            next_char();

        number = 0;

        while (on_digit())
            number = 10 * number + (next_char() - '0');

        if (negative)
            number = -number;
    }

    void read_double(double &number) {
        skip_whitespace();
        bool negative = next_char(false) == '-';

        if (negative)
            next_char();

        number = 0;

        while (on_digit())
            number = 10 * number + (next_char() - '0');

        if (next_char(false) == '.') {
            next_char();

            for (double multiplier = 0.1; on_digit(); multiplier *= 0.1)
                number += multiplier * (next_char() - '0');
        }

        if (negative)
            number = -number;
    }

    void read_char(char &c) {
        skip_whitespace();
        c = next_char();
    }

    void read_str(char *str) {
        skip_whitespace();

        while (!on_whitespace())
            *str++ = next_char();

        *str = '\0';
    }

    void read_line(char *str) {
        while (next_char(false) == '\n')
            next_char();

        while (next_char(false) != '\n')
            *str++ = next_char();

        *str = '\0';
    }

    void flush_output() {
        fwrite(output_buffer, sizeof(char), output_pos, output_stream);
        output_pos = 0;
    }

    void write_char(char c) {
        if (output_pos == BUFFER_SIZE)
            flush_output();

        output_buffer[output_pos++] = c;
    }

    template<typename T>
    void write_int(T number, char after = 0) {
        if (number < 0) {
            write_char('-');
            number = -number;
        }

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

    void write_str(const char *str, char after = 0) {
        while (*str)
            write_char(*str++);

        if (after)
            write_char(after);
    }

    void write_double(double number, char after = 0, int places = 6) {
        if (number < 0) {
            write_char('-');
            number = -number;
        }

        assert(number <= 9e18);

        // Round up the number according to places.
        number += 0.5 * pow(0.1, places);
        long long floored = (long long) number;
        write_int(floored);

        if (places > 0) {
            write_char('.');
            number = (number - floored) * pow(10.0, places);
            floored = (long long) number;
            int length = 0;

            for (int i = 0; i < places / 2; i++) {
                uint8_t lookup_value = lookup[floored % 100];
                floored /= 100;
                number_buffer[length++] = (lookup_value & 15) + '0';
                number_buffer[length++] = (lookup_value >> 4) + '0';
            }

            if (places % 2)
                number_buffer[length++] = floored + '0';

            assert(length == places);

            for (int i = places - 1; i >= 0; i--)
                write_char(number_buffer[i]);
        }

        if (after)
            write_char(after);
    }

    void init() {
        // Make sure flush_output() is called at the end of the program.
        bool exit_success = atexit(flush_output) == 0;
        assert(exit_success);

        for (int i = 0; i < 100; i++)
            lookup[i] = (i / 10 << 4) + i % 10;
    }
}


const int MAX = 1 << 18;

double values[MAX];

int main() {
    IO::init();

    int N, R;
    IO::read_int(N);
    IO::read_int(R);
    double sum = 0;

    for (int i = 0; i < 1 << N; i++) {
        int x;
        IO::read_int(x);
        values[i] = x;
        sum += x;
    }

    double ratio = 1.0 / (1 << N);
    IO::write_double(ratio * sum, '\n');

    for (int i = 0; i < R; i++) {
        int index, value;
        IO::read_int(index);
        IO::read_int(value);
        sum += value - values[index];
        values[index] = value;
        IO::write_double(ratio * sum, '\n');
    }
}
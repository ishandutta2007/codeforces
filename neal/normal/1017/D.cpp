#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
using namespace std;

namespace IO {
    const int BUFFER_SIZE = 32768;
    const int NUMBER_BUFFER = 100;

    FILE *input_stream = stdin;
    FILE *output_stream = stdout;

    int input_pos = BUFFER_SIZE;
    int input_read = BUFFER_SIZE;

    int output_pos = 0;

    char input_buffer[BUFFER_SIZE];
    char output_buffer[BUFFER_SIZE];

    char number_buffer[NUMBER_BUFFER];

    void init(const char *input_file, const char *output_file) {
        input_stream = fopen(input_file, "r");
        output_stream = fopen(output_file, "w");
    }

    void _update_input_buffer() {
        if (input_pos >= input_read && input_read == BUFFER_SIZE) {
            input_read = fread(input_buffer, sizeof(char), BUFFER_SIZE, input_stream);
            input_pos = 0;
        }
    }

    char next_char(bool advance = true) {
        _update_input_buffer();
        return input_buffer[advance ? input_pos++ : input_pos];
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
        skip_whitespace();
        return input_pos >= input_read && input_read < BUFFER_SIZE;
    }

    long long next_int() {
        skip_whitespace();
        bool negative = next_char(false) == '-';

        if (negative)
            next_char();

        long long number = 0;

        while (on_digit())
            number = 10 * number + (next_char() - '0');

        return negative ? -number : number;
    }

    double next_double() {
        skip_whitespace();
        bool negative = next_char(false) == '-';

        if (negative)
            next_char();

        double number = 0;

        while (on_digit())
            number = 10 * number + (next_char() - '0');

        if (next_char(false) == '.') {
            next_char();

            for (double multiplier = 0.1; on_digit(); multiplier *= 0.1)
                number += multiplier * (next_char() - '0');
        }

        return negative ? -number : number;
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

    void write_int(long long number, char after = 0) {
        if (number < 0) {
            write_char('-');
            number = -number;
        }

        int length = 0;

        do {
            number_buffer[length++] = number % 10 + '0';
            number /= 10;
        } while (number > 0);

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

            for (int i = 0; i < places; i++) {
                number_buffer[i] = floored % 10 + '0';
                floored /= 10;
            }

            for (int i = places - 1; i >= 0; i--)
                write_char(number_buffer[i]);
        }

        if (after)
            write_char(after);
    }

    // Make sure flush_output() is called at the end of the program.
    struct Dummy {
        ~Dummy() {
            flush_output();
        }
    } dummy;
}


const int N_MAX = 15;
const int NN_MAX = (1 << 12) + 5;
const int K_MAX = 105;

int N, M, Q;
int values[N_MAX];
int value_sum[NN_MAX];
int freq[NN_MAX];
int counts[NN_MAX][K_MAX];

int str_to_int(char *str) {
    int value = 0;

    for (int i = 0; i < N; i++)
        value += (str[i] - '0') << i;

    return value;
}

int main() {
    N = IO::next_int();
    M = IO::next_int();
    Q = IO::next_int();

    for (int i = 0; i < N; i++)
        values[i] = IO::next_int();

    char str[100];

    for (int m = 0; m < M; m++) {
        IO::read_str(str);
        freq[str_to_int(str)]++;
    }

    for (int s = 0; s < 1 << N; s++) {
        value_sum[s] = 0;

        for (int i = 0; i < N; i++)
            if ((s & 1 << i) == 0)
                value_sum[s] += values[i];

        value_sum[s] = min(value_sum[s], K_MAX - 1);
    }

    for (int s = 0; s < 1 << N; s++) {
        for (int v = 0; v < 1 << N; v++)
            counts[s][value_sum[s ^ v]] += freq[v];

        for (int k = 0; k + 1 < K_MAX; k++)
            counts[s][k + 1] += counts[s][k];
    }

    for (int q = 0; q < Q; q++) {
        IO::read_str(str);
        int k = IO::next_int();
        IO::write_int(counts[str_to_int(str)][k], '\n');
    }

    return 0;
}
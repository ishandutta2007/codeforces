#include <algorithm>
#include <cassert>
#include <cmath>
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

    inline void read_double(double &number) {
        bool negative = false;
        number = 0;

        while (!isdigit(next_char(false)))
            if (next_char() == '-')
                negative = true;

        do {
            number = 10 * number + (next_char() - '0');
        } while (isdigit(next_char(false)));

        if (next_char(false) == '.') {
            next_char();

            for (double multiplier = 0.1; isdigit(next_char(false)); multiplier *= 0.1)
                number += multiplier * (next_char() - '0');
        }

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

    inline void write_double(double number, char after = '\0', int places = 6) {
        if (number < 0) {
            write_char('-');
            number = -number;
        }

        assert(number <= 9e18);

        // Round up the number according to places.
        number += 0.5 * pow(0.1, places);
        long long floored = (long long) number;

        if (floored <= numeric_limits<int>::max())
            write_int((int) floored);
        else
            write_int(floored);

        number -= floored;

        if (places > 0) {
            write_char('.');

            while (places >= 2) {
                number *= 100;
                int two = (int) number;
                number -= two;
                uint8_t lookup_value = lookup[two];
                write_char((lookup_value >> 4) + '0');
                write_char((lookup_value & 15) + '0');
                places -= 2;
            }

            if (places == 1) {
                number *= 10;
                int one = (int) number;
                write_char(one + '0');
            }
        }

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


int main() {
    IO::init();

    int N;
    IO::read_int(N);
    vector<pair<long long, int>> stack;

    for (int i = 0; i < N; i++) {
        int a;
        IO::read_int(a);
        pair<long long, int> current = {a, 1};

        while (!stack.empty() && current.first * stack.back().second <= stack.back().first * current.second) {
            current.first += stack.back().first;
            current.second += stack.back().second;
            stack.pop_back();
        }

        stack.push_back(current);
    }

    for (pair<long long, int> &current : stack) {
        double value = (double) current.first / current.second;
        int before = 0;

        for (double x = value; x >= 1; x /= 10)
            before++;

        for (int i = 0; i < current.second; i++)
            IO::write_double(value, '\n', 10 - before);
    }
}
#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;


namespace IO {
    const int BUFFER_SIZE = 4096;

    char input_buffer[BUFFER_SIZE];
    int input_pos = BUFFER_SIZE;
    int input_read = BUFFER_SIZE;

    char output_buffer[BUFFER_SIZE];
    int output_pos = 0;

    uint8_t lookup[100];

    void _update_input_buffer() {
        if (input_pos >= input_read && input_read == BUFFER_SIZE) {
            input_read = fread(input_buffer, sizeof(char), BUFFER_SIZE, stdin);
            input_pos = 0;
        }
    }

    char next_char(bool advance = true) {
        _update_input_buffer();
        return input_buffer[advance ? input_pos++ : input_pos];
    }

    template<typename T>
    void read_int(T &number) {
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

    void flush_output() {
        fwrite(output_buffer, sizeof(char), output_pos, stdout);
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
        // Make sure flush_output() is called at the end of the program.
        bool exit_success = atexit(flush_output) == 0;
        assert(exit_success);

        for (int i = 0; i < 100; i++)
            lookup[i] = (i / 10 << 4) + i % 10;
    }
}


int N;
long long T;
vector<long long> A;
vector<int> X;
vector<bool> good;
vector<bool> bad;

int main() {
    IO::init();
    IO::read_int(N);
    IO::read_int(T);
    A.resize(N);
    X.resize(N);
    good.assign(N, false);
    bad.assign(N, false);

    for (int i = 0; i < N; i++)
        IO::read_int(A[i]);

    vector<pair<int, int>> events;

    for (int i = 0; i < N; i++) {
        IO::read_int(X[i]);
        X[i]--;

        if (X[i] < i || (i > 0 && X[i] < X[i - 1])) {
            puts("No");
            return 0;
        }

        bad[X[i]] = true;

        events.emplace_back(i, +1);
        events.emplace_back(X[i], -1);
    }

    sort(events.begin(), events.end());
    int e_index = 0, e_count = 0;

    for (int position = 0; position < N; position++) {
        while (e_index < (int) events.size() && events[e_index].first == position)
            e_count += events[e_index++].second;

        if (e_count > 0)
            good[position] = true;
    }

    for (int i = 0; i < N; i++)
        if (good[i] && bad[i]) {
            puts("No");
            return 0;
        }

    vector<long long> B;

    for (int i = 0; i < N; i++) {
        long long value = A[i] + T;

        if (i > 0)
            value = max(value, B[i - 1] + 1);

        if (good[i]) {
            assert(i < N - 1);
            value = max(value, A[i + 1] + T);
        } else if (bad[i]) {
            if (i < N - 1 && value >= A[i + 1] + T) {
                puts("No");
                return 0;
            }
        }

        B.push_back(value);
    }

    puts("Yes");

    for (int i = 0; i < N; i++)
        IO::write_int(B[i], i < N - 1 ? ' ' : '\n');
}
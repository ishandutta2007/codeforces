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
        // Make sure _flush_output() is called at the end of the program.
        bool exit_success = atexit(_flush_output) == 0;
        assert(exit_success);

        for (int i = 0; i < 100; i++)
            lookup[i] = (i / 10 << 4) + i % 10;
    }
}


const int OFFSET = 5;
const int D_MAX = 7050;
const int INF = 1e9 + 5;

int N;
vector<int> A;
double angle_save[D_MAX];

inline double single_angle(int distance) {
    if (angle_save[distance] < 0)
        angle_save[distance] = atan2(1, distance);

    return angle_save[distance];
}

double solve(int x) {
    static int index = 0;

    while (index < N && A[index] < x)
        index++;

    int left = index - 1, right = index;
    int left_dist = INF, right_dist = INF;
    double answer = 0;

    if (left >= 0)
        left_dist = x - 1 - A[left];

    if (right < N)
        right_dist = A[right] - x;

    int start_dist = min(left_dist, right_dist);
    answer = single_angle(start_dist);

    while (left >= 0 && right < N) {
        left_dist = x - 1 - A[left];
        right_dist = A[right] - x;

        if (max(left_dist, right_dist) > 2 * start_dist + OFFSET)
            break;

        if (abs(left_dist - right_dist) <= 1) {
            answer = max(answer, 2 * single_angle(max(left_dist, right_dist)));
            break;
        }

        if (left_dist < right_dist)
            left--;
        else
            right++;
    }

    return answer;
}

int main() {
    IO::init();
    fill(angle_save, angle_save + D_MAX, -1);
    int D;
    IO::read_int(N, D);
    A.resize(N);

    for (int &a : A)
        IO::read_int(a);

    int M;
    IO::read_int(M);

    while (M-- > 0) {
        int x;
        IO::read_int(x);
        IO::write_double(solve(x), '\n', 9);
    }
}
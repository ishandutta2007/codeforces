#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;


namespace IO {
    const int BUFFER_SIZE = 4096;
    const int NUMBER_BUFFER = 100;

    FILE *input_stream = stdin;
    FILE *output_stream = stdout;

    char input_buffer[BUFFER_SIZE];
    int input_pos = BUFFER_SIZE;
    int input_read = BUFFER_SIZE;

    char output_buffer[BUFFER_SIZE];
    int output_pos = 0;

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
            number_buffer[length++] = number % 10 + '0';
            number /= 10;
        } while (number > 0);

        for (int i = length - 1; i >= 0; i--)
            write_char(number_buffer[i]);

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


const int HAND_SOLVE = 59;

int N;
vector<int> sequence;

int main() {
    IO::read_int(N);
    sequence.resize(N);

    for (int i = 0; i < N; i++) {
        long long a;
        IO::read_int(a);
        sequence[i] = __builtin_popcountll(a);
    }

    long long total = 0;

    for (int i = 0; i < N; i++) {
        long long sum = 0;
        int most = 0;

        for (int j = i; j < min(i + HAND_SOLVE, N); j++) {
            sum += sequence[j];
            most = max(most, sequence[j]);

            if (sum % 2 == 0 && 2 * most <= sum)
                total++;
        }
    }

    vector<int> partial(N + 1, 0);
    vector<int> counts(2, 0);
    partial[0] = 0;

    for (int i = 1; i <= N; i++) {
        partial[i] = partial[i - 1] + sequence[i - 1];
        total += counts[partial[i] % 2];

        if (i >= HAND_SOLVE)
            counts[partial[i - HAND_SOLVE] % 2]++;
    }

    IO::write_int(total, '\n');
}
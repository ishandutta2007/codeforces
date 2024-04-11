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


const int NM_MAX = 1024;
const int MOD = 998244353;

int encode(int r, int c) {
    return r * NM_MAX + c;
}

template<typename T>
void decode(int encoded, T &r, T &c) {
    r = encoded / NM_MAX;
    c = encoded % NM_MAX;
}

struct entry {
    int value;
    int location;

    bool operator<(const entry &other) const {
        return value < other.value;
    }
};

int N, M;
int expectation[NM_MAX][NM_MAX];
int inv[NM_MAX * NM_MAX];

template<typename T1, typename T2>
void mod_add(T1 &a, T2 b) {
    a += b;

    if (a >= MOD)
        a -= MOD;
}

int main() {
    IO::read_int(N);
    IO::read_int(M);
    vector<entry> entries;

    for (int r = 0; r < N; r++)
        for (int c = 0; c < M; c++) {
            int a;
            IO::read_int(a);
            entries.push_back({a, encode(r, c)});
        }

    sort(entries.begin(), entries.end());
    inv[0] = inv[1] = 1;

    for (int i = 2; i <= N * M; i++)
        inv[i] = (long long) (MOD - MOD / i) * inv[MOD % i] % MOD;

    int r_sum = 0, r_square_sum = 0;
    int c_sum = 0, c_square_sum = 0;
    int expectation_sum = 0;

    for (int i = 0, j = 0; i < N * M; i = j) {
        while (j < N * M && entries[i].value == entries[j].value)
            j++;

        for (int k = i; k < j; k++) {
            int r, c;
            decode(entries[k].location, r, c);
            long long sum = (long long) (r * r + c * c) * i - 2 * ((long long) r * r_sum + (long long) c * c_sum) +
                (r_square_sum + c_square_sum) + expectation_sum;
            expectation[r][c] = (sum % MOD + MOD) * inv[i] % MOD;
        }

        for (int k = i; k < j; k++) {
            int r, c;
            decode(entries[k].location, r, c);
            mod_add(r_sum, r);
            mod_add(c_sum, c);
            mod_add(r_square_sum, r * r);
            mod_add(c_square_sum, c * c);
            mod_add(expectation_sum, expectation[r][c]);
        }
    }

    int R, C;
    IO::read_int(R);
    IO::read_int(C);
    R--; C--;
    IO::write_int(expectation[R][C], '\n');
}
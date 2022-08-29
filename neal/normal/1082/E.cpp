#include <iostream>
using namespace std;


namespace IO {
    const int BUFFER_SIZE = 1 << 15;

    char input_buffer[BUFFER_SIZE];
    int input_pos = 0, input_len = 0;

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
}


template<typename T1, typename T2>
void maximize(T1 &a, const T2 &b) {
    if (b > a) {
        a = b;
    }
}


const int N_MAX = 5e5 + 5;

int N, C;
int A[N_MAX];
int last_prefix_sum[N_MAX];
int running_sum[N_MAX];

int main() {
    IO::read_int(N);
    IO::read_int(C);

    for (int i = 0; i < N; i++)
        IO::read_int(A[i]);

    int c_count = 0, max_improve = 0, prefix_sum = 0;

    for (int i = 0; i < N; i++)
        if (A[i] == C) {
            c_count++;
            prefix_sum++;
        } else {
            running_sum[A[i]] = max(running_sum[A[i]] - (prefix_sum - last_prefix_sum[A[i]]), 0) + 1;
            last_prefix_sum[A[i]] = prefix_sum;
            maximize(max_improve, running_sum[A[i]]);
        }

    printf("%d\n", c_count + max_improve);
}
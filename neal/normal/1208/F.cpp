#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

namespace IO {
    const int BUFFER_SIZE = 1 << 15;

    char input_buffer[BUFFER_SIZE];
    int input_pos = 0, input_len = 0;

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
}


const int BITS = 21;

int N;
vector<int> A;
uint8_t status[1 << BITS];
int masks[1 << BITS];

void add_mask(int mask) {
    if (status[mask] == 2)
        return;

    int n_masks = 0;
    masks[n_masks++] = mask;

    for (int bit = 0; bit < BITS; bit++) {
        if ((mask >> bit & 1) == 0)
            continue;

        int original_size = n_masks;

        for (int i = 0; i < original_size; i++)
            if (masks[i] >> bit & 1) {
                int next_mask = masks[i] ^ 1 << bit;

                if (status[next_mask] < 2)
                    masks[n_masks++] = next_mask;
            }
    }

    for (int i = 0; i < n_masks; i++)
        status[masks[i]]++;
}

int main() {
    IO::read_int(N);
    A.resize(N);

    for (int &a : A)
        IO::read_int(a);

    int answer = 0;

    for (int i = N - 1; i >= 0; i--) {
        int current = 0;

        for (int bit = BITS - 1; bit >= 0; bit--)
            if ((A[i] >> bit & 1) == 0 && status[current | 1 << bit] == 2)
                current |= 1 << bit;

        if (i <= N - 3)
            answer = max(answer, current | A[i]);

        add_mask(A[i]);
    }

    cout << answer << '\n';
}
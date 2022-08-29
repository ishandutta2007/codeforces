#include <algorithm>
#include <bitset>
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

const int A_MAX = 1e7 + 5;

int main() {
    int N;
    IO::read_int(N);
    vector<int> A(N);
    bitset<A_MAX> exists;
    long long best = (long long) A_MAX * A_MAX;
    int best_a = -1, best_b = -1;

    for (auto &a : A) {
        IO::read_int(a);

        if (!exists[a])
            exists[a] = true;
        else if (a < best)
            best = best_a = best_b = a;
    }

    for (int g = 1; g < A_MAX && 2 * g < best; g++) {
        int a = -1, b = -1, target = A_MAX;
        int i = g;
        long long product = g;

        while (i < A_MAX && product < best) {
            if (exists[i]) {
                a = i;
                target = min(best / (a / g), (long long) A_MAX);
                i += g;
                break;
            }

            product += 2 * i + g;
            i += g;
        }

        if (a < 0)
            continue;

        while (i < target) {
            if (exists[i]) {
                b = i;
                break;
            }

            i += g;
        }

        if (b < 0)
            continue;

        long long lcm = (long long) a * b / g;

        if (lcm < best) {
            best = lcm;
            best_a = a;
            best_b = b;
        }
    }

    int a_index = -1, b_index = -1;

    for (int i = 0; i < N; i++)
        if (a_index < 0 && A[i] == best_a)
            a_index = i;
        else if (b_index < 0 && A[i] == best_b)
            b_index = i;

    if (a_index > b_index)
        swap(a_index, b_index);

    cout << a_index + 1 << ' ' << b_index + 1 << '\n';
}
#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math,inline")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,lzcnt,mmx,abm,avx,avx2,fma")

// Note: for Topcoder, remove abm, avx, and avx2.
// Note: for purely unrolling loops, also try running with just the first line only.

// Hack to make bitsets 64-bit rather than 32-bit on Windows. See https://codeforces.com/blog/entry/77480
#if defined(_WIN64)
#include <string>
#include <bits/functexcept.h>
#include <iosfwd>
#include <bits/cxxabi_forced.h>
#include <bits/functional_hash.h>

#pragma push_macro("__SIZEOF_LONG__")
#pragma push_macro("__cplusplus")
#define __SIZEOF_LONG__ __SIZEOF_LONG_LONG__
#define unsigned unsigned long
#define __cplusplus 201102L

#define __builtin_popcountl __builtin_popcountll
#define __builtin_ctzl __builtin_ctzll

#include <bitset>

#pragma pop_macro("__cplusplus")
#pragma pop_macro("__SIZEOF_LONG__")
#undef unsigned
#undef __builtin_popcountl
#undef __builtin_ctzl
#endif

// Solution to https://codeforces.com/contest/1097/problem/F
#include <algorithm>
#include <bitset>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

namespace IO {
    const int BUFFER_SIZE = 1 << 15;

    char input_buffer[BUFFER_SIZE];
    size_t input_pos = 0, input_len = 0;

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
            number_buffer[length++] = char((lookup_value & 15) + '0');
            number_buffer[length++] = char((lookup_value >> 4) + '0');
        }

        if (number != 0 || length == 0)
            write_char(char(number + '0'));

        for (int i = length - 1; i >= 0; i--)
            write_char(number_buffer[i]);

        if (after)
            write_char(after);
    }

    void init() {
        // Make sure _flush_output() is called at the end of the program.
        bool exit_success = atexit(_flush_output) == 0;
        assert(exit_success);

        for (int i = 0; i < 100; i++)
            lookup[i] = uint8_t((i / 10 << 4) + i % 10);
    }
}


const int V_MAX = 7005;

int N, Q;
bitset<V_MAX> square_free;
bitset<V_MAX> mobius[V_MAX];
vector<bitset<V_MAX>> values;

int main() {
    IO::init();

    square_free.set();

    for (int i = 1; i < V_MAX; i++)
        for (int p = 2; p * p <= i; p++)
            if (i % (p * p) == 0)
                square_free[i] = 0;

    for (int i = 1; i < V_MAX; i++)
        for (int j = 1; i * j < V_MAX; j++)
            mobius[i][i * j] = square_free[j];

    IO::read_int(N, Q);
    values.resize(N);

    for (int q = 0; q < Q; q++) {
        int type, x, y, z;
        IO::read_int(type, x, y);
        x--;

        if (type == 2 || type == 3) {
            IO::read_int(z);
            y--; z--;
        }

        if (type == 1) {
            values[x].reset();

            for (int i = 1; i * i <= y; i++)
                if (y % i == 0)
                    values[x][i] = values[x][y / i] = 1;
        } else if (type == 2) {
            values[x] = values[y] ^ values[z];
        } else if (type == 3) {
            values[x] = values[y] & values[z];
        } else if (type == 4) {
            IO::write_char(char((values[x] & mobius[y]).count() % 2 + '0'));
        }
    }

    IO::write_char('\n');
}
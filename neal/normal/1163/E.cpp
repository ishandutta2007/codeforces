#include <algorithm>
#include <cassert>
#include <chrono>
#include <iostream>
#include <random>
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

    void init() {
        // Make sure _flush_output() is called at the end of the program.
        bool exit_success = atexit(_flush_output) == 0;
        assert(exit_success);

        for (int i = 0; i < 100; i++)
            lookup[i] = (i / 10 << 4) + i % 10;
    }
}


mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count() * ((uint64_t) new char | 1));

const int BITS = 18;

template<typename T>
struct xor_basis {
    // A list of basis values sorted in decreasing order, where each value has a unique highest bit.
    // We use a static array instead of a vector for better performance.
    T basis[BITS];
    int n = 0;

    T min_value(T start) const {
        for (int i = 0; i < n; i++)
            start = min(start, start ^ basis[i]);

        return start;
    }

    T max_value(T start = 0) const {
        for (int i = 0; i < n; i++)
            start = max(start, start ^ basis[i]);

        return start;
    }

    bool add(T x) {
        if (n == BITS)
            return false;

        x = min_value(x);

        if (x == 0)
            return false;

        basis[n++] = x;

        // Insertion sort.
        for (int k = n - 1; k > 0 && basis[k] > basis[k - 1]; k--)
            swap(basis[k], basis[k - 1]);

        return true;
    }

    void merge(const xor_basis<T> &other) {
        for (int i = 0; i < other.n && n < BITS; i++)
            add(other.basis[i]);
    }

    void merge(const xor_basis<T> &a, const xor_basis<T> &b) {
        *this = a;
        merge(b);
    }
};

int main() {
    IO::init();

    int N;
    IO::read_int(N);
    vector<int> S(N);

    for (int &s : S)
        IO::read_int(s);

    shuffle(S.begin(), S.end(), rng);
    vector<int> original;

    for (int bits = BITS; bits >= 0; bits--) {
        xor_basis<int> basis;
        original.clear();

        for (int s : S)
            if (s < 1 << bits && basis.add(s))
                original.push_back(s);

        if ((int) original.size() == bits)
            break;
    }

    int bits = original.size();
    vector<int> permutation = {0};
    int number = 0;

    for (int i = 1; i < 1 << bits; i++) {
        number ^= original[__builtin_ctz(i)];
        permutation.push_back(number);
    }

    IO::write_int(bits, '\n');

    for (int i = 0; i < 1 << bits; i++)
        IO::write_int(permutation[i], i < (1 << bits) - 1 ? ' ' : '\n');
}
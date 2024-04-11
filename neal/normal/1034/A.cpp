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


vector<int> smallest_factor;
vector<bool> prime;

void sieve(int maximum) {
    assert(maximum > 0);
    smallest_factor.assign(maximum + 1, 0);
    prime.assign(maximum + 1, true);
    prime[0] = prime[1] = false;

    for (int p = 2; p <= maximum; p += 2) {
        prime[p] = p == 2;
        smallest_factor[p] = 2;
    }

    for (int p = 3; p * p <= maximum; p += 2)
        if (prime[p])
            for (int i = p * p; i <= maximum; i += 2 * p)
                if (prime[i]) {
                    prime[i] = false;
                    smallest_factor[i] = p;
                }

    for (int p = 3; p <= maximum; p += 2)
        if (prime[p])
            smallest_factor[p] = p;
}


template<typename T1, typename T2>
void maximize(T1 &a, const T2 &b) {
    if (b > a)
        a = b;
}


const int N_MAX = 3e5 + 5;
const int A_MAX = 1.5e7 + 5;

int N;
int numbers[N_MAX];
int freq[A_MAX];

int main() {
    sieve(A_MAX);
    IO::read_int(N);
    int G = 0;

    for (int i = 0; i < N; i++) {
        IO::read_int(numbers[i]);
        G = __gcd(G, numbers[i]);
    }

    int highest = 0;

    for (int i = 0; i < N; i++) {
        int x = numbers[i] / G;

        while (x > 1) {
            int factor = smallest_factor[x];

            do {
                x /= factor;
            } while (smallest_factor[x] == factor);

            maximize(highest, ++freq[factor]);
        }
    }

    printf("%d\n", highest == 0 ? -1 : N - highest);
}
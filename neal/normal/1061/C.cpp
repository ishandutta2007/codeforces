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
}


vector<int> smallest_factor;
vector<bool> prime;
vector<int> primes;

void sieve(int maximum) {
    maximum = max(maximum, 2);
    smallest_factor.assign(maximum + 1, 0);
    prime.assign(maximum + 1, true);
    prime[0] = prime[1] = false;
    primes = {2};

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
        if (prime[p]) {
            smallest_factor[p] = p;
            primes.push_back(p);
        }
}


template<typename int_array>
int generate_factors(int n, int_array &&factors, bool sorted = false) {
    // http://oeis.org/A066150
    static const int FACTORS_MAX = 2000;
    static int buffer[FACTORS_MAX];

    assert(n >= 1);
    int f_count = 0;
    factors[f_count++] = 1;

    while (n != 1) {
        int p = smallest_factor[n], exponent = 0;

        do {
            n /= p;
            exponent++;
        } while (n % p == 0);

        int before_count = f_count;

        for (int e = 1; e <= exponent; e++)
            for (int i = 0; i < before_count; i++) {
                factors[f_count] = factors[f_count - before_count] * p;
                f_count++;
            }

        if (sorted && factors[before_count - 1] > p) {
            for (int section = before_count; section < f_count; section *= 2)
                for (int i = 0; i + section < f_count; i += 2 * section) {
                    int length = min(2 * section, f_count - i);
                    merge(factors + i, factors + i + section, factors + i + section, factors + i + length, buffer);
                    copy(buffer, buffer + length, factors + i);
                }
        }
    }

    return f_count;
}


const int N_MAX = 1e5 + 5;
const int A_MAX = 1e6 + 5;
const int MOD = 1e9 + 7;
const int FACTORS_MAX = 1000;

int N;
int factors[FACTORS_MAX];
unsigned ways[N_MAX];

inline unsigned mod_add(unsigned a, unsigned b, unsigned m = MOD) {
    return a < m - b ? a + b : a + b - m;
}

int main() {
    sieve(A_MAX);
    IO::read_int(N);
    ways[0] = 1;

    for (int i = 0; i < N; i++) {
        int a;
        IO::read_int(a);
        int count = generate_factors(a, factors, true);

        for (int f = count - 1; f >= 0; f--) {
            int x = factors[f];

            if (x <= N)
                ways[x] = mod_add(ways[x], ways[x - 1]);
        }
    }

    long long total = 0;

    for (int i = 1; i <= N; i++)
        total += ways[i];

    printf("%lld\n", total % MOD);
}
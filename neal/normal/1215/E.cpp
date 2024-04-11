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


const int A = 20;
const long long LL_INF = (long long) 2e18 + 5;

long long inversions[A][A];
long long subset_sums[A][1 << A];

void compute_subset_sums(int index) {
    vector<long long> change(A, 0);
    long long sum = 0;

    for (int i = 0; i < A; i++) {
        change[i] = inversions[index][i] - sum;
        sum += inversions[index][i];
    }

    sum = 0;

    for (int mask = 1; mask < 1 << A; mask++) {
        sum += change[__builtin_ctz(mask)];
        subset_sums[index][mask] = sum;
    }
}

int main() {
    int N;
    IO::read_int(N);
    vector<int> counts(A, 0);

    for (int i = 0; i < N; i++) {
        int a;
        IO::read_int(a);
        a--;

        for (int x = 0; x < A; x++)
            inversions[a][x] += counts[x];

        counts[a]++;
    }

    for (int i = 0; i < A; i++) {
        inversions[i][i] = 0;
        compute_subset_sums(i);
    }

    vector<long long> dp(1 << A, LL_INF);
    dp[0] = 0;

    for (int mask = 0; mask < 1 << A; mask++)
        for (int prefix = mask; prefix != 0; prefix &= prefix - 1) {
            int bit = __builtin_ctz(prefix);
            dp[mask] = min(dp[mask], dp[mask ^ 1 << bit] + subset_sums[bit][mask]);
        }

    cout << dp[(1 << A) - 1] << '\n';
}
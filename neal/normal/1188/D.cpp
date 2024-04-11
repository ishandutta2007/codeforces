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

const int BITS = 58;
const int INF = 1e9 + 5;

int N;
vector<long long> A;

int main() {
    IO::read_int(N);
    A.resize(N);

    for (auto &a : A)
        IO::read_int(a);

    vector<int> dp(N + 1, INF), next_dp(N + 1);
    dp[0] = 0;

    vector<long long> zeros(N), ones(N);

    for (int bit = 0; bit < BITS; bit++) {
        next_dp.assign(N + 1, INF);

        int zero_count = 0, one_count = 0;
        int zero_carry = 0, one_carry = 0;
        int num_zeros = 0, num_ones = 0;

        for (int i = 0; i < N; i++)
            if (A[i] >> bit & 1) {
                one_count++;
                zero_carry++;
                ones[num_ones++] = A[i];
            } else {
                zero_count++;
                zeros[num_zeros++] = A[i];
            }

        for (int carry = 0; carry <= N; carry++) {
            next_dp[one_carry] = min(next_dp[one_carry], dp[carry] + zero_count);
            next_dp[zero_carry] = min(next_dp[zero_carry], dp[carry] + one_count);

            if (carry < N) {
                if (A[carry] >> bit & 1) {
                    zero_count++;
                    one_count--;
                    one_carry++;
                } else {
                    one_count++;
                    zero_count--;
                    zero_carry++;
                }
            }
        }

        swap(dp, next_dp);

        // Redo the sorting by the current bit: 1s then 0s. This way, at the start of the loop A[i] is sorted in
        // decreasing order based on the last `bit` bits.
        int n = 0;

        for (int i = 0; i < num_ones; i++)
            A[n++] = ones[i];

        for (int i = 0; i < num_zeros; i++)
            A[n++] = zeros[i];
    }

    cout << min(dp[0], dp[N]) << '\n';
}
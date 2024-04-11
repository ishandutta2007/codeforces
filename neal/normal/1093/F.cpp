#include <algorithm>
#include <cassert>
#include <cstring>
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


const int MOD = 998244353;
const int N_MAX = 1e5 + 1, K_MAX = 101;

int N, K, L;
int A[N_MAX];
int freq[K_MAX];

// dp[n][k] = how many ways to get the first n, ending with k
// dp[n][0] = sum of dp[n][k] for all k from 1 to K
int dp[N_MAX][K_MAX];

int main() {
    IO::read_int(N, K, L);

    for (int i = 0; i < N; i++) {
        IO::read_int(A[i]);

        if (A[i] < 0)
            A[i] = 0;
    }

    if (L == 1) {
        puts("0");
        return 0;
    }

    // memset(dp, 0, sizeof(dp)); 
    // memset(freq, 0, sizeof(freq));
    dp[0][0] = 1;

    for (int n = 1; n <= N; n++) {
        int current = A[n - 1];
        freq[current]++;

        if (current <= 0) {
            fill(dp[n] + 1, dp[n] + K + 1, dp[n - 1][0]);

            // for (int k = 1; k <= K; k++)
            //     dp[n][k] = dp[n - 1][0];
        } else {
            dp[n][current] = dp[n - 1][0];
        }

        // Subtract ways that make it invalid for the first time at this point. 
        for (int k = 1; k <= K; k++)
            if (freq[0] + freq[k] == L) {
                dp[n][k] -= dp[n - L][0] - dp[n - L][k];

                if (dp[n][k] >= MOD)
                    dp[n][k] -= MOD;
                else if (dp[n][k] < 0)
                    dp[n][k] += MOD;
            }

        uint64_t sum = 0;

        for (int k = 1; k <= K; k++)
            sum += dp[n][k];

        dp[n][0] = sum % MOD;

        if (n >= L)
            freq[A[n - L]]--;
    }

    printf("%d\n", dp[N][0]);
}
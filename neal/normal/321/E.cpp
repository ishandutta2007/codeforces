// Solution to https://codeforces.com/contest/321/problem/E
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

template<typename T1, typename T2>
bool minimize(T1 &a, const T2 &b) {
    if (b < a) {
        a = b;
        return true;
    }

    return false;
}

const int N_MAX = 4096;
const int INF = 1e9 + 5;

int N, K;
int cost[N_MAX][N_MAX];

int main() {
    IO::read_int(N, K);

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++) {
            IO::next_char();
            cost[i][j] = IO::next_char() - '0';
            // scanf("%d", &cost[i][j]);
        }

    vector<int> left_sum(N + 1, 0);

    for (int i = N - 1; i >= 0; i--) {
        left_sum[i] = 0;

        for (int j = i + 1; j <= N; j++)
            left_sum[j] = left_sum[j - 1] + cost[i][j - 1];

        for (int j = i + 1; j <= N; j++)
            cost[i][j] = left_sum[j] + cost[i + 1][j];
    }

    vector<int> dp(N + 1, INF), next_dp;
    vector<int16_t> opt(N + 1, N);
    dp[N] = 0;

    for (int k = 1; k <= K; k++) {
        next_dp.assign(N + 1, INF);

        for (int i = 0; i <= N; i++) {
            int next_opt = -1;

            for (int j = i == 0 ? 0 : opt[i - 1]; j <= opt[i]; j++)
                if (minimize(next_dp[i], cost[i][j] + dp[j]))
                    next_opt = j;

            opt[i] = next_opt;
        }

        swap(dp, next_dp);
    }

    printf("%d\n", dp[0]);
}
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

const long long LL_INF = (long long) 2e18 + 5;

template<typename T1, typename T2>
void minimize(T1 &a, const T2 &b) {
    if (b < a)
        a = b;
}

int main() {
    int N, M, K;
    IO::read_int(N, M, K);
    vector<int> shovels(N);

    for (auto &s : shovels)
        IO::read_int(s);

    nth_element(shovels.begin(), shovels.begin() + K, shovels.end());
    sort(shovels.begin(), shovels.begin() + K);
    vector<long long> shovel_sum(K + 1, 0);

    for (int i = 0; i < K; i++)
        shovel_sum[i + 1] = shovel_sum[i] + shovels[i];

    vector<int> best_offer(K + 1);

    for (int i = 0; i <= K; i++)
        best_offer[i] = i;

    for (int i = 0; i < M; i++) {
        int x, y;
        IO::read_int(x, y);
        y = x - y;

        if (x <= K)
            best_offer[x] = min(best_offer[x], y);
    }

    vector<long long> dp(K + 1, LL_INF);
    dp[0] = 0;

    for (int k = 1; k <= K; k++)
        for (int x = 1; x <= k; x++)
            minimize(dp[k], dp[k - x] + shovel_sum[k] - shovel_sum[k - best_offer[x]]);

    cout << dp[K] << '\n';
}
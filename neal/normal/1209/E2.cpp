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


void solve_case() {
    int N, M;
    IO::read_int(N, M);
    vector<vector<int>> A(M, vector<int>(N));

    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            IO::read_int(A[j][i]);

    M = min(M, N);

    nth_element(A.begin(), A.begin() + M, A.end(), [&](const vector<int> &x, const vector<int> &y) {
        return *max_element(x.begin(), x.end()) > *max_element(y.begin(), y.end());
    });

    A.resize(M);
    vector<int> dp(1 << N, 0);

    for (vector<int> row : A) {
        for (int i = 0; i < N; i++)
            for (int mask = 0; mask < 1 << N; mask++)
                if (mask >> i & 1)
                    dp[mask] = max(dp[mask], dp[mask ^ 1 << i] + row[i]);

        vector<bool> done(1 << N, false);

        for (int mask = 0; mask < 1 << N; mask++) {
            if (done[mask])
                continue;

            int rotation = mask, most = 0;

            for (int i = 0; i < N; i++) {
                most = max(most, dp[rotation]);
                rotation = (rotation >> 1) + ((rotation & 1) << (N - 1));
            }

            for (int i = 0; i < N; i++) {
                dp[rotation] = most;
                done[rotation] = true;
                rotation = (rotation >> 1) + ((rotation & 1) << (N - 1));
            }
        }
    }

    cout << dp[(1 << N) - 1] << '\n';
}

int main() {
    int T;
    IO::read_int(T);

    while (T-- > 0)
        solve_case();
}
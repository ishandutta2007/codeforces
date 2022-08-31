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

struct truck {
    int start, finish, consume, refuel;
};

int N, M;
vector<int> A;
vector<vector<truck>> trucks_at_start;

int main() {
    IO::read_int(N, M);
    A.resize(N);
    trucks_at_start.resize(N);

    for (int &a : A)
        IO::read_int(a);

    for (int i = 0; i < M; i++) {
        truck t;
        IO::read_int(t.start, t.finish, t.consume, t.refuel);
        t.start--; t.finish--;
        t.refuel = min(t.refuel, t.finish - t.start);
        trucks_at_start[t.start].push_back(t);
    }

    vector<vector<int>> dp(N, vector<int>(N));
    long long answer = 0;

    for (int start = 0; start < N - 1; start++) {
        for (int finish = start; finish < N; finish++)
            dp[0][finish] = A[finish] - A[start];

        for (int refuel = 1; refuel < N - start; refuel++) {
            int opt = start;

            for (int finish = start + refuel; finish < N; finish++) {
                dp[refuel][finish] = max(dp[refuel - 1][opt], A[finish] - A[opt]);

                while (opt < finish && minimize(dp[refuel][finish], max(dp[refuel - 1][opt + 1], A[finish] - A[opt + 1])))
                    opt++;
            }
        }

        for (truck &t : trucks_at_start[start])
            answer = max(answer, (long long) t.consume * dp[t.refuel][t.finish]);
    }

    printf("%lld\n", answer);
}
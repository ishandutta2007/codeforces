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


const int MOD = 1e9 + 7;

int N;
vector<long long> subtree_sum;
vector<int> parent;

int main() {
    IO::read_int(N);
    subtree_sum.assign(N, 0);
    parent.assign(N, -1);

    for (int i = 0; i < N; i++) {
        int a;
        IO::read_int(a);
        subtree_sum[i] = a;
    }

    for (int i = 1; i < N; i++) {
        IO::read_int(parent[i]);
        parent[i]--;
    }

    for (int i = N - 1; i > 0; i--)
        subtree_sum[parent[i]] += subtree_sum[i];

    vector<int> freq(N + 1, 0);

    for (int i = 0; i < N; i++) {
        long long number = subtree_sum[0] / __gcd(subtree_sum[0], subtree_sum[i]);

        if (number <= N)
            freq[number]++;
    }

    for (int i = N; i > 0; i--)
        for (int j = 2 * i; j <= N; j += i)
            freq[j] += freq[i];

    for (int i = 1; i <= N; i++)
        freq[i] = freq[i] == i ? 1 : 0;

    for (int i = N; i > 0; i--)
        if (freq[i] > 0) {
            long long sum = 0;

            for (int j = i; j <= N; j += i)
                sum += freq[j];

            if (sum >= MOD)
                sum %= MOD;

            freq[i] = sum;
        }

    cout << freq[1] << '\n';
}
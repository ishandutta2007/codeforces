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
        number = 0;

        while (!isdigit(next_char(false)))
            next_char();

        do {
            number = 10 * number + (next_char() - '0');
        } while (isdigit(next_char(false)));
    }

    template<typename T, typename... Args>
    inline void read_int(T &number, Args &... args) {
        read_int(number);
        read_int(args...);
    }
}

int main() {
    int N, X;
    IO::read_int(N, X);
    vector<int> A(N);
    vector<int> first_occurrence(X + 1, -1);
    vector<int> last_occurrence(X + 1, -1);

    for (auto &a : A)
        IO::read_int(a);

    for (int i = 0; i < N; i++) {
        if (first_occurrence[A[i]] < 0)
            first_occurrence[A[i]] = i;

        last_occurrence[A[i]] = i;
    }

    vector<int> prefix_end(X + 2, 0);
    vector<int> suffix_start(X + 2, N);

    for (int x = 1; x <= X; x++) {
        if (prefix_end[x - 1] < 0 || first_occurrence[x] < 0)
            prefix_end[x] = prefix_end[x - 1];
        else if (prefix_end[x - 1] > first_occurrence[x])
            prefix_end[x] = -1;
        else
            prefix_end[x] = last_occurrence[x] + 1;
    }

    for (int x = X; x > 0; x--) {
        if (suffix_start[x + 1] < 0 || last_occurrence[x] < 0)
            suffix_start[x] = suffix_start[x + 1];
        else if (last_occurrence[x] > suffix_start[x + 1])
            suffix_start[x] = -1;
        else
            suffix_start[x] = first_occurrence[x];
    }

    long long total = 0;

    // for (int left = 1; left <= X; left++)
    //     for (int right = left; right <= X; right++)
    //         if (prefix_end[left - 1] >= 0 && suffix_start[right + 1] >= 0 && prefix_end[left - 1] <= suffix_start[right + 1])
    //             total++;

    for (int left = 1, right = 1; left <= X; left++) {
        if (prefix_end[left - 1] < 0)
            break;

        while (right < left)
            right++;

        while (right <= X && (suffix_start[right + 1] < 0 || prefix_end[left - 1] > suffix_start[right + 1]))
            right++;

        total += X + 1 - right;
    }

    cout << total << '\n';
}
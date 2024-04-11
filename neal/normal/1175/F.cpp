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


int N;
vector<int> A;
vector<int> farthest;
vector<int> range_max;

int solve(int one) {
    int start = one, end = one + 1;
    range_max[one] = range_max[one + 1] = 1;

    while (start > 0 && A[start - 1] != 1) {
        start--;
        range_max[start] = max(range_max[start + 1], A[start]);
    }

    while (end < N && A[end] != 1) {
        range_max[end + 1] = max(range_max[end], A[end]);
        end++;
    }

    int count = 0;

    for (int left = one - 1; left >= start; left--) {
        int biggest = range_max[left];
        int right = left + biggest;

        if (one < right && right <= end && range_max[right] <= biggest && right <= farthest[left])
            count++;
    }

    for (int right = one + 1; right <= end; right++) {
        int biggest = range_max[right];
        int left = right - biggest;

        if (start <= left && left <= one && range_max[left] <= biggest && right <= farthest[left])
            count++;
    }

    return count;
}

int main() {
    IO::read_int(N);
    A.resize(N);

    for (int &a : A)
        IO::read_int(a);

    farthest.assign(N, -1);
    vector<bool> seen(N + 1, false);

    // Starting from each i, find how far right we can go while staying distinct.
    for (int i = 0, j = 0; i < N; i++) {
        while (j < N && !seen[A[j]])
            seen[A[j++]] = true;

        farthest[i] = j;
        seen[A[i]] = false;
    }

    range_max.assign(N + 1, -1);
    int total = 0;

    for (int one = 0; one < N; one++)
        if (A[one] == 1)
            total += solve(one);

    cout << total << '\n';
}
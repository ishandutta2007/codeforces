#include <algorithm>
#include <array>
#include <cassert>
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

template<typename T> ostream& operator<<(ostream &os, const vector<T> &v) { os << '{'; string sep; for (const auto &x : v) os << sep << x, sep = ", "; return os << '}'; }
template<typename T, size_t size> ostream& operator<<(ostream &os, const array<T, size> &arr) { os << '{'; string sep; for (const auto &x : arr) os << sep << x, sep = ", "; return os << '}'; }
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }

void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }

#ifdef NEAL_DEBUG
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif

namespace IO {
    const int BUFFER_SIZE = 1 << 15;

    char input_buffer[BUFFER_SIZE];
    size_t input_pos = 0, input_len = 0;

    char output_buffer[BUFFER_SIZE];
    int output_pos = 0;

    char number_buffer[100];
    uint8_t lookup[100];

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

    void _flush_output() {
        fwrite(output_buffer, sizeof(char), output_pos, stdout);
        output_pos = 0;
    }

    inline void write_char(char c) {
        if (output_pos == BUFFER_SIZE)
            _flush_output();

        output_buffer[output_pos++] = c;
    }

    template<typename T>
    inline void write_int(T number, char after = '\0') {
        if (number < 0) {
            write_char('-');
            number = -number;
        }

        int length = 0;

        while (number >= 10) {
            uint8_t lookup_value = lookup[number % 100];
            number /= 100;
            number_buffer[length++] = char((lookup_value & 15) + '0');
            number_buffer[length++] = char((lookup_value >> 4) + '0');
        }

        if (number != 0 || length == 0)
            write_char(char(number + '0'));

        for (int i = length - 1; i >= 0; i--)
            write_char(number_buffer[i]);

        if (after)
            write_char(after);
    }

    void init() {
        // Make sure _flush_output() is called at the end of the program.
        bool exit_success = atexit(_flush_output) == 0;
        assert(exit_success);

        for (int i = 0; i < 100; i++)
            lookup[i] = uint8_t((i / 10 << 4) + i % 10);
    }
}


const int INF = 1e9 + 5;

int N, Q, NB, BS;
vector<int> A;
vector<vector<int16_t>> add_on;

int get_bucket_start(int b) {
    return min(b * BS, N);
}

int get_bucket_end(int b) {
    return get_bucket_start(b + 1);
}

int process(int start, int end, int count) {
    int initial = count;

    for (int i = start; i < end; i++)
        count += i - count <= A[i] && A[i] <= i;

    return count - initial;
}

pair<int, int> min_gap(int start, int end, int count) {
    int initial = count;
    int minimum = INF;

    for (int i = start; i < end; i++) {
        if (A[i] < i - count)
            minimum = min(minimum, i - count - A[i]);

        count += i - count <= A[i] && A[i] <= i;
    }

    return {count - initial, minimum};
}

void build_bucket(int b) {
    int start = get_bucket_start(b);
    int end = get_bucket_end(b);

    add_on[b].assign(N + 1, 0);

    int initial = 0;
    pair<int, int> p = min_gap(start, end, initial);
    int current = p.first;
    add_on[b][initial] = current;

    while (current < end - start) {
        int gap = p.second;

        if (gap >= INF)
            break;

        initial += gap;
        int previous = current;
        p = min_gap(start, end, initial);
        current = p.first;
        assert(current > previous);
        add_on[b][initial] = current;
    }

    for (int i = 1; i <= N; i++)
        add_on[b][i] = max(add_on[b][i], add_on[b][i - 1]);
}

int query(int start, int end) {
    int count = 0;
    int start_b = start / BS;
    int end_b = end / BS;

    if (start_b == end_b)
        return process(start, end, count);

    count += process(start, get_bucket_end(start_b), count);

    for (int b = start_b + 1; b < end_b; b++)
        count += add_on[b][count];

    count += process(get_bucket_start(end_b), end, count);
    return count;
}

int main() {
    IO::init();
    IO::read_int(N, Q);
    A.resize(N);

    for (auto &a : A) {
        IO::read_int(a);
        a--;
    }

    BS = int(2.8 * sqrt(N) + 1);
    NB = (N + BS - 1) / BS;
    add_on.assign(NB, {});

    for (int b = 0; b < NB; b++)
        build_bucket(b);

    for (int q = 0; q < Q; q++) {
        int x, y;
        IO::read_int(x, y);
        IO::write_int(query(x, N - y), '\n');
    }
}
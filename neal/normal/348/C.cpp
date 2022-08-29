#include <algorithm>
#include <bitset>
#include <cassert>
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

namespace IO {
    const int BUFFER_SIZE = 1 << 15;

    char input_buffer[BUFFER_SIZE];
    int input_pos = 0, input_len = 0;

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

    inline bool isspace(char c) {
        return (unsigned char) (c - '\t') < 5 || c == ' ';
    }

    inline void read_char(char &c) {
        while (isspace(next_char(false)))
            next_char();

        c = next_char();
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
            number_buffer[length++] = (lookup_value & 15) + '0';
            number_buffer[length++] = (lookup_value >> 4) + '0';
        }

        if (number != 0 || length == 0)
            write_char(number + '0');

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
            lookup[i] = (i / 10 << 4) + i % 10;
    }
}


const int N_MAX = 1e5 + 5;

int N, M, Q;
// S = sum of set sizes, B = number of big sets, CUTOFF = cutoff to be a big set.
int S, B, CUTOFF;
vector<long long> A;
vector<vector<int>> sets;
vector<bitset<N_MAX>> big_sets;
vector<long long> big_sum, big_add;
vector<int> index_to_big, big_to_index;
vector<vector<int>> intersection;

int compute_intersection(int index, int b) {
    if (index_to_big[index] >= 0) {
        if (index_to_big[index] == b)
            return sets[index].size();

        if (sets[index].size() > sets[big_to_index[b]].size())
            return compute_intersection(big_to_index[b], index_to_big[index]);
    }

    int count = 0;

    for (int x : sets[index])
        if (big_sets[b][x])
            count++;

    return count;
}

void preprocess() {
    CUTOFF = 1.2 * sqrt(S) + 1;
    index_to_big.assign(N, -1);
    B = 0;

    for (int i = 0; i < M; i++)
        if ((int) sets[i].size() > CUTOFF) {
            big_to_index.push_back(i);
            index_to_big[i] = B++;
            big_sets.emplace_back();
            long long sum = 0;

            for (int x : sets[i]) {
                big_sets.back()[x] = true;
                sum += A[x];
            }

            big_sum.push_back(sum);
        }

    big_add.assign(B, 0);
    intersection.assign(N, vector<int>(B, -1));

    for (int i = 0; i < M; i++)
        for (int b = 0; b < B; b++)
            if (index_to_big[i] >= 0 && intersection[big_to_index[b]][index_to_big[i]] >= 0)
                intersection[i][b] = intersection[big_to_index[b]][index_to_big[i]];
            else
                intersection[i][b] = compute_intersection(i, b);
}

long long query_big(int b) {
    long long answer = big_sum[b];

    for (int i = 0; i < B; i++)
        answer += intersection[big_to_index[b]][i] * big_add[i];

    return answer;
}

long long query_small(int index) {
    long long answer = 0;

    for (int x : sets[index])
        answer += A[x];

    for (int b = 0; b < B; b++)
        answer += intersection[index][b] * big_add[b];

    return answer;
}

long long query(int index) {
    if (index_to_big[index] >= 0)
        return query_big(index_to_big[index]);
    else
        return query_small(index);
}

void update_big(int b, long long add) {
    big_add[b] += add;
}

void update_small(int index, long long add) {
    for (int x : sets[index])
        A[x] += add;

    for (int b = 0; b < B; b++)
        big_sum[b] += intersection[index][b] * add;
}

void update(int index, long long add) {
    if (index_to_big[index] >= 0)
        update_big(index_to_big[index], add);
    else
        update_small(index, add);
}

int main() {
    IO::init();
    IO::read_int(N, M, Q);
    A.resize(N);

    for (long long &a : A) {
        int x;
        IO::read_int(x);
        a = x;
    }

    S = 0;
    sets.assign(M, {});

    for (int i = 0; i < M; i++) {
        int k;
        IO::read_int(k);
        S += k;

        while (k-- > 0) {
            int x;
            IO::read_int(x);
            x--;
            sets[i].push_back(x);
        }

        sort(sets[i].begin(), sets[i].end());
    }

    preprocess();

    for (int q = 0; q < Q; q++) {
        char type;
        int k, x;
        IO::read_char(type);
        IO::read_int(k);
        k--;

        if (type == '?') {
            IO::write_int(query(k), '\n');
        } else if (type == '+') {
            IO::read_int(x);
            update(k, x);
        } else {
            assert(false);
        }
    }
}
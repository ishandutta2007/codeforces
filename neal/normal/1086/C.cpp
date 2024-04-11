#include <algorithm>
#include <cassert>
#include <iostream>
#include <string>
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

    inline void read_str(string &str) {
        while (!isspace(next_char(false)))
            next_char();

        str.clear();

        do {
            str += next_char();
        } while (!isspace(next_char(false)));
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

    inline void write_str(const string &str, char after = '\0') {
        for (char c : str)
            write_char(c);

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


const char UNASSIGNED = '*';

int N, K;
string S, A, B;
vector<char> mapping;
vector<bool> available;

void set_mapping(char x, char y) {
    if (mapping[x] == y)
        return;

    assert(mapping[x] == UNASSIGNED);
    assert(available[y]);
    mapping[x] = y;
    available[y] = false;
}

void fill_remaining() {
    for (char c = 'a'; c < 'a' + K; c++)
        if (mapping[c] == UNASSIGNED) {
            for (int i = 'a'; i < 'a' + K; i++)
                if (available[i]) {
                    set_mapping(c, i);
                    break;
                }
        }
}

string get_template() {
    string template_str = "";

    for (char c = 'a'; c < 'a' + K; c++)
        template_str += mapping[c];

    return template_str;
}

string solve_A(int start) {
    set_mapping(S[start], A[start]);

    for (int i = start + 1; i < N; i++) {
        char goal = A[i];

        if (mapping[S[i]] != UNASSIGNED) {
            if (mapping[S[i]] < goal) {
                return "";
            } else if (mapping[S[i]] > goal) {
                fill_remaining();
                return get_template();
            }

            assert(mapping[S[i]] == goal);
            continue;
        }

        for (char c = 'a'; c < 'a' + K; c++)
            if (available[c] && c > goal) {
                set_mapping(S[i], c);
                fill_remaining();
                return get_template();
            }

        if (!available[goal])
            return "";

        assert(available[goal]);
        set_mapping(S[i], goal);
    }

    fill_remaining();
    return get_template();
}

string solve_B(int start) {
    set_mapping(S[start], B[start]);

    for (int i = start + 1; i < N; i++) {
        char goal = B[i];

        if (mapping[S[i]] != UNASSIGNED) {
            if (mapping[S[i]] > goal) {
                return "";
            } else if (mapping[S[i]] < goal) {
                fill_remaining();
                return get_template();
            }

            assert(mapping[S[i]] == goal);
            continue;
        }

        for (char c = 'a'; c < 'a' + K; c++)
            if (available[c] && c < goal) {
                set_mapping(S[i], c);
                fill_remaining();
                return get_template();
            }

        if (!available[goal])
            return "";

        assert(available[goal]);
        set_mapping(S[i], goal);
    }

    fill_remaining();
    return get_template();
}

void solve_case() {
    IO::read_int(K);
    IO::read_str(S);
    IO::read_str(A);
    IO::read_str(B);
    N = S.size();
    int equal = 0;

    while (equal < N && A[equal] == B[equal])
        equal++;

    mapping.assign(128, UNASSIGNED);
    available.assign(128, true);

    for (int i = 0; i < equal; i++) {
        bool valid = mapping[S[i]] == A[i] || (mapping[S[i]] == UNASSIGNED && available[A[i]]);

        if (!valid) {
            IO::write_str("NO", '\n');
            return;
        }

        set_mapping(S[i], A[i]);
    }

    if (equal == N) {
        // cerr << get_template() << '\n';
        fill_remaining();
        IO::write_str("YES", '\n');
        IO::write_str(get_template(), '\n');
        return;
    }

    assert(equal < N && A[equal] < B[equal]);

    for (char c = 'a'; c < 'a' + K; c++)
        if (A[equal] < c && c < B[equal])
            if (mapping[S[equal]] == c || (mapping[S[equal]] == UNASSIGNED && available[c])) {
                set_mapping(S[equal], c);
                // cerr << get_template() << '\n';
                fill_remaining();
                IO::write_str("YES", '\n');
                IO::write_str(get_template(), '\n');
                return;
            }

    char current = mapping[S[equal]];
    assert(!(A[equal] < current && current < B[equal]));

    if (current != UNASSIGNED && (current < A[equal] || current > B[equal])) {
        IO::write_str("NO", '\n');
        return;
    }

    vector<char> copy_mapping = mapping;
    vector<bool> copy_available = available;
    string answer = "";

    if (current == A[equal]) {
        answer = solve_A(equal);
    } else if (current == B[equal]) {
        answer = solve_B(equal);
    } else if (current == UNASSIGNED) {
        if (available[A[equal]])
            answer = solve_A(equal);

        mapping = copy_mapping;
        available = copy_available;

        if (available[B[equal]]) {
            string potential = solve_B(equal);

            if (potential.size() > answer.size())
                answer = potential;
        }
    }

    if (answer.empty()) {
        IO::write_str("NO", '\n');
        return;
    }

    assert((int) answer.size() == K);
    IO::write_str("YES", '\n');
    IO::write_str(answer, '\n');
}

int main() {
    IO::init();

    int T;
    IO::read_int(T);

    while (T-- > 0)
        solve_case();
}
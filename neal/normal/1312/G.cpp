#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

template<typename T> ostream& operator<<(ostream &os, const vector<T> &v) { os << "{"; for (typename vector<T>::const_iterator vi = v.begin(); vi != v.end(); ++vi) { if (vi != v.begin()) os << ", "; os << *vi; } os << "}"; return os; }
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { os << '(' << p.first << ", " << p.second << ')'; return os; }

void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }

#ifdef NEAL
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif


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

    inline bool isspace(char c) {
        return (unsigned char) (c - '\t') < 5 || c == ' ';
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

    inline void read_char(char &c) {
        while (isspace(next_char(false)))
            next_char();

        c = next_char();
    }

    inline void read_str(string &str) {
        while (isspace(next_char(false)))
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

template<typename T1, typename T2>
bool compare_first(const pair<T1, T2> &x, const pair<T1, T2> &y) {
    return x.first < y.first;
}

const int MAX = 1e6 + 5;

int N, K;
vector<pair<char, int>> nodes[MAX];

int dp[MAX];

vector<int> S;
bool in_S[MAX];

int minimums[MAX];
int offset;

void dfs(int node, int parent, int depth) {
    dp[node] = parent < 0 ? 0 : dp[parent] + 1;
    int offset_before = offset;

    if (in_S[node]) {
        offset++;
        dp[node] = min(dp[node], minimums[depth - 1] + offset);
    }

    minimums[depth] = dp[node] - offset_before;

    if (depth > 0)
        minimums[depth] = min(minimums[depth], minimums[depth - 1]);

    for (auto &pr : nodes[node]) {
        int child = pr.second;
        dfs(child, node, depth + 1);
    }
}

int main() {
    IO::init();

    IO::read_int(N);

    for (int i = 1; i <= N; i++) {
        int p;
        char c;
        IO::read_int(p);
        IO::read_char(c);
        nodes[p].emplace_back(c, i);
    }

    for (int i = 0; i <= N; i++)
        sort(nodes[i].begin(), nodes[i].end(), compare_first<char, int>);

    IO::read_int(K);
    S.resize(K);

    for (int &s : S) {
        IO::read_int(s);
        in_S[s] = true;
    }

    offset = 0;
    dfs(0, -1, 0);

    for (int k = 0; k < K; k++)
        IO::write_int(dp[S[k]], k < K - 1 ? ' ' : '\n');
}
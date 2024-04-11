#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <chrono>
#include <cmath>
#include <cstring>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <vector>
using namespace std;

// http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2016/p0200r0.html
template<class Fun> class y_combinator_result {
    Fun fun_;
public:
    template<class T> explicit y_combinator_result(T &&fun): fun_(std::forward<T>(fun)) {}
    template<class ...Args> decltype(auto) operator()(Args &&...args) { return fun_(std::ref(*this), std::forward<Args>(args)...); }
};
template<class Fun> decltype(auto) y_combinator(Fun &&fun) { return y_combinator_result<std::decay_t<Fun>>(std::forward<Fun>(fun)); }


template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }

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
        // Ensures that _flush_output() is called at the end of the program.
        bool exit_success = atexit(_flush_output) == 0;
        assert(exit_success);

        for (int i = 0; i < 100; i++)
            lookup[i] = uint8_t((i / 10 << 4) + i % 10);
    }
}

template<typename T_vector>
void output_vector(const T_vector &v, bool add_one = false, int start = -1, int end = -1) {
    if (start < 0) start = 0;
    if (end < 0) end = int(v.size());

    for (int i = start; i < end; i++)
        IO::write_int(v[i] + (add_one ? 1 : 0), i < end - 1 ? ' ' : '\n');
}


struct query {
    int v, l, k, index;
};

void run_case() {
    int N, Q;
    IO::read_int(N, Q);
    vector<int> A(N);

    for (auto &a : A)
        IO::read_int(a);

    vector<vector<int>> children(N);

    for (int i = 1; i < N; i++) {
        int p;
        IO::read_int(p);
        p--;
        children[p].push_back(i);
    }

    vector<vector<query>> queries(N);

    for (int q = 0; q < Q; q++) {
        query qry;
        IO::read_int(qry.v, qry.l, qry.k);
        qry.v--; qry.k--;
        qry.index = q;
        queries[qry.v].push_back(qry);
    }

    vector<int> answers(Q, -1);
    vector<int> freq(N + 1, 0);
    vector<vector<int>> freq_list(N + 1);
    vector<int> freq_less_than(N + 2, N);
    freq_less_than[0] = 0;
    vector<int> inv_freq_less_than(N + 1, 0);
    inv_freq_less_than[N] = N + 1;

    auto find_any = [&](int cnt) -> int {
        while (freq[freq_list[cnt].back()] != cnt)
            freq_list[cnt].pop_back();

        return freq_list[cnt].back();
    };

    y_combinator([&](auto dfs, int node) -> void {
        int a = A[node];
        freq[a]++;
        freq_less_than[freq[a]]--;
        inv_freq_less_than[freq_less_than[freq[a]]]++;
        freq_list[freq[a]].push_back(a);

        for (query &qry : queries[node]) {
            int want = freq_less_than[qry.l] + qry.k;
            answers[qry.index] = want >= freq_less_than[N + 1] ? -1 : find_any(inv_freq_less_than[want]);
        }

        for (int child : children[node])
            dfs(child);

        inv_freq_less_than[freq_less_than[freq[a]]]--;
        freq_less_than[freq[a]]++;
        freq[a]--;
        freq_list[freq[a]].push_back(a);
    })(0);

    output_vector(answers);
}

int main() {
    IO::init();
    int tests;
    IO::read_int(tests);

    while (tests-- > 0)
        run_case();
}
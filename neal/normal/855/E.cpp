#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math,inline")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,lzcnt,mmx,abm,avx,avx2,fma")

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

int highest_bit(unsigned x) {
    return x == 0 ? -1 : 31 - __builtin_clz(x);
}


const int B_MAX = 10;
const int64_t R_MAX = int64_t(1e18) + 5;
const int DIGITS_MAX = 64 - __builtin_clzll(R_MAX);

vector<int> get_digits(int b, int64_t n) {
    vector<int> digits;

    if ((b & (b - 1)) == 0) {
        int bits = highest_bit(b);

        do {
            digits.push_back(n & (b - 1));
            n >>= bits;
        } while (n > 0);
    } else {
        do {
            digits.push_back(int(n % b));
            n /= b;
        } while (n > 0);
    }

    reverse(digits.begin(), digits.end());
    return digits;
}

int64_t dp[B_MAX + 1][DIGITS_MAX + 1][B_MAX + 1];

void precompute() {
    for (int b = 2; b <= B_MAX; b++) {
        int digits = int(get_digits(b, R_MAX).size());
        dp[b][0][0] = 1;

        for (int d = 1; d <= digits; d++)
            for (int odd = 0; odd <= b; odd++) {
                if (odd > 0) dp[b][d][odd] += odd * dp[b][d - 1][odd - 1];
                if (odd < b) dp[b][d][odd] += (b - odd) * dp[b][d - 1][odd + 1];
            }
    }
}

int64_t solve(int b, int64_t n) {
    vector<int> digits = get_digits(b, n);
    int D = int(digits.size());
    int64_t mask = 0, total = (digits[0] - 1) * dp[b][D - 1][1];

    for (int match = 1; match < D; match++) {
        mask ^= 1LL << digits[match - 1];
        int digit = digits[match];
        int mask_count = __builtin_popcountll(mask);
        int on_bits = __builtin_popcountll(mask & ((1LL << digit) - 1));
        if (mask_count > 0) total += on_bits * dp[b][D - 1 - match][mask_count - 1];
        if (mask_count < b) total += (digit - on_bits) * dp[b][D - 1 - match][mask_count + 1];
    }

    for (int length = D - 1; length > 0; length--)
        total += (b - 1) * dp[b][length - 1][1];

    return total;
}

int main() {
    IO::init();

    precompute();
    int Q;
    IO::read_int(Q);

    for (int q = 0; q < Q; q++) {
        int B;
        int64_t L, R;
        IO::read_int(B, L, R);
        R++;
        IO::write_int(solve(B, R) - solve(B, L), '\n');
    }
}
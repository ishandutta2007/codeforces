#include <algorithm>
#include <cassert>
#include <cstring>
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
 
const int MOD = 998244353;
 
struct mod_int {
    int val;
 
    mod_int(long long v = 0) {
        if (v < 0)
            v = v % MOD + MOD;
 
        if (v >= MOD)
            v %= MOD;
 
        val = v;
    }
 
    static int mod_inv(int a, int m = MOD) {
        // https://en.wikipedia.org/wiki/Extended_Euclidean_algorithm#Example
        int g = m, r = a, x = 0, y = 1;
 
        while (r != 0) {
            int q = g / r;
            g %= r; swap(g, r);
            x -= q * y; swap(x, y);
        }
 
        return x < 0 ? x + m : x;
    }
 
    explicit operator int() const {
        return val;
    }
 
    mod_int& operator+=(const mod_int &other) {
        val += other.val;
        if (val >= MOD) val -= MOD;
        return *this;
    }
 
    mod_int& operator-=(const mod_int &other) {
        val -= other.val;
        if (val < 0) val += MOD;
        return *this;
    }
 
    static unsigned fast_mod(uint64_t x, unsigned m = MOD) {
    #if !defined(_WIN32) || defined(_WIN64)
        return x % m;
    #endif
        // Optimized mod for Codeforces 32-bit machines.
        // x must be less than 2^32 * m for this to work, so that x / m fits in a 32-bit integer.
        unsigned x_high = x >> 32, x_low = (unsigned) x;
        unsigned quot, rem;
        asm("divl %4\n"
            : "=a" (quot), "=d" (rem)
            : "d" (x_high), "a" (x_low), "r" (m));
        return rem;
    }
 
    mod_int& operator*=(const mod_int &other) {
        val = fast_mod((uint64_t) val * other.val);
        return *this;
    }
 
    mod_int& operator/=(const mod_int &other) {
        return *this *= other.inv();
    }
 
    friend mod_int operator+(const mod_int &a, const mod_int &b) {
        return mod_int(a) += b;
    }
 
    friend mod_int operator-(const mod_int &a, const mod_int &b) {
        return mod_int(a) -= b;
    }
 
    friend mod_int operator*(const mod_int &a, const mod_int &b) {
        return mod_int(a) *= b;
    }
 
    friend mod_int operator/(const mod_int &a, const mod_int &b) {
        return mod_int(a) /= b;
    }
 
    mod_int& operator++() {
        val = val == MOD - 1 ? 0 : val + 1;
        return *this;
    }
 
    mod_int operator++(int) {
        mod_int before = *this;
        ++*this;
        return before;
    }
 
    mod_int& operator--() {
        val = val == 0 ? MOD - 1 : val - 1;
        return *this;
    }
 
    mod_int operator--(int) {
        mod_int before = *this;
        --*this;
        return before;
    }
 
    mod_int operator-() const {
        return val == 0 ? 0 : MOD - val;
    }
 
    bool operator==(const mod_int &other) const {
        return val == other.val;
    }
 
    bool operator!=(const mod_int &other) const {
        return val != other.val;
    }
 
    mod_int inv() const {
        return mod_inv(val);
    }
 
    mod_int pow(long long p) const {
        assert(p >= 0);
        mod_int a = *this, result = 1;
 
        while (p > 0) {
            if (p & 1)
                result *= a;
 
            a *= a;
            p >>= 1;
        }
 
        return result;
    }
};
 
 
const int M_MAX = 1005;
const int INF = 1e9 + 5;
 
int N, M;
vector<int> C;
vector<int> color_start, color_end;
mod_int dp[M_MAX][M_MAX];
 
mod_int solve(int start, int end) {
    if (end - start <= 0)
        return 1;
 
    mod_int &answer = dp[start][end];
 
    if (answer.val >= 0)
        return answer;
 
    int color = *min_element(C.begin() + start, C.begin() + end);
 
    if (color_start[color] < start || color_end[color] > end)
        return answer = 0;
 
    if (end - start <= 1)
        return answer = 1;
 
    answer = 0;
 
    mod_int product = 1;
    int previous = color_start[color];
 
    for (int i = color_start[color] + 1; i < color_end[color]; i++)
        if (C[i] == color) {
            product *= solve(previous + 1, i);
            previous = i;
        }
 
    mod_int left = 0, right = 0;
 
    for (int i = start; i <= color_start[color]; i++)
        left += solve(start, i) * solve(i, color_start[color]);
 
    for (int i = color_end[color]; i <= end; i++)
        right += solve(color_end[color], i) * solve(i, end);
 
    return answer = product * left * right;
}
 
int main() {
    IO::read_int(N, M);
    C.resize(M);
 
    for (int &c : C)
        IO::read_int(c);
 
    C.resize(unique(C.begin(), C.end()) - C.begin());
    M = C.size();
 
    if (M > 2 * N + 1) {
        cout << 0 << '\n';
        return 0;
    }
 
    color_start.assign(N + 1, INF);
    color_end.assign(N + 1, -INF);
 
    for (int i = 0; i < M; i++) {
        color_start[C[i]] = min(color_start[C[i]], i);
        color_end[C[i]] = max(color_end[C[i]], i + 1);
    }
 
    // bool valid = true;
 
    // for (int color = 1; color <= N; color++)
    //     for (int i = color_start[color]; i < color_end[color]; i++)
    //         if (C[i] < color)
    //             valid = false;
 
    // if (!valid) {
    //     cout << 0 << '\n';
    //     return 0;
    // }
 
    memset(dp, -1, sizeof(dp));
    cout << (int) solve(0, M) << '\n';
}
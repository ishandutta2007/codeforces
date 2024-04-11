#include <algorithm>
#include <cassert>
#include <chrono>
#include <climits>
#include <iostream>
#include <random>
#include <vector>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;

auto random_address = [] { char *p = new char; delete p; return (uint64_t) p; };

struct safe_hash32 {
    static unsigned hash32(unsigned x) {
        x = (x ^ (x >> 16)) * 0x45d9f3b;
        x = (x ^ (x >> 16)) * 0x45d9f3b;
        return x ^ (x >> 16);
    }

    unsigned operator()(unsigned x) const {
        static const unsigned FIXED_RANDOM = hash32(chrono::steady_clock::now().time_since_epoch().count() * (random_address() | 1));
        return hash32(x ^ FIXED_RANDOM);
    }
};

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

const int MOD = 1e9 + 7;

struct mod_int {
    int val;

    mod_int(long long v = 0) {
        if (v < 0) v = v % MOD + MOD;
        if (v >= MOD) v %= MOD;
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

    friend mod_int operator+(const mod_int &a, const mod_int &b) { return mod_int(a) += b; }
    friend mod_int operator-(const mod_int &a, const mod_int &b) { return mod_int(a) -= b; }
    friend mod_int operator*(const mod_int &a, const mod_int &b) { return mod_int(a) *= b; }
    friend mod_int operator/(const mod_int &a, const mod_int &b) { return mod_int(a) /= b; }

    mod_int& operator++() {
        val = val == MOD - 1 ? 0 : val + 1;
        return *this;
    }

    mod_int& operator--() {
        val = val == 0 ? MOD - 1 : val - 1;
        return *this;
    }

    mod_int operator++(int) { mod_int before = *this; ++*this; return before; }
    mod_int operator--(int) { mod_int before = *this; --*this; return before; }

    mod_int operator-() const {
        return val == 0 ? 0 : MOD - val;
    }

    bool operator==(const mod_int &other) const { return val == other.val; }
    bool operator!=(const mod_int &other) const { return val != other.val; }

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

    friend ostream& operator<<(ostream &stream, const mod_int &m) {
        return stream << m.val;
    }
};

const int W_MAX = 32;

struct edge {
    int node, weight;

    bool operator<(const edge &other) const {
        return node < other.node;
    }
};

int N, M;
vector<vector<edge>> adj;
vector<int> weight0;

inline unsigned combine_one(unsigned mask, int index) {
    unsigned combined = mask | 1U << index;
    if (index >> 4 & 1) mask = ((mask & 0xFFFF0000) >> 16) | ((mask & 0x0000FFFF) << 16);
    if (index >> 3 & 1) mask = ((mask & 0xFF00FF00) >>  8) | ((mask & 0x00FF00FF) <<  8);
    if (index >> 2 & 1) mask = ((mask & 0xF0F0F0F0) >>  4) | ((mask & 0x0F0F0F0F) <<  4);
    if (index >> 1 & 1) mask = ((mask & 0xCCCCCCCC) >>  2) | ((mask & 0x33333333) <<  2);
    if (index >> 0 & 1) mask = ((mask & 0xAAAAAAAA) >>  1) | ((mask & 0x55555555) <<  1);
    combined |= mask;
    return combined;

    // unsigned combined = mask | 1U << index;

    // for (int i = 0; i < W_MAX; i++)
    //     combined |= (unsigned) (mask >> i & 1) << (i ^ index);

    // return combined;
}

unsigned combine(unsigned a, unsigned b) {
    if (max(a, b) == UINT_MAX)
        return UINT_MAX;

    unsigned combined = a | b;

    for (int i = 0; i < W_MAX; i++)
        if (b >> i & 1)
            combined |= combine_one(a, i);

    return combined;
}

const int K = 374;

int id = 0;
gp_hash_table<unsigned, int, safe_hash32> mask_to_id;
unsigned masks[K + 1];
int transition[K + 1][K + 1];

int get_or_create_mask_id(unsigned mask) {
    if ((mask & 1) != 0)
        return K;

    if (mask_to_id.find(mask) != mask_to_id.end())
        return mask_to_id[mask];

    masks[id] = mask;
    mask_to_id[mask] = id;
    return id++;
}

void precompute_masks() {
    masks[K] = UINT_MAX;
    id = 0;
    get_or_create_mask_id(0);

    for (int i = 0; i < W_MAX; i++)
        get_or_create_mask_id(1U << i);

    for (int i = 0; i <= K; i++)
        for (int j = 0; j <= i; j++)
            transition[i][j] = transition[j][i] = get_or_create_mask_id(combine(masks[i], masks[j]));

    cerr << "K = " << K << endl;
}

void print(int mask_id) {
    unsigned mask = masks[mask_id];
    cerr << "( ";

    for (int i = 0; i < W_MAX; i++)
        if (mask >> i & 1)
            cerr << i << ' ';

    cerr << ") ";
}

unsigned reach;
vector<int> path;

void dfs(int node, int parent, int current_path) {
    if (path[node] >= 0)
        return;

    path[node] = current_path;

    for (edge &e : adj[node])
        if (e.node != parent) {
            if (path[e.node] >= 0) {
                // An already seen node creates a cycle.
                int cycle = current_path ^ path[e.node] ^ e.weight;

                // Only combine once for the same edge.
                if (node < e.node)
                    reach = combine_one(reach, cycle);
            } else {
                dfs(e.node, node, current_path ^ e.weight);
            }
        }
}

int main() {
    IO::init();
    precompute_masks();

    IO::read_int(N, M);
    adj.assign(N, {});
    weight0.assign(N, -1);

    for (int i = 0; i < M; i++) {
        int a, b, w;
        IO::read_int(a, b, w);
        a--; b--;

        if (a == 0 || b == 0) {
            weight0[max(a, b)] = w;
        } else {
            adj[a].push_back({b, w});
            adj[b].push_back({a, w});
        }
    }

    path.assign(N, -1);
    vector<mod_int> dp(K + 1, 0);
    dp[0] = 1;

    for (int x = 1; x < N; x++)
        for (edge &e : adj[x]) {
            int y = e.node;

            if (x < y && weight0[x] >= 0 && weight0[y] >= 0) {
                int cycle = weight0[x] ^ weight0[y] ^ e.weight;
                reach = 0;
                dfs(x, -1, 0);
                int single = get_or_create_mask_id(reach);
                int both = get_or_create_mask_id(combine_one(reach, cycle));
                vector<mod_int> next_dp = dp;

                for (int k = 0; k < K; k++) {
                    next_dp[transition[single][k]] += dp[k] + dp[k];
                    next_dp[transition[both][k]] += dp[k];
                }

                dp = next_dp;
            }
        }

    for (int x = 1; x < N; x++)
        if (weight0[x] >= 0 && path[x] < 0) {
            reach = 0;
            dfs(x, -1, 0);
            int single = get_or_create_mask_id(reach);
            vector<mod_int> next_dp = dp;

            for (int k = 0; k < K; k++)
                next_dp[transition[single][k]] += dp[k];

            dp = next_dp;
        }

    mod_int total = 0;

    for (int option = 0; option < K; option++)
        total += dp[option];

    cout << total << '\n';
}
#include <algorithm>
#include <array>
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

struct identity {
    template<typename T>
    T operator()(const T &x) const {
        return x;
    }
};

// A stable sort that sorts in passes of `bits_per_pass` bits at a time.
template<typename T, typename T_extract_key = identity>
void radix_sort(vector<T> &data, int bits_per_pass = 10, const T_extract_key &extract_key = identity()) {
    if (data.size() < 256) {
        stable_sort(data.begin(), data.end(), [&](const T &a, const T &b) {
            return extract_key(a) < extract_key(b);
        });
        return;
    }

    using T_key = decltype(extract_key(data.front()));
    T_key minimum = numeric_limits<T_key>::max();

    for (T &x : data)
        minimum = min(minimum, extract_key(x));

    int max_bits = 0;

    for (T &x : data) {
        T_key key = extract_key(x);
        max_bits = max(max_bits, key == minimum ? 0 : 64 - __builtin_clzll(key - minimum));
    }

    int passes = max((max_bits + bits_per_pass / 2) / bits_per_pass, 1);

    if (64 - __builtin_clzll(data.size()) <= 1.5 * passes) {
        stable_sort(data.begin(), data.end(), [&](const T &a, const T &b) {
            return extract_key(a) < extract_key(b);
        });
        return;
    }

    vector<T> buffer(data.size());
    vector<int> counts;
    int bits_so_far = 0;

    for (int p = 0; p < passes; p++) {
        int bits = (max_bits + p) / passes;
        counts.assign(1 << bits, 0);

        for (T &x : data) {
            T_key key = T_key(extract_key(x) - minimum);
            counts[(key >> bits_so_far) & ((1 << bits) - 1)]++;
        }

        int count_sum = 0;

        for (int &count : counts) {
            int current = count;
            count = count_sum;
            count_sum += current;
        }

        for (T &x : data) {
            T_key key = T_key(extract_key(x) - minimum);
            int key_section = int((key >> bits_so_far) & ((1 << bits) - 1));
            buffer[counts[key_section]++] = x;
        }

        swap(data, buffer);
        bits_so_far += bits;
    }
}

template<typename T_array>
int compute_mex(const T_array &values) {
    int n = int(values.size());
    vector<bool> seen(n + 1, false);

    for (const auto &x : values)
        if (x <= n)
            seen[x] = true;

    int mex = 0;

    while (seen[mex])
        mex++;

    return mex;
}


const int C = 4;
const int INF = int(1e9) + 5;

int main() {
    array<int, C> N;
    array<vector<int>, C> cost;

    for (int c = 0; c < C; c++)
        IO::read_int(N[c]);

    for (int c = 0; c < C; c++) {
        cost[c].resize(N[c]);

        for (auto &cs : cost[c])
            IO::read_int(cs);
    }

    for (int c = 1; c < C; c++) {
        int m;
        IO::read_int(m);
        vector<array<int, 2>> edges(m);
        vector<int> degree(N[c], 0);

        for (int i = 0; i < m; i++) {
            int x, y;
            IO::read_int(x, y);
            x--; y--;
            edges[i] = {x, y};
            degree[y]++;
        }

        vector<vector<int>> bad(N[c]);

        for (int y = 0; y < N[c]; y++)
            bad[y].reserve(degree[y]);

        for (int i = 0; i < m; i++)
            bad[edges[i][1]].push_back(edges[i][0]);

        int n = N[c - 1];
        vector<int> sorted(n);
        iota(sorted.begin(), sorted.end(), 0);
        radix_sort(sorted, 10, [&](int x) { return cost[c - 1][x]; });
        vector<int> where(n);

        for (int i = 0; i < n; i++)
            where[sorted[i]] = i;

        for (int y = 0; y < N[c]; y++) {
            for (auto &x : bad[y])
                x = where[x];

            int mex = compute_mex(bad[y]);
            int add = mex < n ? cost[c - 1][sorted[mex]] : INF;
            cost[c][y] += add;
        }
    }

    int ans = *min_element(cost.back().begin(), cost.back().end());
    cout << (ans < INF ? ans : -1) << '\n';
}
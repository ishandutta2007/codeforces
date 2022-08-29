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


template<typename T>
struct fenwick_tree {
    int tree_n = 0;
    vector<T> tree;

    fenwick_tree(int n = 0) {
        if (n > 0)
            init(n);
    }

    void init(int n) {
        tree_n = n;
        tree.assign(tree_n + 1, 0);
    }

    void reset() {
        memset(&tree[0], 0, tree.size() * sizeof(T));
    }

    // O(n) initialization of the Fenwick tree.
    void build(const auto &initial) {
        assert((int) initial.size() == tree_n);

        for (int i = 1; i <= tree_n; i++) {
            tree[i] = initial[i - 1];

            for (int k = (i & -i) >> 1; k > 0; k >>= 1)
                tree[i] += tree[i - k];
        }
    }

    // index is in [0, tree_n).
    void update(int index, const T &change) {
        assert(0 <= index && index < tree_n);

        for (int i = index + 1; i <= tree_n; i += i & -i)
            tree[i] += change;
    }

    // Returns the sum of the range [0, count).
    T query(int count) const {
        assert(count <= tree_n);
        T sum = 0;

        for (int i = count; i > 0; i -= i & -i)
            sum += tree[i];

        return sum;
    }

    // Returns the sum of the range [a, b).
    T query(int a, int b) const {
        return query(b) - query(a);
    }

    // Returns the element at index a in O(1) amortized across every index.
    T get(int a) const {
        assert(0 <= a && a < tree_n);
        int above = a + 1;
        T sum = tree[above];
        above -= above & -above;

        while (a != above) {
            sum -= tree[a];
            a -= a & -a;
        }

        return sum;
    }

    // Returns the last i in [0, N] such that tree_query(i) <= sum, or -1 if no such i exists.
    int find_last_prefix(T sum) const {
        if (sum < 0)
            return -1;

        int prefix = 0;

        for (int k = 31 - __builtin_clz(tree_n); k >= 0; k--)
            if (prefix + (1 << k) <= tree_n && tree[prefix + (1 << k)] <= sum) {
                prefix += 1 << k;
                sum -= tree[prefix];
            }

        return prefix;
    }
};


const int MOD = 998244353;

// dp[n][k] = number of ways to arrange a row of n elements where k of the items have a match to avoid above.
vector<vector<int>> dp;

void precompute_dp(int N) {
    dp.resize(N + 1);
    dp[0] = {1};

    for (int n = 1; n <= N; n++) {
        dp[n].resize(n + 1);
        dp[n][0] = (long long) n * dp[n - 1][0] % MOD;

        for (int k = 1; k <= n; k++) {
            long long value = (long long) (n - k) * dp[n - 1][k - 1];

            if (k > 1)
                value += (long long) (k - 1) * (dp[n - 2][k - 2] + dp[n - 1][k - 1]);

            dp[n][k] = value % MOD;
        }
    }
}

int main() {
    int N;
    IO::read_int(N);
    precompute_dp(N);
    vector<int> row(N, 0), prev_row(N, 0);
    vector<long long> remaining_powers(N + 1, 1);

    for (int i = 1; i <= N; i++)
        remaining_powers[i] = remaining_powers[i - 1] * dp[N][N] % MOD;

    vector<bool> seen, prev_seen;
    fenwick_tree<int16_t> common_tree(N + 1), row_tree(N + 1);
    long long total = 0;

    for (int r = 0; r < N; r++) {
        long long remaining_rows = remaining_powers[N - 1 - r];

        for (int i = 0; i < N; i++)
            IO::read_int(row[i]);

        seen.assign(N + 1, false);
        prev_seen.assign(N + 1, false);
        common_tree.reset();
        row_tree.reset();
        int common = 0;

        for (int i = N - 1; i >= 0; i--) {
            seen[row[i]] = true;

            if (prev_seen[row[i]]) {
                common++;
                common_tree.update(row[i], +1);
            } else {
                row_tree.update(row[i], +1);
            }

            int row_count = row_tree.query(row[i]);
            int common_count = common_tree.query(row[i]);

            if (prev_row[i] < row[i] && seen[prev_row[i]])
                row_count--;

            total += row_count * (dp[N - 1 - i][common] * remaining_rows % MOD);
            if (common > 0) total += common_count * (dp[N - 1 - i][common - 1] * remaining_rows % MOD);

            prev_seen[prev_row[i]] = true;

            if (seen[prev_row[i]]) {
                common++;
                row_tree.update(prev_row[i], -1);
                common_tree.update(prev_row[i], +1);
            }
        }

        total %= MOD;
        prev_row = row;
    }

    printf("%lld\n", total);
}
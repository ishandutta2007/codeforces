#include <algorithm>
#include <cassert>
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

const int INF = 1e9 + 5;

template<typename T, bool maximum_mode, T T_INF>
struct monotonic_RMQ {
    vector<pair<T, int>> values;
    int front = 0, current_index = 0;

    int size() const {
        return (int) values.size() - front;
    }

    static bool is_better(T a, T b) {
        return maximum_mode ? b < a : a < b;
    }

    int prev_add_index = -INF, prev_query_index = -INF;

    // Adds a value and returns its index.
    int add(const T &x, int index = -INF) {
        if (index == -INF)
            index = current_index++;

        assert(index >= prev_add_index);
        prev_add_index = index;

        while (size() > 0 && !is_better(values.back().first, x))
            values.pop_back();

        values.emplace_back(x, index);
        return index;
    }

    // Queries for the maximum (minimum) with index at least the given `index`. `index` must be non-decreasing.
    T query_index(int index) {
        assert(index >= prev_query_index);
        prev_query_index = index;

        while (size() > 0 && values[front].second < index)
            front++;

        if (size() == 0)
            return maximum_mode ? (is_signed<T>::value ? -T_INF : 0) : T_INF;

        return values[front].first;
    }

    // Warning: does not work when adding with custom indices.
    T query_count(int count) {
        return query_index(current_index - count);
    }

    // Returns whether or not the queue has a result for querying the given index.
    bool has_index(int index) const {
        return !values.empty() && values.back().second >= index;
    }

    bool has_count(int count) const {
        return has_index(current_index - count);
    }
};


int N, M, K;

vector<int> transition(vector<int> dp, vector<int> row, vector<int> next_row, bool first = false) {
    vector<int> partial_sums(M + 1, 0);
    vector<int> next_sums(M + 1, 0);

    for (int i = 0; i < M; i++) {
        partial_sums[i + 1] = partial_sums[i] + row[i];
        next_sums[i + 1] = next_sums[i] + next_row[i];
    }

    auto &&get_both_sum = [&](int start, int end) {
        return partial_sums[end] - partial_sums[start] + next_sums[end] - next_sums[start];
    };

    if (first) {
        for (int i = 0; i <= M - K; i++)
            dp[i] = get_both_sum(i, i + K);

        return dp;
    }

    vector<int> next_dp(M - K + 1, -INF);
    monotonic_RMQ<int, true, INF> rmq;
    int fixed = -INF;
    int bump = 0;

    for (int i = 0; i <= M - K; i++) {
        if (i >= K)
            fixed = max(fixed, dp[i - K]);

        next_dp[i] = max(next_dp[i], get_both_sum(i, i + K) + fixed);
        rmq.add(dp[i] - (partial_sums[i + K] - partial_sums[i]) - bump);
        next_dp[i] = max(next_dp[i], get_both_sum(i, i + K) + rmq.query_count(K) + bump);
        bump += row[i];
    }

    return next_dp;
}

int main() {
    IO::read_int(N, M, K);
    vector<vector<int>> A(N, vector<int>(M));

    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            IO::read_int(A[i][j]);

    A.push_back(vector<int>(M, 0));

    vector<int> dp(M - K + 1, 0);
    dp = transition(dp, A[0], A[1], true);

    for (int i = 1; i < N; i++) {
        vector<int> next_dp = transition(dp, A[i], A[i + 1]);
        reverse(dp.begin(), dp.end());
        reverse(A[i].begin(), A[i].end());
        reverse(A[i + 1].begin(), A[i + 1].end());
        vector<int> reverse_next_dp = transition(dp, A[i], A[i + 1]);
        reverse(A[i].begin(), A[i].end());
        reverse(A[i + 1].begin(), A[i + 1].end());
        reverse(reverse_next_dp.begin(), reverse_next_dp.end());

        for (int index = 0; index <= M - K; index++)
            dp[index] = max(next_dp[index], reverse_next_dp[index]);
    }

    cout << *max_element(dp.begin(), dp.end()) << '\n';
}
#include <algorithm>
#include <cassert>
#include <iostream>
#include <string>
#include <vector>
using namespace std;


template<typename T>
struct RMQ {
    int n = 0, levels = 0;
    vector<vector<T>> range_min;

    RMQ(const vector<T> &values = {}) {
        if (!values.empty())
            build(values);
    }

    static int largest_bit(int x) {
        return 31 - __builtin_clz(x);
    }

    void build(const vector<T> &values) {
        n = values.size();
        levels = largest_bit(n) + 1;
        range_min.resize(levels);

        for (int k = 0; k < levels; k++)
            range_min[k].resize(n - (1 << k) + 1);

        for (int i = 0; i < n; i++)
            range_min[0][i] = values[i];

        for (int k = 1; k < levels; k++)
            for (int i = 0; i <= n - (1 << k); i++)
                range_min[k][i] = min(range_min[k - 1][i], range_min[k - 1][i + (1 << (k - 1))]);
    }

    T query(int a, int b) const {
        assert(a < b);
        int level = largest_bit(b - a);
        return min(range_min[level][a], range_min[level][b - (1 << level)]);
    }
};


struct suffix_array {
    int n = 0;
    vector<int> suffix;
    vector<int> rank;
    vector<int> lcp;
    RMQ<int> rmq;

    suffix_array() {}

    template<typename T_string>
    suffix_array(const T_string &str, bool build_rmq = true) {
        build(str, build_rmq);
    }

    template<typename T_string>
    void build(const T_string &str, bool build_rmq = true) {
        n = str.size();
        suffix.resize(n);

        for (int i = 0; i < n; i++)
            suffix[i] = i;

        bool large_alphabet = false;

        for (int i = 0; i < n; i++)
            if (str[i] < 0 || str[i] >= 128)
                large_alphabet = true;

        // Sort each suffix by the first character.
        if (large_alphabet) {
            sort(suffix.begin(), suffix.end(), [&](int a, int b) {
                return str[a] < str[b];
            });
        } else {
            vector<int> freq(128, 0);

            for (int i = 0; i < n; i++)
                freq[str[i]]++;

            for (int c = 1; c < 128; c++)
                freq[c] += freq[c - 1];

            for (int i = 0; i < n; i++)
                suffix[--freq[str[i]]] = i;
        }

        // Compute the rank of each suffix. Tied suffixes share the same rank.
        rank.resize(n);
        rank[suffix[0]] = 0;

        for (int i = 1; i < n; i++)
            rank[suffix[i]] = str[suffix[i]] == str[suffix[i - 1]] ? rank[suffix[i - 1]] : i;

        vector<int> next_index(n);
        vector<int> values(n);
        bool done = false;

        for (int len = 1; len < n && !done; len *= 2) {
            // next_index[i] = the next index to use for a suffix of rank i. We insert them in order of the rank of the
            // suffix that comes len characters after the current suffix.
            for (int i = 0; i < n; i++)
                next_index[i] = i;

            // Compute the suffix array for 2 * len. Suffixes of length <= len are prioritized first.
            for (int i = n - len; i < n; i++)
                values[next_index[rank[i]]++] = i;

            for (int i = 0; i < n; i++) {
                int prev = suffix[i] - len;

                if (prev >= 0)
                    values[next_index[rank[prev]]++] = prev;
            }

            swap(suffix, values);

            // Compute the rank array for 2 * len.
            values[suffix[0]] = 0;
            done = true;

            for (int i = 1; i < n; i++) {
                int s = suffix[i], prev = suffix[i - 1];

                if (s + len < n && prev + len < n && rank[s] == rank[prev] && rank[s + len] == rank[prev + len]) {
                    values[s] = values[prev];
                    done = false;
                } else {
                    values[s] = i;
                }
            }

            swap(rank, values);
        }

        compute_lcp(str);

        if (build_rmq)
            rmq.build(lcp);
    }

    template<typename T_string>
    void compute_lcp(const T_string &str) {
        lcp.assign(n, 0);
        int match = 0;

        for (int i = 0; i < n; i++) {
            if (rank[i] == 0)
                continue;

            int a = suffix[rank[i]] + match;
            int b = suffix[rank[i] - 1] + match;

            while (a < n && b < n && str[a++] == str[b++])
                match++;

            lcp[rank[i]] = match;
            match = max(match - 1, 0);
        }
    }

    int get_lcp_from_ranks(int a, int b) const {
        if (a == b)
            return n - suffix[a];

        if (a > b)
            swap(a, b);

        return rmq.query(a + 1, b + 1);
    }

    int get_lcp(int a, int b) const {
        if (a == b)
            return n - a;

        if (a >= n || b >= n)
            return 0;

        return get_lcp_from_ranks(rank[a], rank[b]);
    }
};

const int INF = 1e9 + 5;

int N, A, B;
string S;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> A >> B >> S;
    suffix_array SA(S);
    vector<int> dp(N + 1, INF);
    dp[0] = 0;

    for (int i = 0; i < N; i++) {
        dp[i + 1] = min(dp[i + 1], dp[i] + A);
        int most = 0;

        for (int j = 0; j < i; j++)
            most = max(most, min(SA.get_lcp(j, i), i - j));

        for (int j = i + 1; j <= N && j <= i + most; j++)
            dp[j] = min(dp[j], dp[i] + B);
    }

    cout << dp[N] << '\n';
}